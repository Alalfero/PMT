package hsrm.pmt;

public class BankSystem {

    public static boolean transfer(BankAccount source, BankAccount target, double amount) throws Exception {

        var small = source.getAccountNumber() < target.getAccountNumber() ? source: target;
        var big = source.getAccountNumber() > target.getAccountNumber() ? source: target;
        synchronized (small) {
            synchronized (big) {
                if (source.getBalance() > amount) {
                    source.withdraw(amount);
                    target.deposit(amount);
                    return true;
                }
            }
        }
        return false;
    }
}
