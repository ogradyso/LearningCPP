#include <cstdio>

int absoluteValue(int inputVal) {
	if (inputVal >= 0) return inputVal;
	else return inputVal * -1;
}

int main() {
	int valToPass = -42;
	int absValToPass = absoluteValue(valToPass);
	printf("The absolute value of %d is %d.", valToPass, absValToPass);
	return 0;
}