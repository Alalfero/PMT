package name.panitz.util;

import java.math.BigInteger;
import java.util.Arrays;
import java.util.Iterator;
import java.util.function.Function;
import java.util.function.Predicate;


public interface Iteratoren {


	class IntRange implements Iterable<Integer> {
		int from;
		int to;
		int step;
		boolean infinite;

		public IntRange(int from, int to, int step) {
			this.from = from;
			this.to = to;
			this.step = step;
			this.infinite = false;
		}

		public IntRange(int from, int to) {
			this(from, to, 1);
			this.infinite = false;
		}

		public IntRange(int from) {
			this.from = from;
			this.step = 1;
			this.infinite = true;
		}

		public IntRange() {
			this.from = 0;
			this.step = 1;
			this.infinite = true;
		}

		@Override
		public Iterator<Integer> iterator() {
			return new Iterator<Integer>() {
				int current = from;

				@Override
				public boolean hasNext() {
					if (infinite) return true;
					if (step == 0) return false;
					return step > 0 ? current <= to : current >= to;
				}

				@Override
				public Integer next() {
					int temp = current;
					current = current + step;
					return temp;
				}
			};
		}
	}


	class Fib implements Iterable<BigInteger> {
		@Override
		public Iterator<BigInteger> iterator() {
			return new Iterator<BigInteger>() {
				BigInteger current = BigInteger.ZERO;
				BigInteger nextNum = BigInteger.ONE;

				@Override
				public boolean hasNext() {
					return true;
				}

				@Override
				public BigInteger next() {
					BigInteger result = current;
					BigInteger newNext = current.add(nextNum);
					current = nextNum;
					nextNum = newNext;
					return result;
				}
			};
		}

		public static void main(String[] args) {
			new Fib().forEach(x -> System.out.println(x));
		}
	}


	class ArrayIterable<A> implements Iterable<A> {
		A[] as;

		public ArrayIterable(A[] as) {
			this.as = as;
		}

		@Override
		public Iterator<A> iterator() {
			return new Iterator<A>() {
				int currentIndex = 0;

				@Override
				public boolean hasNext() {
					return as.length > currentIndex;
				}

				@Override
				public A next() {
					return as[currentIndex++];
				}
			};
		}
	}


	class IterableString implements Iterable<Character> {
		Character[] chars;

		public IterableString(String str) {
			this.chars = str.chars().mapToObj(c -> (char) c).toArray(Character[]::new);
		}

		@Override
		public Iterator<Character> iterator() {
			return new ArrayIterable<Character>(chars).iterator();
		}
	}

	static void main(String[] args) {
		for (char c : new IterableString("Hello world!")) {
			System.out.println(c);
		}

	}


	class Lines implements Iterable<String> {
		static String NEW_LINE = System.getProperty("line.separator");
		private final String[] arr;

		public Lines(String str) {
			if (str.isEmpty()) arr = new String[0];
			else this.arr = str.split(NEW_LINE, -1);
		}

		@Override
		public Iterator<String> iterator() {
			return new ArrayIterable<String>(arr).iterator();
		}

		public static void main(String[] args) {
			for (String s : new Lines("hallo" + NEW_LINE + "welt!"))
				System.out.println(s);
		}
	}


	class Words implements Iterable<String> {
		private final String[] arr;

		public Words(String text) {
			if (text.isEmpty()) arr = new String[0];
			else this.arr = Arrays.stream(text.split("\\s+", -1)).filter(x -> !x.isEmpty()).toArray(String[]::new);
		}

		@Override
		public Iterator<String> iterator() {
			return new ArrayIterable<String>(arr).iterator();
		}
	}


	class IndexIterable<A> implements Iterable<A> {
		private final Function<Long, A> function;

		public IndexIterable(Function<Long, A> f) {
			this.function = f;
		}

		@Override
		public Iterator<A> iterator() {
			return new Iterator<>() {
				long index = 1;

				@Override
				public boolean hasNext() {
					return true;
				}

				@Override
				public A next() {
					return function.apply(index++);
				}
			};

		}
	}


	class GenerationIterable<A> implements Iterable<A> {
		A a;
		Function<A, A> f;

		public GenerationIterable(A a, Function<A, A> f) {
			this.a = a;
			this.f = f;
		}

		@Override
		public Iterator<A> iterator() {
			return new Iterator<A>() {
				private A current = a;

				@Override
				public boolean hasNext() {
					return true;
				}

				@Override
				public A next() {
					A result = current;
					current = f.apply(current);
					return result;
				}
			};
		}
	}


	class OddIterable extends GenerationIterable<Long> {
		public OddIterable() {
			super(1L, x -> x + 2);
		}

		public OddIterable(Long aLong, Function<Long, Long> f) {
			super(aLong, f);
		}
	}


	record Limit<A>(Iterable<A> itA, long n)
			implements Iterable<A> {
		public Iterator<A> iterator() {
			return new Iterator<>() {
				@Override
				public boolean hasNext() {
					return i < n;
				}

				@Override
				public A next() {
					i++;
					return it.next();
				}

				final Iterator<A> it = itA.iterator();
				int i = 0;

			};
		}
	}


	record Maperable<A, R>(Iterable<A> itA, Function<A, R> f)
			implements Iterable<R> {
		public Iterator<R> iterator() {
			return new Iterator<>() {
				@Override
				public boolean hasNext() {
					return it.hasNext();
				}

				@Override
				public R next() {
					return f.apply(it.next());
				}

				final Iterator<A> it = itA.iterator();

			};
		}
	}


	record Filterable<A>(Iterable<A> itA, Predicate<A> p)
			implements Iterable<A> {
		public Iterator<A> iterator() {
			return new MyIterator();
		}

		private class MyIterator implements Iterator<A> {
			Iterator<A> it = itA.iterator();
			A theNext = null;

			MyIterator() {
				getTheNext();
			}

			void getTheNext() {
				while (it.hasNext()){
					A leNext = it.next();
					if (p.test(leNext)) {
                        theNext = leNext;
                        return;
                    }
				}
			}

			public boolean hasNext() {
				return theNext != null;
			}

			public A next() {
				var result = theNext;
				getTheNext();
				return result;
			}
		}
	}


}
