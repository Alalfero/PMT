package name.panitz.pmt.iteration;

import java.util.Iterator;

public interface PmtIterator<A> extends Iterator<A> {
	boolean schleifenTest();

	void schleifeWeiterschalten();

	A schleifenWert();

	public default A next() {
		A result = schleifenWert();
		schleifeWeiterschalten();
		return result;
	}

	public default boolean hasNext() {
		return schleifenTest();
	}
}

