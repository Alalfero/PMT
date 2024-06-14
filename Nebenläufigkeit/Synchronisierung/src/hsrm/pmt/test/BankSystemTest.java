package hsrm.pmt.test;

import hsrm.pmt.BankAccount;
import hsrm.pmt.BankSystem;
import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.fail;

public class BankSystemTest {

    @Test
    public void testSingleThreadedTransfer() throws Exception {
        var source = new BankAccount(1, 1000);
        var target = new BankAccount(2, 1000);
        BankSystem.transfer(source, target, 500);
        assertEquals(500, source.getBalance(), 0.1);
        assertEquals(1500, target.getBalance(), 0.1);
    }

    @Test
    public void testMultiThreadedTransfer() throws Exception {
        var source = new BankAccount(1, 1000);
        var target1 = new BankAccount(2, 1000);
        var target2 = new BankAccount(2, 1000);

        var t1 = new Thread(() -> {
            try {
                BankSystem.transfer(source, target1, 200);
            } catch (Exception e) {
                fail(e.getMessage());
            }
        });
        var t2 = new Thread(() -> {
            try {
                BankSystem.transfer(source, target2, 200);
            } catch (Exception e) {
                fail(e.getMessage());
            }
        });

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        assertEquals(600, source.getBalance(), 0.1);
        assertEquals(1200, target1.getBalance(), 0.1);
        assertEquals(1200, target2.getBalance(), 0.1);
    }

    @Test
    public void testOpposite() throws Exception {
        var source = new BankAccount(1, 1000);
        var target = new BankAccount(2, 1000);

        var t1 = new Thread(() -> {
            try {
                BankSystem.transfer(source, target, 600);
            } catch (Exception e) {
                fail(e.getMessage());
            }
        });
        var t2 = new Thread(() -> {
            try {
                BankSystem.transfer(target, source, 600);
            } catch (Exception e) {
                fail(e.getMessage());
            }
        });

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        assertEquals(1000, source.getBalance(), 0.1);
        assertEquals(1000, target.getBalance(), 0.1);
    }

    @Test
    public void testCircular() throws Exception {
        var accounts = new BankAccount[5];
        for (int i = 0; i < 5; i++) { accounts[i] = new BankAccount(i+1, 1000); }

        var threads = new Thread[5];
        for (int i = 0; i < 5; i++) {
            int finalI = i;
            threads[i] = new Thread(() -> {
                try {
                    BankSystem.transfer(accounts[finalI], accounts[(finalI + 1) % 5], 600);
                } catch (Exception e) {
                    fail(e.getMessage());
                }
            });
            threads[i].start();
        }

        for (int i = 0; i < 5; i++) { threads[i].join(); }
        for (int i = 0; i < 5; i++) { assertEquals(1000, accounts[i].getBalance(), 0.1); }
    }
}
