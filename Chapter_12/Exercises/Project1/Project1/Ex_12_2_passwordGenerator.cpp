#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <iostream>
#include <ctype.h>
#include <string>
#include <random>

using namespace std;

char pwGenerator() {
	char printableCharacters[]{"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"};
	random_device randomGen{};
	uniform_int_distribution<int> int_dist{0, 61};
	char passwordChar = printableCharacters[int_dist(randomGen)];
	cout << passwordChar;
	return passwordChar;
}

TEST_CASE("PW generator generates alphanumeric output") {
	long pwLength = 8;

	for (long character{ 0 }; character < pwLength; character++) {
		auto letter = pwGenerator();
		REQUIRE(isalnum(letter));
	}
}