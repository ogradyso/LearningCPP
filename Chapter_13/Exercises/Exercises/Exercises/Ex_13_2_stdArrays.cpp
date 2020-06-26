//#define CATCH_CONFIG_MAIN
//#include "catch.h"
//#include <array>
//#include <cstdio>
//#include <cstddef>
//
//using namespace std;
//
//
//int main() {
//	//listing 2-9 rewrite
//	array<int, 4> arr{1,2,3,4};
//	printf("The third element is %d.\n", arr[2]);
//	arr[2] = 100;
//	printf("The third element is %d.\n", arr[2]);
//
//	//listing 2-10 rewrite
//	unsigned long maximum = 0;
//	array<unsigned long, 5> values{ 10, 50, 20, 40, 0 };
//	for (size_t i = 0; i < 5; i++) {
//		if (values[i] > maximum) maximum = values[i];
//	}
//	printf("The maximum value is %lu.\n", maximum);
//
//	//listing 2-11 rewrite
//	unsigned long maximum2 = 0;
//	array<unsigned long, 5> values2{ 10, 50, 20, 40, 0 };
//	for (unsigned long value : values2) {
//		if (value > maximum2) maximum2 = value;
//	}
//	printf("The maximum value is %lu.\n", maximum2);
//}