package name.panitz.pmt.iteration;

import java.util.Iterator;

public class IntegerRangeIterator implements PmtIterator<Integer> {
	int from;
	int to;
	int step;

	IntegerRangeIterator(int from, int to, int step) {
		this.from = from;
		this.to = to;
		this.step = step;
	}

	public boolean schleifenTest() {
		return from <= to;
	}

	public void schleifeWeiterschalten() {
		from = from + step;
	}

	public Integer schleifenWert() {
		return from;
	}

	public static void main(String[] args) {
		for (Iterator<Integer> it = new IntegerRangeIterator(0, 10, 2)
		     ; it.hasNext()
				;
		) {
			int i = it.next();
			System.out.println(i);
		}
	}
}

