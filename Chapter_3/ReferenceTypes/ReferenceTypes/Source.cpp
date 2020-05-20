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

}