package name.panitz.pmt.iteration;

import java.util.function.Consumer;

public interface GenerischerIterierer<A> {
	boolean schleifenTest();

	void schleifeWeiterschalten();

	A schleifenWert();

	default void run(Consumer<? super A> action) {
		for (; schleifenTest(); schleifeWeiterschalten()) {
			action.accept(schleifenWert());
		}
	}
}

