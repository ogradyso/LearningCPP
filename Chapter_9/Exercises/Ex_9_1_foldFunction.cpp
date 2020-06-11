#include <cstdio>

//template <typename Fn, typename In, typename Out>
//constexpr Out fold(Fn function, In* input, size_t length, Out initial);
template <typename...T>
constexpr auto sumFun(T... args) {
	return (... + args);
}

int main() {
	int data[]{ 100, 200, 300, 400, 500 };
	size_t data_len = 5;
	//auto sum = fold([](auto x, auto y) {return x + y; }, data, data_len, 0);
	//auto sum = sumFun(100, 200, 300, 400, 500);
	printf("Sum: %d\n", sumFun(100, 200, 300, 400, 500));
}