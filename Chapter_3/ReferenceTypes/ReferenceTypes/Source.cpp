#include <cstdio>

struct ClockOfTheLongNow {
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
	// methods can be constant as long as they do not alter an object's members
	int get_year() const {
		return year;
	}
private:
	int year;
};

struct College {
	char name[256];
};

//for showing the relation between const and non-const members:
//struct Avout {
//	const char* name = "Erasmus";
//	ClockOfTheLongNow apert;
//};

//member initializer lists are used to set a constant member during constructor/initialization:
struct Avout {
	Avout(const char* name, long year_of_apert)
		: name { name }, apert { year_of_apert } { //member initializer list
	}
	void announce() const {
		printf("My name is %s and my next apert is %d.\n", name, apert.get_year());
	}
	const char* name;
	ClockOfTheLongNow apert;
};

void print_names(College* colleges, size_t n_colleges) {
	for (size_t i = 0; i < n_colleges; i++) {
		printf("%s College\n", colleges[i].name);
	}
}

void add_year(ClockOfTheLongNow& clock) {
	clock.set_year(clock.get_year() + 1); // no dereference operatore needed
}

//void does_not_compile(const Avout& avout) {
	//	avout.apert.add_year(); //compile error becuase the object is constant
	//}

void does_compile(Avout& avout) {
	avout.apert.add_year(); //does compile
};

//if an object is a const, it can only invoke methods that are const:
bool is_leap_year(const ClockOfTheLongNow& clock) {
	if (clock.get_year() % 4 > 0) return false;
	if (clock.get_year() % 100 > 0) return true;
	if (clock.get_year() % 400 > 0) return false;
	return true;
}

//forward linked lists
//struct Element {
//	Element* next{};
//	void insert_after(Element* new_element) {
//		new_element->next = next;
//		next = new_element;
//	}
//	char prefix[2];
//	short operating_number;
//
//};

//replaces about struct using 'this' keyword
struct Element {
	Element* next{};
	void insert_after(Element* new_element) {
		new_element->next = this->next;
		this->next = new_element;
	}
	char prefix[2];
	short operating_number;
};


//constants as arguments
void petruchio(const char* shrew) {
	printf("Fear not, sweet wench, they shall not touch thee, %s. \n", shrew);
}
//int main() {
//	//pointers
//	// pointers encode an objects type and its address
//
//	//adressing variables:
//	int gettysburg{};
//	printf("gettysburg: %d\n", gettysburg);
//
//	//reference pointers:
//	//append the object type with * to get the memory address for the object:
//	int* gettysburg_address = &gettysburg;
//	printf("&gettysburg: %p\n", gettysburg_address);
//
//	// dereferencing pointers
//	//prepend variable name with start to access the object rather than the adress of the object
//	*gettysburg_address = 753;
//	printf("Gettysburg address = %d\n", *gettysburg_address);
//	printf("Gettysburg: %d\n", gettysburg);
//
//	//The member-of-pointer operator (->)
//	// this operator dereferences a pointer and access a member of the pointed to object
//	ClockOfTheLongNow clock;
//	ClockOfTheLongNow* clock_ptr = &clock; // set clock_ptr to the address of the clock object
//	clock_ptr->set_year(2020);
//	printf("Clock's year member: %d\n", clock_ptr->get_year());
//	printf("Address of clock: %p\n", clock_ptr);
//	printf("Value of clock's year: %d\n", clock_ptr->get_year());
//
//	// pointers and arrays
//	//pointers encode object locations
//	// arrays encode the location and length of contiguous objects
//	// arrays can become decay into a pointer pointing to the location of the first object in the array
//	int key_to_the_universe[]{ 3,6,9 };
//	int* key_ptr = key_to_the_universe;  // points to 3
//
//	//College best_colleges[] = { "Magdalen","Nuffield", "Kellogg" };
//	//print_name(best_colleges);
//	College oxford[] = { "Magdalen", "Nuffield", "Kellog" };
//	print_names(oxford, sizeof(oxford) / sizeof(College));
//
//	//pointer arithmetic
//	//address of the nth element of an array can be obtained in two ways:
//	College* third_college_ptr = &oxford[2];
//	printf("Address of the 3rd element in oxford array: %p\n", third_college_ptr);
//	//or by pointer arithmetic:
//	College* thrid_college_ptr = oxford + 2;
//	printf("Address of the 3rd element in oxford array: %p\n", third_college_ptr);
//
//	//the danger of arrays: buffer overflow
//	char lower[] = "abc?e";
//	char upper[] = "ABC?E";
//	char* upper_ptr = upper;
//
//	lower[3] = 'd';
//	upper[3] = 'D';
//
//	char letter_d = lower[3];
//	char letter_D = upper_ptr[3];
//
//	printf("lower: %s\nupper: %s\n", lower, upper);
//	// never add an element beyond an arrays' last index!!
//
//
//	//void pointers and std::byte pointers
//	// void pointers (void*) can be used when the pointed to object is irrelevant
//	//void pointers cannot use pointer arithmetic
//
//	//null ptr and boolean expressions
//
//	//references
//	//safer than pointers because they cannot be set to null and cannot be reassigned
//	ClockOfTheLongNow clock2;
//	printf("The year is %d.\n", clock2.get_year());
//	add_year(clock2); // clock is implicitly passed by reference
//	printf("The year is %d.\n", clock2.get_year());
//
//	//pointers and forward linked lists
//	Element trooper1, trooper2, trooper3;
//	trooper1.prefix[0] = 'T';
//	trooper1.prefix[1] = 'K';
//	trooper1.operating_number = 421;
//	trooper1.insert_after(&trooper2);
//	trooper2.prefix[0] = 'F';
//	trooper2.prefix[1] = 'N';
//	trooper2.operating_number = 2187;
//	trooper2.insert_after(&trooper3);
//	trooper3.prefix[0] = 'L';
//	trooper3.prefix[1] = 'S';
//	trooper3.operating_number = 005;
//
//	for (Element* cursor = &trooper1; cursor; cursor = cursor->next) {
//		printf("stormtrooper %c%c-%d\n",
//			cursor->prefix[0],
//			cursor->prefix[1],
//			cursor->operating_number);
//	}
//
//	//employing references:
//	//setting reference reseats a value
//	int original = 100;
//	int& original_ref = original;
//	printf("Original: %d\n", original);
//	printf("Original_ref: %d\n", original_ref);
//
//	int new_value = 200;
//	original_ref = new_value;
//	printf("Original: %d\n", original);
//	printf("new_value: %d\n", new_value);
//	printf("original_ref: %d\n", original_ref);
//
//	//constant methods
//	ClockOfTheLongNow new_clock;
//	ClockOfTheLongNow* new_clock_ptr = &new_clock;
//	if (is_leap_year(new_clock)) printf("Leap year.\n");
//	else printf("Not a leap year.\n");
//	new_clock_ptr->set_year(2020);
//	if (is_leap_year(new_clock)) printf("Leap year.\n");
//	else printf("Not a leap year.\n");
//
//	//constant  members:
//	
//	//member initialization lists:
//	Avout raz{ "Erasmus", 3010 };
//	Avout jad{ "Jad", 4000 };
//	raz.announce();
//	jad.announce();
//
//	//auto type deduction
//	int answer = 42;
//	auto the_anser{ 42 }; // int
//	auto foot{ 12L };//long
//	auto rootbeer{ 5.0F }; //float
//	auto cheeseburger{ 10.0 }; //double
//	auto politifact_claims{ false }; //bool
//	auto cheese{ "String" }; //char[7]
//
//	auto another_answer = 42;
//	auto another_foot(12L);
//
//	//auto and reference types
//	//&:reference
//	//*:pointer
//	//const:const
//	auto year{ 2019 };	//int
//	auto& year_ref = year; //int&
//	const auto& year_cref = year; //const int&
//	auto* year_ptr = &year;  //int*
//	const auto* year_cptr = &year; // const int*
//
//	// auto and code refactorings
//	// using auto on structs will allow you to change the struct without changing the code that touches it.
//
// }
