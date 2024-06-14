package hsrm.pmt;

import static hsrm.pmt.BankSystem.transfer;

public class TestMain {
	public static void main(String[] args) throws Exception {
		var bank1 = new BankAccount(1,10);
		var bank2 = new BankAccount(3,30);

		System.out.println(transfer(bank1, bank2, 5));
	}
}