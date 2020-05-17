#include <cstdio>

int absoluteValue(int inputVal) {
	if (inputVal >= 0) return inputVal;
	else return inputVal * -1;
}

int sum(int val1, int val2) {
	return val1 + val2;
}

int main() {
	int valToPass = -42;
	int absValToPass = absoluteValue(valToPass);
	int sumFun = sum(valToPass, absValToPass);
	printf("The absolute value of %d is %d.\n", valToPass, absValToPass);
	printf("The sum of both integers is %d.", sumFun);
	return 0;
}