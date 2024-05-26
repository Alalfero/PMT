


package name.panitz.util;

import java.math.BigInteger;
import java.util.Spliterator;
import java.util.function.Consumer;
import java.util.stream.LongStream;
import java.util.stream.Stream;


public interface Strom {


	static long readBinary(String x) {
		return x.chars().reduce(0, (result, a) -> result * 2 + (a == '1' ? 1 : 0));
	}


	static long quersumme(long x) {
		return LongStream
				.iterate(x, (y) -> y / 10)
				.takeWhile(y -> y > 0)
				.reduce(0, (result, a) -> result + a % 10);
	}


	static long factorial(int x) {
		return LongStream
				.iterate(1L, (y) -> y + 1L)
				.limit(x)
				.reduce(1, (result, a) -> result * a);
	}


	static String asBinary(long x) {
		return (x == 0) ? "0"
				: LongStream
				.iterate(x, (y) -> y / 2)
				.takeWhile(y -> y > 0)
				.mapToObj(y -> y % 2)
				.reduce("", (result, a) -> a + result, String::concat);
	}


	static String convertToBase(int b, long x) {
		return (x == 0) ? "0" : LongStream
				.iterate(x, (y) -> y / b)
				.takeWhile(y -> y > 0)
				.mapToObj(y -> (int) y % b)
				.reduce("", (result, a) -> toDigit(a) + result, String::concat);

	}

	static String digits = "0123456789ABFDEFGHIJKLMNOPQRSTUVWXYZ";

	static char toDigit(int x) {
		return digits.charAt(x);
	}


	static long readFromBase(int b, String x) {
		return x.chars().reduce(0, (result, a) -> result * b + digits.indexOf(a));
	}

	public static record TwoLong(long i1, long i2) {
	}


	static public Stream<TwoLong> fibPairs() {
		return Stream.iterate(new TwoLong(0, 1), (a) -> new TwoLong(a.i2(), a.i1() + a.i2()));
	}


	static public Stream<Long> fibs() {
		return fibPairs().map(TwoLong::i1);
	}


	static public Stream<Long> fibs100() {
		return fibs().limit(100);
	}


	static public long fib(int n) {
		return n <= 0 ? 0L : fibs().skip(n - 1).findFirst().get();
	}

	static public record TwoBig(BigInteger i1, BigInteger i2) {
	}


	static public Stream<TwoBig> facPairs() {
		return Stream.iterate(new TwoBig(BigInteger.ONE, BigInteger.ONE), (a) ->
		{
			BigInteger bigInt = a.i1().add(BigInteger.ONE);
			return new TwoBig(bigInt, a.i2().multiply(bigInt));
		});
	}


	static public Stream<BigInteger> facs() {
		return facPairs().map(TwoBig::i2);
	}

	static public BigInteger fac(int n) {
		return facs().skip(n - 1).findFirst().get();
	}


	static public class SpliterateString
			implements Spliterator<Character> {
		int i = 0;
		int end;
		String s;

		public SpliterateString(String s) {
			this(0, s.length() - 1, s);
		}

		public SpliterateString(int i, int end, String s) {
			this.i = i;
			this.end = end;
			this.s = s;
		}

		@Override
		public boolean tryAdvance(Consumer<? super Character> action) {
			if (i <= end) {
				action.accept(s.charAt(i));
				i++;
				return true;
			} else return false;

		}

		@Override
		public Spliterator<Character> trySplit() {
			int middle = i+ (end + i) / 2;
			if (middle <=1) return null;
			int oEnd = end;
			end = middle;
			return new SpliterateString(middle+1, oEnd, s);
		}

		@Override
		public long estimateSize() {
			return (end - i);
		}

		@Override
		public int characteristics() {
			return 0;
		}
	}


}
