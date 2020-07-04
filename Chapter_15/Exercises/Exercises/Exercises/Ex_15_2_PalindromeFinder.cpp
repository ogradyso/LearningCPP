//#define CATCH_CONFIG_MAIN
//#include "catch.h"
//#include <iostream>
//#include <string>
//
//bool is_palindrome(std::string forwardString) {
//	std::string reverseString{};
//	size_t stopNum{};
//	size_t stringEndNum{};
//	stringEndNum = forwardString.size();
//	if (forwardString.size() % 2 == 0){
//		stopNum = forwardString.size() / 2;
//	}
//	else {
//		stopNum = (forwardString.size() / 2);
//	}
//	while (stopNum > 0) {
//		reverseString.append(1, forwardString[forwardString.size()-1]);
//		forwardString.pop_back();
//		stopNum--;
//	}
//	if (stringEndNum % 2 == 1) {
//		reverseString.append(1, forwardString[forwardString.size() - 1]);
//	}
//	return reverseString == forwardString;
//}
//
//TEST_CASE("is_palindrome ") {
//	SECTION("finds palindromes ") {
//		std::string input_toTest("racecar");
//		REQUIRE(is_palindrome(input_toTest) == true);
//	}
//	SECTION("returns false for non-palindromes ") {
//		std::string input_toTest("dance");
//		REQUIRE(is_palindrome(input_toTest) == false);
//	}
//}
