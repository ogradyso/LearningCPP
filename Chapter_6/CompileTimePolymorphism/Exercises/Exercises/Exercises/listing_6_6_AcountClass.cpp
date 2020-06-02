#include <cstdio>

struct Account {
	Account() = default;
	Account(long newId, double currentBalance) {
		id = newId;
		balance = currentBalance;
	}
	double get_balance() {
		return this->balance;
	}
	void set_balance(double newBalance) {
		this->balance = newBalance;
	}
	long id;
	double balance;
};

template <typename T>
struct Bank {
	Bank(T NewAccount) {
		account = NewAccount;
	}
	T account;
};

int main() {
	Account myAccount = { 12345, 50.00 };
	Bank<Account> myBank{myAccount};
	double accountBalance = myBank.account.get_balance();
	printf("Current balance: %f\n",accountBalance);
}