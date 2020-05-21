#include <cstdio>

struct ClockOfTheLongNow {
	ClockOfTheLongNow() {
		year = 2019;
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

struct College {
	char name[256];
};

void print_names(College* colleges, size_t n_colleges) {
	for (size_t i = 0; i < n_colleges; i++) {
		printf("%s College\n", colleges[i].name);
	}
}

int main() {
	//pointers
	// pointers encode an objects type and its address

	//adressing variables:
	int gettysburg{};
	printf("gettysburg: %d\n", gettysburg);

	//reference pointers:
	//append the object type with * to get the memory address for the object:
	int* gettysburg_address = &gettysburg;
	printf("&gettysburg: %p\n", gettysburg_address);

	// dereferencing pointers
	//prepend variable name with start to access the object rather than the adress of the object
	*gettysburg_address = 753;
	printf("Gettysburg address = %d\n", *gettysburg_address);
	printf("Gettysburg: %d\n", gettysburg);

	//The member-of-pointer operator (->)
	// this operator dereferences a pointer and access a member of the pointed to object
	ClockOfTheLongNow clock;
	ClockOfTheLongNow* clock_ptr = &clock; // set clock_ptr to the address of the clock object
	clock_ptr->set_year(2020);
	printf("Clock's year member: %d\n", clock_ptr ->get_year());
	printf("Address of clock: %p\n", clock_ptr);
	printf("Value of clock's year: %d\n", clock_ptr->get_year());

	// pointers and arrays
	//pointers encode object locations
	// arrays encode the location and length of contiguous objects
	// arrays can become decay into a pointer pointing to the location of the first object in the array
	int key_to_the_universe[]{3,6,9};
	int* key_ptr = key_to_the_universe;  // points to 3

	//College best_colleges[] = { "Magdalen","Nuffield", "Kellogg" };
	//print_name(best_colleges);
	College oxford[] = { "Magdalen", "Nuffield", "Kellog" };
	print_names(oxford, sizeof(oxford) / sizeof(College));

	//pointer arithmetic
	//address of the nth element of an array can be obtained in two ways:
	College* third_college_ptr = &oxford[2];
	printf("Address of the 3rd element in oxford array: %p\n", third_college_ptr);
	//or by pointer arithmetic:
	College* thrid_college_ptr = oxford + 2;
	printf("Address of the 3rd element in oxford array: %p\n", third_college_ptr);

	//the danger of arrays: buffer overflow
	char lower[] = "abc?e";
	char upper[] = "ABC?E";
	char* upper_ptr = upper;

	lower[3] = 'd';
	upper[3] = 'D';

	char letter_d = lower[3];
	char letter_D = upper_ptr[3];

	printf("lower: %s\nupper: %s\n", lower, upper);
	// never add an element beyond an arrays' last index!!


	//connection between brackets and pointer arithmetic

}