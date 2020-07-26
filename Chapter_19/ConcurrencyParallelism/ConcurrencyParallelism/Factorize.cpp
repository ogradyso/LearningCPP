#include <set>
#include <chrono>
#include <sstream>
#include <string>

using namespace std;

struct Stopwatch {
	Stopwatch(std::chrono::nanoseconds& result)
		: result{ result },
		start{ std::chrono::high_resolution_clock::now() } {}
	~Stopwatch() {
		result = std::chrono::high_resolution_clock::now() - start;
	}
private:
	std::chrono::nanoseconds& result;
	const std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

template <typename T>
std::set<T> factorize(T x) {
	std::set<T> result{ 1 };
	for (T candidate{ 2 }; candidate <= x; candidate++) {
		if (x % candidate == 0) {
			result.insert(candidate);
			x /= candidate;
			candidate = 1;
		}
	}
	return result;
}

string factor_task(unsigned long x) {
	chrono::nanoseconds elapsed_ns;
	set<unsigned long long> factors;
	{
		Stopwatch stopwatch{ elapsed_ns };
		factors = factorize(x);
	}
	const auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(elapsed_ns).count();
	stringstream ss;
	ss << elapsed_ms << " ms: Factoring " << x << " ( ";
	for (auto factor : factors) ss << factor << " ";
	ss << ")\n";
	return ss.str();
};