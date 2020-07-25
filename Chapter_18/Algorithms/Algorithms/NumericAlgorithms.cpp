#define CATCH_CONFIG_MAIN
#include "catch.h"

using namespace std;

#include <functional>
TEST_CASE("plus") {
	plus<short> adder;
	REQUIRE(3 == adder(1, 2));
	REQUIRE(3 == plus<short>{}(1, 2));
}

