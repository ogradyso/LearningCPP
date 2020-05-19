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
	printf("The maximum value is %lu\n", maximum);

	// range based for loop:
	for (unsigned long value : values) {
		if (value > maximum) maximum = value;
	}
	printf("Range-based for loop found maximum: %lu\n", maximum);

	// find the number of elements in an array using size_t:
	// take the size of the array (in bytes) and divide by the size of 
	// a the same type as a single element of the array.
	size_t n_elements = sizeof(values) / sizeof(short);
	printf("Length of values array: %zd\n", n_elements);

	//C-style strings
	char english[] = "A book holds a house of gold.";
	char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";
	printf("English: %s\n", english);
	//printf("Chinese: %s\n", chinese);

	// make array with ASCII printable letters, print the result, and then convert the array to uppercase
	char alphabet[27];
	for (int i = 0; i < 26; i++) {
		alphabet[i] = i + 97;
	}
	alphabet[26] = 0;
	printf("%s\n", alphabet);
	for (int i = 0; i < 26; i++) {
		alphabet[i] = i + 65;
	}
	printf("%s\n", alphabet);

	//user defined types
	//enumerations
	enum class Race {
		Dinan, 
		Teklan, 
		Ivyn, 
		Moiran, 
		Camite, 
		Julian, 
		Aidan
	};
	Race langobard_race = Race::Aidan;

	// using a switch-case statement with an enum class
	switch (langobard_race) {
	case Race::Dinan: {
		printf("You word hard.");
	} break;
	case Race::Teklan: {
		printf("You are very strong.");
	} break;
	case Race::Ivyn: {
		printf("You are a great reader.");
	} break;
	case Race::Moiran: {
		printf("My, how versatile you are!");
	} break;
	case Race::Camite: {
		printf("You're incredibly helpful.");
	} break;
	case Race::Julian: {
		printf("Anything you want!");
	} break;
	case Race::Aidan: {
		printf("What an enigma.");
	} break;
	default: {
		printf("Error: unknown race.");
	}
	}

	// plain old data types (PODs):
	struct Book {
		char name[256];
		int year;
		int pages;
		bool hardcover;
	};

	Book neuromancer;
	neuromancer.pages = 271;
	neuromancer.year = 1971;
	printf("Neuromancer was written in %d, and contains %d pages.\n", neuromancer.year, neuromancer.pages);

	//unions: like PODs but different
	union Variant {
		char string[10];
		int integer;
		double floating_point;
	};

	//fully featured C++ Classes
	struct ClockOfTheLongNow {
		void add_year() {
			year++;
		}
		int add_years(int valToAdd) {
			return year + valToAdd;
		}
		int year;
	};

	ClockOfTheLongNow clock;
	clock.year = 2017;
	clock.add_year();
	printf("Year: %d\n", clock.year);
	clock.year = clock.add_years(20);
	printf("Year: %d\n", clock.year);

}