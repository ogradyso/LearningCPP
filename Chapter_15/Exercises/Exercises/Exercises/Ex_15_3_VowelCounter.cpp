//#define CATCH_CONFIG_MAIN
//#include "catch.h"
//
//#include <cstdio>
//#include <cstdint>
//#include <string>
//
//
//size_t count_vowels(std::string_view userInput) {
//	size_t result{};
//	std::string vowelList{"aeiouy"};
//	for (auto letter : userInput)
//		if (vowelList.find(letter)!=std::string::npos) result++;
//	return result;
//}
//
//TEST_CASE("count_vowels ") {
//	SECTION("counts vowels in user input ") {
//		std::string input_toTest("racecar");
//		REQUIRE(count_vowels(input_toTest) == 3);
//	}
//	SECTION("returns false for non-palindromes ") {
//		std::string input_toTest("dance type");
//		REQUIRE(count_vowels(input_toTest) == 4);
//	}
//}
