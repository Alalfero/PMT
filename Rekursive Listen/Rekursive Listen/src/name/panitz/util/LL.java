

package name.panitz.util;

import java.util.function.Function;
import java.util.function.Predicate;
import java.util.function.Consumer;
import java.util.Comparator;

import java.util.NoSuchElementException;

public sealed interface LL<E> permits LL.Nil, LL.Cons {

  record Nil<E>() implements LL<E> {
    @Override
    public String toString() {
      return "[]";
    }
  }

  record Cons<E>(E hd, LL<E> tl) implements LL<E> {
    @Override
    public String toString() {
      return show(true, new StringBuffer("["));
    }
  }

  default boolean isEmpty() {
    return this instanceof Nil;
  }

  default E head() {
    if (this instanceof Cons<E> c) return c.hd();
    throw new NoSuchElementException("head on empty list");
  }

  default LL<E> tail() {
    if (this instanceof Cons<E> c) return c.tl();
    throw new NoSuchElementException("tail on empty list");
  }

  @SuppressWarnings("rawtypes")
  final LL nil = new Nil<>();

  @SuppressWarnings("unchecked")
  static <E> LL<E> nil() {
    return nil;
  }

  static <E> LL<E> cons(E hd, LL<E> tl) {
    return new Cons<>(hd, tl);
  }

  @SafeVarargs
  static <E> LL<E> of(E... es) {
    LL<E> r = nil();
    for (int i = es.length - 1; i >= 0; i--) r = cons(es[i], r);
    return r;
  }

  default String show(boolean first, StringBuffer result) {
    if (isEmpty()) {
      result.append("]");
      return result.toString();
    }
    if (!first) result.append(", ");
    result.append(head());
    return tail().show(false, result);
  }

  default int length() {
    return this.isEmpty() ? 0 : this.tail().length() + 1;
  }

  default E last() {
    if (this.isEmpty()) throw new NoSuchElementException();
    if (this.tail().isEmpty()) return this.head();
    else return this.tail().last();
  }

  default LL<E> append(LL<E> that) {
    if (this.isEmpty()) return that;
    return cons(this.head(), this.tail().append(that));
  }

  default LL<E> drop(int i) {
    if (i > this.length() || this.isEmpty()) return nil();
    if (i <= 0) return this;
    return this.tail().drop(i - 1);
  }

  default LL<E> take(int i) {
    if (i <= 0) return nil();
    if (i > this.length()) return this;
    return cons(this.head(), this.tail().take(i - 1));
  }

  default LL<E> sublist(int from, int length) {
    return this.drop(from).take(length);
  }

  default LL<E> reverse() {
    return this.isEmpty() ? nil() : cons(this.last(), this.take(this.length() - 1).reverse());
  }

  default LL<E> intersperse(E e) {
    if (this.isEmpty() || this.tail().isEmpty()) return this;
    return cons(this.head(), cons(e, this.tail().intersperse(e)));
  }

  default boolean isPrefixOf(LL<E> that) {
    if (this.isEmpty()) return true;
    if (that.isEmpty()) return false;
    return this.head().equals(that.head()) && this.tail().isPrefixOf(that.tail());
  }

  default boolean isSuffixOf(LL<E> that) { return this.reverse().isPrefixOf(that.reverse()); }

  default boolean isInfixOf(LL<E> that) {
    if (that.isEmpty()) return false;
    if (this.isPrefixOf(that) || this.isEmpty()) return true;
    return this.isInfixOf(that.tail());
  }

  default E get(int i) {
    if (i < 0 || i > this.length() || this.isEmpty()) throw new IndexOutOfBoundsException();
    return this.drop(i).head();
  }

  default LL<E> rotate() {
    return this.isEmpty() ? nil() : this.drop(1).append(cons(this.head(), nil()));
  }

  default LL<LL<E>> tails() {
    return this.isEmpty() ? of(nil()) : cons(this, this.tail().tails());
  }

  default void forEach(Consumer<? super E> con) {
    if (!this.isEmpty()) {
      con.accept(this.head());
      this.tail().forEach(con);
    }
  }

  default boolean containsWith(Predicate<? super E> p) {
    if (this.isEmpty()) return false;
    if (p.test(this.head())) return true;
    return this.tail().containsWith(p);
  }

  default boolean contains(E el) {
    if (this.isEmpty()) return false;
    if (this.head().equals(el)) return true;
    return this.tail().contains(el);
  }

  default LL<E> dropWhile(Predicate<? super E> p) {
    if (this.isEmpty()) return nil();
    if (!p.test(this.head())) return this;
    return this.tail().dropWhile(p);
  }

  default LL<E> takeWhile(Predicate<? super E> p) {
    if (this.isEmpty() || !p.test(this.head())) return nil();
    return cons(this.head(), this.tail().takeWhile(p));
  }


  default LL<E> filter(Predicate<? super E> p) {
    if (this.isEmpty()) return nil();
    if (!p.test(this.head())) return tail().filter(p);
    return cons(this.head(), this.tail().filter(p));
  }


  default <R> LL<R> map(Function<? super E, ? extends R> f) {
    if (this.isEmpty()) return nil();
    return cons(f.apply(this.head()), this.tail().map(f));
  }

  record Pair<A, B>(A fst, B snd) {
    @Override
    public String toString() {
      return "(" + fst() + ", " + snd() + ")";
    }
  }


  default <B> LL<Pair<E, B>> zip(LL<B> that) {
    if (this.isEmpty() || that.isEmpty()) return nil();
    return cons(new Pair<>(this.head(), that.head()), this.tail().zip(that.tail()));
  }

  default Pair<LL<E>, LL<E>> span(Predicate<? super E> p) {
    if (this.isEmpty()) return new Pair<>(nil(), nil());
    return new Pair<>(this.takeWhile(p), this.dropWhile(p));
  }

  default Pair<LL<E>, LL<E>> partition(Predicate<? super E> p) {
    if (this.isEmpty()) return new Pair<>(nil(), nil());
    return new Pair<>(this.filter(p), this.filter(p.negate()));
  }

  default boolean isSorted(Comparator<? super E> cmp) {
    if (this.isEmpty() || this.tail().isEmpty()) return true;
    if (cmp.compare(this.head(), this.tail().head()) > 0) return false;
    return tail().isSorted(cmp);
  }

  default LL<E> qsort(Comparator<? super E> cmp) {
    if (this.isEmpty()) return nil();
    LL<E> smaller = this.tail().filter(x -> cmp.compare(x, this.head()) < 0);
    LL<E> bigger = this.tail().filter(x -> cmp.compare(x, this.head()) >= 0);
    return smaller.qsort(cmp).append(cons(this.head(), bigger.qsort(cmp)));
  }


}