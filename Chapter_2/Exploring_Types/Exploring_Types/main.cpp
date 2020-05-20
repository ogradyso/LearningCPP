#include <cstdio>
#include <cstddef>
#include <cstdint>

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
	/*struct ClockOfTheLongNow {
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
*/
	//Access controls
	struct ClockOfTheLongNow {
		//constructors:
		ClockOfTheLongNow() {
			year = 2019;
		}
		ClockOfTheLongNow(int year_in) {
			if (!set_year(year_in)) {
				year = 2019;

			}
		}
		void add_year() {
			year++;
		}
		bool set_year(int new_year) {
			if (new_year < 2019) return false;
			year = new_year;
			return true;
		}
		int get_year() {
			return year;
		}
	private:
		int year;
	};

	ClockOfTheLongNow clock;
	if(!clock.set_year(2018)) { // will fail; 2018 < 2019
		clock.set_year(2019);
	}
	clock.add_year();
	printf("Year: %d\n", clock.get_year());

	//initializing:
	// the following all initialize an integer to zero
	// however, the last option should be avoided since its behavior is not predictable.
	int int_a = 0;
	int int_b{}; //braced initialization
	int int_c = {}; //braced initialization
	int int_d;
	//initialize to a value other than zero:
	int int_a2 = 42;
	int int_b2{ 42 }; //braced initialization
	int c2 = { 42 }; //braced initialization
	int d2 = (42);

	//initializing PODs
	struct PodStruct {
		uint64_t aNum;
		char b[256];
		bool c;
	};

	PodStruct initialized_pod1{}; // all fields set to 0
	PodStruct initialized_pod2 = {}; // all fields set to 0

	PodStruct initialized_pod3{ 42, "Hello" }; // fields a & b set, c = 0
	PodStruct initialized_pod4{ 42, "Hello", true }; // all fields set

	// initializing arrays
	int array_1[]{ 1,2,3};
	int array_2[5]{};
	int array_3[5]{ 1,2,3 };
	int array_4[5];

	struct Taxonomist {
		Taxonomist() {
			printf("(no argument)\n");
		}
		Taxonomist(char x) {
			printf("char: %c\n", x);
		}
		Taxonomist(int x) {
			printf("int: %d\n", x);
		}
		Taxonomist(float x) {
			printf("float: %f\n", x);
		}
	};

	Taxonomist t1;
	Taxonomist t2{ 'c' };
	Taxonomist t3{ 65537 };
	Taxonomist t4{ 6.02e23f };
	Taxonomist t5{ 'g' };
	Taxonomist t6{ 'l' };
	Taxonomist t7{};
	//Taxonomist t8(); This line results in unusual behavior

}