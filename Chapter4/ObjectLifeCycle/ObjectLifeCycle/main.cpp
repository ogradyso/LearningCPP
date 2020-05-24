#include <cstdio>
#include <stdexcept>
//static storage duration
//static or extern keywords
//these variables have global scope:
//static int rat_things_power = 200;
//extern int rat_things_power = 200; //external linkage

//automatic storage duration
	//nuclear_isotopes and waste_heat are both automatic variables
	//local variables with local scope
//void power_up_rat_thing(int nuclear_isotopes) {
//	rat_things_power = rat_things_power + nuclear_isotopes;
//	const auto waste_heat = rat_things_power * 20;
//	if (waste_heat > 10000) {
//		printf("Warning! Hot doggie!\n");
//	}
//}

//local static variables and static members:
struct RatThing {
	static int rat_things_power;
	static void power_up_rat_thing(int nuclear_isotopes) {
		rat_things_power = rat_things_power + nuclear_isotopes;
		const auto waste_heat = rat_things_power * 20;
		if (waste_heat > 10000) {
			printf("Warning! Hot doggie!\n");
		}
		printf("Rat-thing power: %d\n", rat_things_power);
	}
};

//Tracing the object lifecycle
struct Tracer {
	Tracer(const char* name) : name{ name } {
		printf("%s constructed.\n", name);
	}
	~Tracer() {
		printf("%s destructed.\n", name);
	}
private:
	const char* const name;
};

static Tracer t1{ "Static variable" };
thread_local Tracer t2{ "Thread-local variable" };

//static members must be initialized globally:
int RatThing::rat_things_power = 200;

//Exceptions:
struct Groucho {
	void forget(int x) {
		if (x == 0xFACE) {
			throw std::runtime_error{ "I'd be glad to make an exception." };
		}
		printf("Forgot 0x%x\n", x);
	}
};

int main() {
	//The object life cycle

	//object storage duration
	//objects have type and value

	//allocation, deallocation, and lifetime
	//allocation - reserve storage for an object
	//deallocation - release objects storage
	
	//static storage duration
	//static or extern keywords
	//default is internal linkage: accessible to internal translation units
	//external linkage: accessible to external translation units
	/*printf("Rat-thing power: %d\n", rat_things_power);
	power_up_rat_thing(100);
	printf("Rat-thing power: %d\n", rat_things_power);
	power_up_rat_thing(500);
	printf("Rat-thing power: %d\n", rat_things_power);
	*/
	
	//local static variables
	//power_up_rat_thing(100);
	//power_up_rat_thing(500);

	//static members:
	RatThing::power_up_rat_thing(100);
	RatThing::power_up_rat_thing(500);

	// dynamic storage duration
	//dynamic objects are called allocated objects and use the 'new' keyword
	int* my_int_ptr = new int;
	int* my_int_ptr2 = new int{ 42 }; //initializing dynamic object
	//deallocation of dynamic objects uses 'delete' keyword
	delete my_int_ptr;
	delete my_int_ptr2;

	//dynamic arrays format:
	//new MyType[n_elements] {init-list}
	//returns a pointer to the first element of the array
	int* my_int_array_ptr = new int[100];
	// or you can use variables:
	int myNumber = { 42 };
	int* my_int_array_ptr2 = new int[myNumber];

	delete[] my_int_array_ptr2;
	delete[] my_int_array_ptr;

	//memory leaks
	//always deallocate allocated objects
	//if you don't you will cause memory leaks

	//Tracing the object lifecycle
	printf("A\n");
	Tracer t3{ "Automatic variable" };
	printf("B\n");
	const auto* t4 = new Tracer{ "Dynamic variable" };
	printf("C\n");

	//Exceptions:
	Groucho groucho;
	try {
		groucho.forget(0xC0DE);
		groucho.forget(0xFACE);
		groucho.forget(0xC0FFEE);
	}
	catch (const std::runtime_error & e) {
		printf("exception caught with message: %s\n", e.what());
	}
	//stdlib exception classses





}