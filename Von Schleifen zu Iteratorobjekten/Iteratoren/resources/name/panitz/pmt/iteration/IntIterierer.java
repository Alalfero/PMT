package name.panitz.pmt.iteration;

import java.util.function.Consumer;

public interface IntIterierer {
	boolean schleifenTest();

	void schleifeWeiterschalten();

	Integer schleifenWert();

	default void run(Consumer<Integer> action) {
		for (; schleifenTest(); schleifeWeiterschalten()) {
			action.accept(schleifenWert());
		}
	}
}

