#define CATCH_CONFIG_MAIN
#include "catch.h"

#include <array>

std::array<int, 10> static_array;

TEST_CASE("std::array") {
	REQUIRE(static_array[0] ==0);

	SECTION("uninitialized without braced initializers") {
		std::array<int, 10> local_array;
		REQUIRE(local_array[0] != 0);
	}

	SECTION("initialized with braced initializers") {
		std::array<int, 10> local_array{ 1,1,2,3 };
		REQUIRE(local_array[0] == 1);
		REQUIRE(local_array[1] == 1);
		REQUIRE(local_array[2] == 2);
		REQUIRE(local_array[3] == 3);
		REQUIRE(local_array[4] == 0);
	}
}

TEST_CASE("std::array access") {
	std::array<int, 4> fib{ 1,1,0,3 };

	SECTION("operator[] can get and set elements") {
		fib[2] = 2;
		REQUIRE(fib[2] == 2);
		// fib[4] = 5; //throws an error
	}
	SECTION("at() can get and set elements") {
		fib.at(2) = 2;
		REQUIRE(fib.at(2) == 2);
		REQUIRE_THROWS_AS(fib.at(4), std::out_of_range);
	}
	SECTION("get can get and set elements") {
		std::get<2>(fib) = 2;
		REQUIRE(std::get<2>(fib) == 2);
		//std::get<4>(fib);
	}
}

