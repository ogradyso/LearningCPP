#include <cstdio>

struct Logger {
	virtual ~Logger() = default;
	virtual void log_transfer(long from, long to, double amount) = 0;
};

struct ConsoleLogger : Logger {
	ConsoleLogger(const char* prefix) {
		name = prefix;
	}
	void log_transfer(long from, long to, double amount) override {
		printf("[%s] %ld -> %ld: %f\n", this->name, from, to, amount);
	}
	const char* name;
};

struct FileLogger : Logger {
	void log_transfer(long from, long to, double amount) override {
		printf("[file] %ld, %ld, %f\n", from, to, amount);
	}
};


//exercise 5_1:
struct AccountDatabase {
	void set_amount(double valToAdd) {
		amount = amount + valToAdd;
		printf("Updated account %ld, remaining balance: %f", id, amount);
	}
	double retrieve_balance(long id) {
		printf("Acount balance for %ld: %f", id, amount);
	}
	double amount;
	long id;
};

struct inMemoryAccountDatabase : AccountDatabase {
	inMemoryAccountDatabase(long newId, double startBalance) {
		id = newId;
		amount = startBalance;
	}
};

//property injection
struct Bank {
	Bank(AccountDatabase& accounts) : accountsDB{ accounts } { }
	void set_logger(Logger* new_logger) {
		logger = new_logger;
	}
	void make_transfer(long from, long to, double amount) {
		if (logger) logger->log_transfer(from, to, amount);
	}
	AccountDatabase& accountsDB;
private:
	Logger* logger{};
};

int main() {
	ConsoleLogger console_logger{"MyLog"};
	FileLogger file_logger;
	inMemoryAccountDatabase account1{ 1000, 5.00 };
	Bank bank{account1};
	bank.set_logger(&console_logger);
	bank.make_transfer(1000, 2000, 49.95);
	bank.set_logger(&file_logger);
	bank.make_transfer(2000, 4000, 20.00);
	bank.accountsDB.set_amount(10.00);
}