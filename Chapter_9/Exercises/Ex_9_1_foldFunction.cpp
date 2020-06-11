#include <cstdio>

template <typename Fn, typename In, typename Out>
constexpr Out fold(Fn function, In* input, size_t length, Out initial) {
	for (size_t i{}; i < length; i++) {
		initial = function(initial, input[i]);
	}
	return initial;
}

//int main() {
//	int data[]{ 100, 200, 300, 400, 500 };
//	size_t data_len = 5;
//	auto sum = fold([](auto x, auto y) {return x + y; }, data, data_len, 0);
//	auto minNum = fold([](auto x, auto y) {return x < y ? x: y; }, data, data_len, 0);
//	auto maxNum = fold([](auto x, auto y) {return x < y ? y: x; }, data, data_len, 0);
//	auto numGreater = fold([](auto x, auto y) {return y > 200 ? x + 1 : 0; }, data, data_len, 0);
//	printf("Sum: %d\n", sum);
//	printf("Min: %d\n", minNum);
//	printf("Min: %d\n", maxNum);
//	printf("CountGreater than: %d\n", numGreater);
//
//}