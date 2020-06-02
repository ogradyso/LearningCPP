#include <cstdio>

struct Account {
	Account() = default;
	Account(long newId, double currentBalance) {
		id = newId;
		balance = currentBalance;
	}
	double get_balance() {
		return balance;
	}
	void set_balance(double newBalance) {
		balance = newBalance;
	}
	void transfer(double amount, Account& other) {
		balance = balance - amount;
		other.set_balance(other.balance + amount);
	}
	long id;
	double balance;
};

struct savingsAccount : Account {

};

struct checkingAccount : Account {

};

template <typename T>
struct Bank {
	Bank(T NewAccount) {
		account = NewAccount;
	}
	T account;
};

int main() {
	Account myCheckingAccount = { 12345, 50.00 };
	Account mySavingsAccount = { 12323, 500.00 };
	Bank<Account> yourBank{ mySavingsAccount };
	Bank<Account> myBank {myCheckingAccount};

	myBank.account.transfer(5.00, yourBank.account);
	//double accountBalance = yourBank.account.get_balance();
	double accountBalance = yourBank.account.get_balance();
	printf("Current balance: %f\n",accountBalance);
	double accountBalance2 = myBank.account.get_balance();
	printf("Current balance: %f\n", accountBalance2);
}