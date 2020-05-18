#include <cstdio>
#include <cstddef>

int main() {

	//integer types, literals
	unsigned short a = 0b10101010;
	printf("Binary literatal: %hu\n", a);
	int b = 0123;
	printf("Octal: %d\n", b);
	unsigned long long d = 0xFFFFFFFFFFFFFFFF;
	printf("Hexadecimal literal: %llu\n", d);

	//printing an integer as a hexadecimal or octal representation
	unsigned int f = 3669732608;
	printf("Yabba %x!\n", a);
	unsigned int g = 69;
	printf("There are %u, %o leaves here.\n", g, g);

	//representing real numbers
	float smallestPrecision = 0.1;
	double mediumPrecision = 0.11123;
	long double mostPrecise = 0.232313123222;

	printf("This is a float: %f \n", smallestPrecision);
	printf("This is a double: %lf\n", mediumPrecision);
	printf("This is a long double represented in scientific notation: %Le\n", mostPrecise);
	printf("\n");

	// character types:
	char myLetter = 'S';
	printf("My letter is: %c", myLetter);
	
	//boolean types:
	bool b1 = true;
	bool b2 = false;
	printf("%d %d\n", b1, b2);

	//sizes of types
	//must include the cstddef header
	size_t size_c = sizeof(char);
	printf("char: %zd\n", size_c);
	size_t size_s = sizeof(short);
	printf("short: %zd\n", size_s);
	size_t size_i = sizeof(int);
	printf("int: %zd\n", size_i);
	size_t size_l = sizeof(long);
	printf("long: %zd\n", size_l);
	size_t size_ll = sizeof(long long);
	printf("long: %zd\n", size_ll);

	// arrays:
	int my_array[100];
	int my_2ndArray[] = { 1,2,3,4,5 };
	printf("Print the 3rd element of an array: %d\n", my_2ndArray[2]);
	                 
	// for loops:
	unsigned long maximum = 0;
	unsigned long values[] = { 10, 50, 20, 40, 0 };
	for (size_t i = 0; i < 5; i++) {
		if (values[i] > maximum) maximum = values[i];
	}
	printf("The maximum value is %lu", maximum);


}