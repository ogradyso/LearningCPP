#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <forward_list>

struct Stopwatch {
	Stopwatch(std::chrono::nanoseconds& result)
		: result{result},
		start{ std::chrono::high_resolution_clock::now() } {}
	~Stopwatch() {
		result = std::chrono::high_resolution_clock::now() - start;
	}
private:
	std::chrono::nanoseconds& result;
	const std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

long random() {
	static std::mt19937_64 mt_engine{ 102787 };
	static std::uniform_int_distribution<long> int_d{ 1000, 2000 };
	return int_d(mt_engine);
}

int main() {
	std::chrono::nanoseconds elapsed;
	{
		size_t nums = 1'000'000;
		std::forward_list<int> easy_as{};
		for (size_t i{}; i < nums; i++) {
			easy_as.push_front(random());
		}
		auto itr = easy_as.begin();
		Stopwatch stopwatch{ elapsed };
		while (itr != easy_as.end()) {
			itr++;
		}
	}
	auto operatingTime = elapsed.count();
	printf("Program took %gms to run.", operatingTime);
};