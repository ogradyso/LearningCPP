#include <cstdio>
#include <cstdint>

size_t count_if(char x, const char* str) {
	size_t index{}, result{};
	while (str[index]) {
		if (str[index]==x) result++;
		index++;
	}
	return result;
}

//int main() {
//	auto sally = count_if('s', "Sally sells seashells by the seashore.");
//	printf("Sally : %zd\n", sally);
//	auto sailor = count_if('s', "Sailor went to sea to see what he could see.");
//	printf("Sailor : %zd\n", sailor);
//	auto buffalo = count_if('f',"Buffalo buffalo buffalo buffalo"
//				"buffalo buffalo buffalo buffalo.");
//	printf("Buffalo: %zd\n", buffalo);
//}