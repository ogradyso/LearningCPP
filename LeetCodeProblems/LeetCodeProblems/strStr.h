#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <string>
#include <limits>

//Implement strStr().
//
//Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
//Example 1:
//
//Input: haystack = "hello", needle = "ll"
//Output : 2
//Example 2 :
//
//	Input : haystack = "aaaaa", needle = "bba"
//	Output : -1
//	Clarification :
//
//	What should we return when needle is an empty string ? This is a great question to ask during an interview.
//
//	For the purpose of this problem, we will return 0 when needle is an empty string.This is consistent to C's strstr() and Java's indexOf().
//
//
//
//Constraints:
//
//haystack and needle consist only of lowercase English characters.

using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t foundIndex = haystack.find(needle);
        int retVal = static_cast<int>(foundIndex);
        return {retVal};
    }
};


Solution mySolution{};

TEST_CASE("removeDuplicates ") {
    SECTION("passess the initial examples") {
        std::string haystack{ "hello" };
        std::string needle{ "ll" };
        int answer{2};
        REQUIRE(mySolution.strStr(haystack, needle) == answer);
        std::string haystack2{ "aaaaa" };
        std::string needle2{ "bba" };
        int answer2{ -1 };
        REQUIRE(mySolution.strStr(haystack2, needle2) == answer2);
        std::string haystack3{ "empty needle" };
        std::string needle3{ "" };
        int answer3{ 0 };
        REQUIRE(mySolution.strStr(haystack3, needle3) == answer3);
        std::string haystack4{ "empty needle" };
        std::string needle4{ "nee" };
        int answer4{ 6 };
        REQUIRE(mySolution.strStr(haystack4, needle4) == answer4);
        std::string haystack5{ "" };
        std::string needle5{ "nee" };
        int answer5{ -1 };
        REQUIRE(mySolution.strStr(haystack5, needle5) == answer5);
    }
}