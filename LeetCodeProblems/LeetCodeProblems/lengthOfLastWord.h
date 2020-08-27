#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <iostream>
//Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.
//
//If the last word does not exist, return 0.
//
//Note: A word is defined as a maximal substring consisting of non-space characters only.
//
//Example:
//
//Input: "Hello World"
//Output: 5

using namespace std;
#include <regex>
#include <limits>
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0) return{0};
        regex pat{ R"(\s+(\w+))" };
        sregex_iterator p(s.begin(), s.end(), pat);
        string lastWord = (*p)[(*p).size()-1];
        if (lastWord.empty()) {
            return{ static_cast<int>(s.size()) };
        }
        return { static_cast<int>(lastWord.size()) };
    }
};


Solution mySolution{};

TEST_CASE("searchInsert ") {
    SECTION("passess the initial examples") {
        std::string input{ "Hello World!" };
        int answer{ 5 };
        REQUIRE(mySolution.lengthOfLastWord(input) == answer);
    }

    /*SECTION("passess the initial examples") {
        std::string input2{  };
        int answer2{ 0 };
        REQUIRE(mySolution.lengthOfLastWord(input2) == answer2);
    }*/

    /*SECTION("passess the initial examples") {
        std::string input3{"Hallibut"};
        int answer3{ 8 };
        REQUIRE(mySolution.lengthOfLastWord(input3) == answer3);
    }*/
    SECTION("passess the initial examples") {
        std::string input4{ "When I was a young warthog!" };
        int answer4{ 7 };
        REQUIRE(mySolution.lengthOfLastWord(input4) == answer4);
    }
}