#include <cstdio>

struct Logger {
	virtual ~Logger() = default;
	virtual void log_transfer(long from, long to, double amount) = 0;
};

struct ConsoleLogger : Logger {
	void log_transfer(long from, long to, double amount) override {
		printf("[cons] %ld -> %ld: %f\n", from, to, amount);
	}
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
		printf("Updated accound %ld with %f", id, amount);
	}
	double retrieve_balance(long id) {
		printf("Acount balance for %ld: %f", id, amount);
	}
	double amount;
	long id;
};

struct inMemoryAccountDatabase : AccountDatabase {
	inMemoryAccountDatabase(long newId, double startBalance) : id{ newId }, amount{ startBalance } {
	}
};

//property injection
struct Bank {
	void set_logger(Logger* new_logger) {
		logger = new_logger;
	}
	void make_transfer(long from, long to, double amount) {
		if (logger) logger->log_transfer(from, to, amount);
	}
private:
	Logger* logger{};
};

int main() {
	ConsoleLogger console_logger;
	FileLogger file_logger;
	Bank bank;
	bank.set_logger(&console_logger);
	bank.make_transfer(1000, 2000, 49.95);
	bank.set_logger(&file_logger);
	bank.make_transfer(2000, 4000, 20.00);
	inMemoryAccountDatabase account1{ 1000, 5.00 };
	account1.set_amount(10.00);
}