package name.panitz.pmt.iteration;

public class IntegerRangeForEach {
	public static void main(String[] args) {
		new IntegerRangeIterator(0, 10, 2)
				.forEachRemaining(i -> System.out.println(i));
	}
}

