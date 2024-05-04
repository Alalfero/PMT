package name.panitz.pmt.iteration;

import java.util.Iterator;

public class IntegerRange implements Iterable<Integer> {
	int from;
	int to;
	int step;

	public IntegerRange(int from, int to, int step) {
		this.from = from;
		this.to = to;
		this.step = step;
	}

	public IntegerRange(int from, int to) {
		this(from, to, 1);
	}

	public IntegerRange(int from) {
		this(from, Integer.MAX_VALUE, 1);
	}

	public java.util.Iterator<Integer> iterator() {
		return new IntegerRangeIterator(from, to, step);
	}

	public static void main(String[] args) {
		IntegerRange is = new IntegerRange(0, 10, 2);
		for (int i : is) {
			System.out.println(i);
		}

		is.forEach(i -> System.out.println(i));

		for (Iterator<Integer> it = is.iterator(); it.hasNext(); ) {
			int i = it.next();
			System.out.println(i);
		}
	}
}

