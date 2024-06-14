package hsrm.pmt.test;

import hsrm.pmt.MyCompletableFuture;
import org.junit.Test;

import java.io.IOException;
import java.util.ArrayList;
import java.util.concurrent.*;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;

public class MyCompletableFutureTest {

    @Test
    public void testThenApply() throws Exception {
        var future = MyCompletableFuture
                .create(() -> {
                    try {
                        Thread.sleep(100);
                    } catch(Exception e) {
                        throw new RuntimeException(e);
                    }
                    return 1;
                })
                .thenApply(i -> i+1);
        assertFalse(future.isDone());
        var result = future.get();
        assertEquals(2, (long)result);
    }

    @Test
    public void testGetRespectsTimeout() throws Exception {
        var future = MyCompletableFuture.create(() -> {
            try {
                Thread.sleep(1000000000);
            } catch (InterruptedException ex) {
                throw new RuntimeException(ex);
            }
            return 42;
        });
        assertThrows(TimeoutException.class, () -> future.get(10, TimeUnit.MILLISECONDS));
    }

    @Test
    public void testThenCompose() throws Exception {
        var future = MyCompletableFuture
                .create(() -> {
                    try {
                        Thread.sleep(100);
                    } catch(Exception e) {
                        throw new RuntimeException(e);
                    }
                    return 1;
                })
                .thenCompose(i -> MyCompletableFuture.fromResult(i+1));
        assertFalse(future.isDone());
        var result = future.get();
        assertEquals(2, (long)result);
    }

    @Test
    public void testFromException() throws Exception {
        var innerExc = new IOException();
        var exception = assertThrows(ExecutionException.class, () -> MyCompletableFuture.fromException(innerExc).get());
        assertEquals(innerExc, exception.getCause());
    }

    @Test
    public void testExceptionallyOnlyCalledWhenFaulted() throws Exception {
        var future = MyCompletableFuture.create(() -> { throw new RuntimeException(); })
                .exceptionally(exception -> 42).get();

        var future2 = MyCompletableFuture.create(() -> 23)
                .exceptionally(exception -> 42).get();

        assertEquals(42, (int)future);
        assertEquals(23, (int)future2);
    }

    @Test
    public void testHandle() throws Exception {
        var future = MyCompletableFuture.<Integer>create(() -> { throw new RuntimeException(); })
                .handle((i,e) -> e != null ? 42 : (i + 1)).get();

        var future2 = MyCompletableFuture.create(() -> 23)
                .handle((i,e) -> e != null ? 42 : (i + 1)).get();

        assertEquals(42, (long)future);
        assertEquals(24, (long)future2);
    }

    private <T extends Exception, U> T assertThrows(Class<T> exceptionClass, Callable<U> runnable) throws Exception {
        try {
            runnable.call();
        } catch (Exception ex) {
            if (ex.getClass() == exceptionClass) {
                return (T)ex;
            }
            throw ex;
        }
        throw new AssertionError("no exception thrown");
    }

}
