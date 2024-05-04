package name.panitz.pmt.iteration;

public class GeradeZahlenIterierer implements IntIterierer {
	int from;
	int to;

	GeradeZahlenIterierer(int from, int to) {
		this.from = from;
		this.to = to;
	}

	public boolean schleifenTest() {
		return from < to;
	}

	public void schleifeWeiterschalten() {
		from = from + 2;
	}

	public Integer schleifenWert() {
		return from;
	}

	public static void main(String[] args) {
		new GeradeZahlenIterierer(0, 10).run(x -> System.out.println(x));
	}
}

