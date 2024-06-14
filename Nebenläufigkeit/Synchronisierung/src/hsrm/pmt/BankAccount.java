package hsrm.pmt;

public class BankAccount {
    private double balance;
    private final int number;

    public BankAccount(int number, double balance) {
        this.number = number;
        this.balance = balance;
    }

    public int getAccountNumber() {
        return number;
    }

    public double getBalance() {
        return balance;
    }

    public void withdraw(double amount) throws Exception {
        var newAmount = balance - amount;
        Thread.sleep(10);
        balance = newAmount;
    }

    public void deposit(double amount) throws Exception {
        var newAmount = balance + amount;
        Thread.sleep(10);
        balance = newAmount;
    }
}
