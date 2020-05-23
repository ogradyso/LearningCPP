#include <cstdio>
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

//static members must be initialized globally:
int RatThing::rat_things_power = 200;

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
}