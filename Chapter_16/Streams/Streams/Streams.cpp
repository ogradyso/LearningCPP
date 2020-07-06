#define CATCH_CONFIG_MAIN
#include "catch.h"

#include <string>
#include <sstream>

TEST_CASE("ostringstream produces strings with str") {
	std::ostringstream ss;
	ss << "By Grabthar's hammer, ";
	ss << "by the suns of Worvan. ";
	ss << "You shall be avenged.";
	const auto lazarus = ss.str();

	ss.str("I am Groot.");
	const auto groot = ss.str();

	REQUIRE(lazarus == "By Grabthar's hammer,"
		" by the suns of Worvan. You shall be avenged.");
	REQUIRE(groot == "I am Groot.");

}

TEST_CASE("istringstream supports contruction from a string") {
	std::string numbers("1 2.23606 2");
	std::istringstream ss{ numbers };
	int a;
	float b, c, d;
	ss >> a;
	ss >> b;
	ss >> c;
	REQUIRE(a == 1);
	REQUIRE(b == Approx(2.23606));
	REQUIRE(c == Approx(2));
	REQUIRE_FALSE(ss >> d);
}

TEST_CASE("stringstream supports all string stream operations") {
	std::stringstream ss;
	ss << "Zed's DEAD";

	std::string who;
	ss >> who;
	int what;
	ss >> std::hex >> what;

	REQUIRE(who == "Zed's");
	REQUIRE(what == 0xdead);
}