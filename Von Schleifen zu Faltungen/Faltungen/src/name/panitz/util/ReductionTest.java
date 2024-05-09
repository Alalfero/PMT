package name.panitz.util;
import static name.panitz.util.Reduction.*;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;

import java.util.Arrays;
import java.util.Collection;
import java.util.List;
import java.util.Set;
import java.util.HashSet;

import java.util.Iterator;

import org.junit.Before;
import org.junit.Test;
import java.math.BigInteger;

public class ReductionTest {
  @Test
  public void test1() {
    assertEquals(10,sum(List.of(1,2,3,4)));
  }
  @Test
  public void test2() {
    assertEquals(0,sum(List.of()));
  }

  @Test
  public void test3() {
    assertEquals(24L,product(List.of(1L,2L,3L,4L)));
  }
  @Test
  public void test4() {
    assertTrue(exists(List.of(1L,2L,3L,4L),x->x==3L));
    assertFalse(exists(List.of(1L,2L,3L,4L),x->x==42L));
  }
  @Test
  public void test5() {
    assertEquals(4L,maximum(List.of(1L,2L,3L,4L)));
  }
  @Test
  public void test5b() {
    assertEquals(-1L,maximum(List.of(-1L,-2L,-3L,-4L)));
  }

  @Test
  public void test6() {
    assertEquals(42L,maximum(List.of(1L,2L,42L,3L,4L)));
  }

  @Test
  public void test7() {
    assertTrue(all(List.of(1L,2L,3L,4L),x->x<=4L));
    assertFalse(all(List.of(1L,2L,3L,4L),x->x==42L));
    assertTrue(all(List.of(),x->false));
  }
  @Test
  public void test8() {
    assertEquals(Set.of(2L,4L),collect(List.of(1L,2L,3L,4L),x->x%2L==0));
  }
  @Test
  public void test9() {
    assertEquals(42,readBinary("101010"));
  }
  @Test
  public void test10() {
    assertEquals(1,readBinary("00000000001"));

  }

  @Test
  public void test11() {
    assertEquals(3,readRoman("III"));
  }
  @Test
  public void test12() {
    assertEquals(4,readRoman("IV"));
  }
  @Test
  public void test13() {
    assertEquals(99,readRoman("IC"));
  }
  @Test
  public void test14() {
    assertEquals(999,readRoman("CMXCIX"));
  }

}
