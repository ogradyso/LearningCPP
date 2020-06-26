#define CATCH_CONFIG_MAIN
#include "catch.h"

#include <chrono>
#include <cstdio>
#include <random>
#include <vector>
#include <map>


long fib_sum(size_t n) {
	long last = 0, current = 1, temp = 0;
	if ((n == 0) | (n == 1)) {
		return n;
	}
	for (int i = 0; i < n - 1; i++) {
		temp = last + current;
		last = current;
		current = temp;
	}
	return current;

}

long random() {
	static std::mt19937_64 mt_engine{ 102787 };
	static std::uniform_int_distribution<long> int_d{ 1000, 2000 };
	return int_d(mt_engine);
}

struct Stopwatch {
	Stopwatch(std::chrono::nanoseconds& result)
		:result{ result },
		start{ std::chrono::system_clock::now() } {}
	~Stopwatch() {
		result = std::chrono::system_clock::now() - start;
	}
private:
	std::chrono::nanoseconds& result;
	const std::chrono::time_point<std::chrono::system_clock> start;
};

long cached_fib_sum(const size_t& n) {
	static std::map<long, long> cache;
	if (cache.find(n) == cache.end()) {
		std::pair<size_t, long> newPair{ n, fib_sum(random()) };
		cache.insert(newPair);
	}
	else {
		return
	}
	return 0;
}

int main() {
	size_t samples{ 1'000'000 };
	std::vector<ULONG> ulMyVector{};
	std::chrono::nanoseconds elapsed;
	{
		Stopwatch stopwatch{ elapsed };
		volatile double answer;
		while (samples--) {
			answer = fib_sum(random());
			//answer = cached_fib_sum(random());
		}
		printf("Answer: %f\n", answer);
	}
	printf("Elapsed: %g s.\n", elapsed.count() / 1'000'000'000);

}