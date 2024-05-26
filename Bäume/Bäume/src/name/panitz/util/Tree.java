


package name.panitz.util;

import java.io.IOException;
import java.io.StringWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.stream.Collectors;


public class Tree<E> {


	public E element = null;

	public List<Tree<E>> childNodes = new ArrayList<>();

	public boolean isEmptyTree;

	public Tree<E> parent = null;

	public Tree() {
		isEmptyTree = true;
	}


	@SafeVarargs
	public Tree(E e, Tree<E>... ts) {
		element = e;
		isEmptyTree = false;
		for (Tree<E> t : ts) {
			if (!t.isEmptyTree) {
				childNodes.add(t);
				t.parent = this;
			}
		}
	}

	public static Tree<String> windsor =
			new Tree<>("George"
					, new Tree<>("Elizabeth"
					, new Tree<>("Charles"
					, new Tree<>("William"
					, new Tree<>("George")
					, new Tree<>("Charlotte"), new Tree<>("Louise"))
					, new Tree<>("Henry", new Tree<>("Archie"))
			)
					, new Tree<>("Andrew", new Tree<>("Beatrice"), new Tree<>("Eugenie"))
					, new Tree<>("Edward", new Tree<>("Louise"), new Tree<>("James"))
					, new Tree<>("Anne"
					, new Tree<>("Peter", new Tree<>("Savannah"), new Tree<>("Isla"))
					, new Tree<>("Zara", new Tree<>("Mia"), new Tree<>("Lena"))
			)
			)
					, new Tree<>("Magaret"
					, new Tree<>("David", new Tree<>("Charles"), new Tree<>("Margarita"))
					, new Tree<>("Sarah", new Tree<>("Samuel"), new Tree<>("Arthur"))
			)
			);


	public int groesse() {
		var result = 0;
		for (var child : childNodes) {
			result += child.groesse();
		}
		return result + 1;
	}


	public int size() {
		return isEmptyTree ? 0
				: childNodes.parallelStream()
				.reduce(0, (r, c) -> c.size() + r, (x, y) -> x + y) + 1;
	}


	public String alsString() {
		if (isEmptyTree) return "Empty()";
		String result = "Branch(" + element + ")[";
		for (Tree<E> child : childNodes) {
			result = result + child.alsString();
		}
		return result + "]";
	}

	@Override
	public String toString() {
		if (isEmptyTree) return "Empty()";


		StringBuffer result = new StringBuffer("Branch(");

		result.append(element.toString());
		result.append(")[");

		for (Tree<E> child : childNodes) {
			result.append(child.toString());
		}
		result.append("]");

		return result.toString();
	}

	public void writeAsString(String indent, Writer out) throws IOException {

		if (isEmptyTree) {
			out.write("[]");
			return;
		}

		out.write(element.toString());


		if (!childNodes.isEmpty()) {
			var newIndent = indent + "  ";
			for (Tree<E> child : childNodes) {
				out.write(newIndent);
				child.writeAsString(newIndent, out);
			}
		}
	}

	public String asString() {
		try {
			var out = new StringWriter();
			writeAsString("\n", out);
			return out.toString();
		} catch (java.io.IOException e) {
			return "";
		}
	}

	public String toLaTeX() {
		var result = new StringBuffer();
		result.append("""
				\\begin{tikzpicture}
				\\tikzset{grow'=right,level distance=80pt}
				\\tikzset{edge from parent/.append style={very thick}}");
				\\Tree 
				""");
		toLaTeXAux(result);

		result.append("\n\\end{tikzpicture}");
		return result.toString();
	}

	private void toLaTeXAux(StringBuffer result) {
		result.append("[.\\fcolorbox{black}{green!50!black}{\\bfseries ");
		result.append(element + "}");
		childNodes.forEach(child -> {
			result.append("\n");
			child.toLaTeXAux(result);

		});
		result.append(" ]");
	}


	public Tree<E> getRoot() {
		return parent == null ? this : parent.getRoot();
	}


	List<Tree<E>> auntsAndUncles() {
		var opa = parent.parent;
		return opa.childNodes.parallelStream()
				.filter(c -> c != parent).collect(Collectors.toList());
	}


	List<E> cousins() {
		List<E> result = new ArrayList<>();
		if (parent == null || parent.parent == null) return result;
		auntsAndUncles()
				.stream()
				.forEach(cs -> cs.childNodes.stream()
						.forEach(c -> result.add(c.element)));
		return result;
	}


	public void forEach(Consumer<? super E> con) {
		con.accept(element);
		for (Tree<E> child : childNodes) child.forEach(con);
	}


	public boolean contains(Predicate<? super E> pred) {
		boolean res = pred.test(element);
		for (Tree<E> child : childNodes) res = res || child.contains(pred);
		return res;
	}


	public List<E> fringe() {
		var result = new ArrayList<E>();
		fringe(result);
		return result;
	}

	public void fringe(List<E> result) {
		if (childNodes.isEmpty()) result.add(element);
		for (Tree<E> child : childNodes) child.fringe(result);
	}


	public List<E> ancestors() {
		var result = new ArrayList<E>();
		ancestors(result);
		return result;
	}

	public void ancestors(List<E> result) {
		if (this.parent != null) {
			result.add(this.parent.element);
			this.parent.ancestors(result);
		}
	}


	public List<E> siblings() {
		var result = new ArrayList<E>();
		siblings(result);
		return result;
	}

	public void siblings(List<E> result) {
		if (this.parent != null) {
			this.parent.childNodes.stream()
					.filter(c -> c != this)
					.forEach(c -> result.add(c.element));
		}
	}


	public List<E> pathTo(E elem) {
		var result = new ArrayList<E>();
		pathTo(elem, result);
		return result;
	}

	public void pathTo(E elem, List<E> result) {
		result.add(element);
		if (element.equals(elem)) return;

		for (Tree<E> child : childNodes) {
			child.pathTo(elem, result);
			if (!result.isEmpty() && result.get(result.size() - 1).equals(elem)) return;
		}

		if (!result.isEmpty() && !result.get(result.size() - 1).equals(elem)) result.remove(result.size() - 1);
		
	}


	public <R> Tree<R> map(Function<? super E, ? extends R> f) {
		Tree<R> map = new Tree<>(f.apply(element));
		for (Tree<E> child : childNodes) map.childNodes.add(child.map(f));
		return isEmptyTree ? new Tree<>() : map;

	}


	public List<E> getLevel(int level) {
		var result = new ArrayList<E>();
		getLevel(level, result);
		return result;
	}

	public void getLevel(int level, List<E> result) {
		if (level == 0) result.add(element);
		for (Tree<E> child : childNodes) child.getLevel(level - 1, result);

	}


	public List<E> myGeneration() {
		int level = 0;
		Tree<E> current = this;
		while (current.parent != null) {
			level++;
			current = current.parent;
		}

		return current.getLevel(level);
	}

}
