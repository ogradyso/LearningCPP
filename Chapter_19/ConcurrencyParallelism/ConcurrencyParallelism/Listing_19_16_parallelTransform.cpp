#include <algorithm>
#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
	vector<long> numbers( 1'000'000 ), squares( 1'000'000 );
	iota(numbers.begin(), numbers.end(), 0);
	size_t n_transformed{};
	transform(execution::par, numbers.begin(), numbers.end(), squares.begin(), [&n_transformed](const auto x) {
		++n_transformed;
		return x * x;
		});
	cout << "n_transformed: " << n_transformed << endl;
}

