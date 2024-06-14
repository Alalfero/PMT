package hsrm.pmt;

import java.security.spec.ECField;
import java.util.concurrent.*;
import java.util.function.BiFunction;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Supplier;

public class MyCompletableFuture<T> implements Future<T> {

    private static ExecutorService executorService = Executors.newCachedThreadPool();

    public static void setExecutorService(ExecutorService executorService) {
        MyCompletableFuture.executorService = executorService;
    }

    private final Object lockObject = new Object();
    private T result;
    private Exception exception;
    private boolean isCompleted;

    private Consumer<MyCompletableFuture<T>> continuation;

    @Override
    public boolean cancel(boolean mayInterruptIfRunning) {
        return setException(new CancellationException());
    }

    @Override
    public boolean isCancelled() {
        return isCompleted && exception instanceof CancellationException;
    }

    @Override
    public boolean isDone() {
        return isCompleted;
    }

    private void addContinuation(Consumer<MyCompletableFuture<T>> continuation) {
        synchronized (lockObject) {
            if (isCompleted) {
                continuation.accept(this);
                return;
            }
            if (this.continuation == null) {
                this.continuation = continuation;
            } else {
                this.continuation = this.continuation.andThen(continuation);
            }
        }
    }

    @Override
    public T get() throws InterruptedException, ExecutionException {
        if (isCompleted) {
            return getCore();
        }

        var notifyObj = new Object();
        addContinuation(t -> {
            synchronized (notifyObj) {
                notifyObj.notify();
            }
        });
        synchronized (notifyObj) {
            notifyObj.wait();
        }
        return getCore();
    }

    private T getCore() throws ExecutionException {
        if (exception != null) {
            throw new ExecutionException(exception);
        }
        return result;
    }

    @Override
    public T get(long timeout, TimeUnit unit) throws InterruptedException, ExecutionException, TimeoutException {
        if (isCompleted) {
            return getCore();
        }

        var notifyObj = new Object();
        addContinuation(t -> {
            synchronized (notifyObj) {
                notifyObj.notify();
            }
        });
        synchronized (notifyObj) {
            notifyObj.wait(timeout);
            if (isCancelled()) return getCore();
            else throw new TimeoutException();
        }
    }

    public boolean setResult(T result) {
        synchronized (lockObject) {
            if (isCompleted) return false;
            this.result = result;
            isCompleted = true;
            if (continuation != null) {
                executorService.submit(() -> continuation.accept(this));
            }
            return true;
        }
    }

    public boolean setException(Exception exception) {
        synchronized (lockObject) {
            if (isCompleted) return false;
            this.exception = exception;
            isCompleted = true;
            if (continuation != null) {
                executorService.submit(() -> continuation.accept(this));
            }
            return true;
        }
    }

    public static <T> MyCompletableFuture<T> create(Supplier<T> supplier) {
        var result = new MyCompletableFuture<T>();
        executorService.submit(() -> {
            try {
                result.setResult(supplier.get());
            } catch(Exception ex) {
                result.setException(ex);
            }
        });
        return result;
    }

    public static <T> MyCompletableFuture<T> fromResult(T result) {
        var future = new MyCompletableFuture<T>();
        future.result = result;
        future.isCompleted = true;
        return future;
    }

    public static <T> MyCompletableFuture<T> fromException(Exception exception) {
        var future = new MyCompletableFuture<T>();
        future.exception = exception;
        future.isCompleted = true;
        return future;
    }

    public <U> MyCompletableFuture<U> thenApply(Function<T, U> mapping) {
        var result = new MyCompletableFuture<U>();
        addContinuation(t -> {
            if (t.exception != null) {
                result.setException(t.exception);
            } else {
                try {
                    var mapped = mapping.apply(t.result);
                    result.setResult(mapped);
                }
                catch (Exception e) {
                    result.setException(e);
                }
            }
        });
        return result;
    }

    public MyCompletableFuture<T> exceptionally(Function<Exception, T> handler) {
        var future = new MyCompletableFuture<T>();
        addContinuation(t -> {
            if (t.exception != null) {
                try {
                    future.setResult(handler.apply(t.exception));
                }
                catch (Exception e) {
                    future.setException(e);
                }
            }
            else future.setResult(t.result);
        });
        return future;
    }

    public <U> MyCompletableFuture<U> thenCompose(Function<T, MyCompletableFuture<U>> mapping) {
        var result = new MyCompletableFuture<U>();
        addContinuation(t -> {
            if (t.exception != null) {
                result.setException(t.exception);
            } else {
                try {
                    var mapped = mapping.apply(t.result);
                    mapped.addContinuation(t2 -> {
                        if (t2.exception != null) {
                            result.setException(t2.exception);
                        } else {
                            result.setResult(t2.result);
                        }
                    });
                }
                catch (Exception e) {
                    result.setException(e);
                }
            }
        });
        return result;
    }

    public <U> MyCompletableFuture<U> handle(BiFunction<T, Exception, U> handler) {
        var future = new MyCompletableFuture<U>();
        addContinuation(t -> {
            if (t.exception != null) {
                try {
                    future.setResult(handler.apply(null, t.exception));
                }
                catch (Exception e) {
                    future.setException(e);
                }
            }
            else {
                try {
                    future.setResult(handler.apply(t.result, null));
                }
                catch (Exception e) {
                    future.setException(e);
                }
            }
        });
        return future;
    }
}
