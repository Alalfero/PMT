package name.panitz.pmt.util;

import java.util.Iterator;

public record AnonIntegerRange(int from, int to, int step)
		implements Iterable<Integer> {
	public Iterator<Integer> iterator() {
		return new Iterator<>() {
			int from = AnonIntegerRange.this.from;
			int to = AnonIntegerRange.this.to;
			int step = AnonIntegerRange.this.step;

			public boolean hasNext() {
				return from < to;
			}

			public Integer next() {
				int result = from;
				from = from + step;
				return result;
			}
		};
	}
}

