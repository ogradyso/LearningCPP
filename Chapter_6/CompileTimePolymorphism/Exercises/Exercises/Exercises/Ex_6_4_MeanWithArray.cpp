#include <cstddef>
#include <cstdio>

template <size_t Index, typename T, size_t Length>
int mean(T (&arr)[Length]){
static_assert(Index < Length, "Out-of-bounds access.");
	T result{};
	for (size_t i{}; i < Length; i++) {
		result += arr[i];
	}
	return result / Length;
}

//int main() {
//	int nums_d[]{ 1,2,3,4 };
//	const auto result3 = mean<3>(nums_d);
//	printf("Mean: %zd\n", result3);
//}