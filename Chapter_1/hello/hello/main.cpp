#include <cstdio>
int addOne(int valueToIncrement) {
	return valueToIncrement + 1;
}

int main() {
	printf("Hello, World!");
	int myIntVar = 42;
	printf("My integer is %d\n", myIntVar);
	if (myIntVar % 2 == 0) printf("Even number");
	else printf("Odd number");

	int myIntVar2 = addOne(myIntVar);
	if (myIntVar2 % 2 == 0) printf("Even number");
	else printf("Odd number");
	return 0;
}
