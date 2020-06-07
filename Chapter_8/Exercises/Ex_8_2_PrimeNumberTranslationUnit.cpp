#include "PrimeNumbers.h"
#include <cstdio>

int main() {
	for (const auto i : PrimeNumberRange{ 5000 }) {
			printf("%d ", i);
	}
};