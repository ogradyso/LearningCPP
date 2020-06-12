#include <cstdio>
#include <cstdint>

template <typename Fn, typename In>
constexpr bool all(Fn function, In* input, size_t length) {
	for (size_t index{}; index < length; index++) {
		if (!function(input[index])) return false;
	}
}

int main() {
	int data[]{ 200, 200, 300, 400, 500 };
	size_t data_len = 5;
	auto all_gt100 = all([](auto x) {return x > 100; }, data, data_len);
	if (all_gt100) printf("All elements greater than 100.\n");
	
}
