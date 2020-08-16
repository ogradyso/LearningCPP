#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <string>
#include <vector>

// includes for Leet submission:
#include <algorithm>

//Write a function to find the longest common prefix string amongst an array of strings.
//
//If there is no common prefix, return an empty string "".
//
//Example 1:
//
//Input: ["flower", "flow", "flight"]
//Output : "fl"
//Example 2 :
//
//    Input : ["dog", "racecar", "car"]
//    Output : ""
//    Explanation : There is no common prefix among the input strings.
//    Note :
//
//    All given inputs are in lowercase letters a - z.

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return{};
        if (strs.size() == 1) return{ strs[0] };
        std::string foundPrefix;
        std::string firstWord{ strs[0] };
        for (auto& letter : firstWord) {
            for (std::string& word : strs) {
                if (word.front() != letter) {
                    return foundPrefix;
                }
                else {
                    word.erase(word.cbegin(),word.cbegin()+1);
                }
            }
            foundPrefix.push_back(letter);
        }
        return{foundPrefix};
    }

};

Solution mySolution{};

TEST_CASE("romanToInt ") {
    SECTION("passess the initial examples") {
        std::vector<std::string> strVectorInput1{ "flower", "flow", "flight" };
        std::string answer1{ "fl" };
        REQUIRE(mySolution.longestCommonPrefix(strVectorInput1) == answer1);
        std::vector<std::string> strVectorInput2{ "dog", "racecar", "car" };
        std::string answer2{ "" };
        REQUIRE(mySolution.longestCommonPrefix(strVectorInput2) == answer2);
    }
    SECTION("handles empty and single word vectors") {
        std::vector<std::string> strVectorInput3{ "flower" };
        std::string answer3{ "flower" };
        REQUIRE(mySolution.longestCommonPrefix(strVectorInput3) == answer3);
        std::vector<std::string> strVectorInput4{ };
        std::string answer4{ };
        REQUIRE(mySolution.longestCommonPrefix(strVectorInput4) == answer4);
    }
    SECTION("additional tests") {
        std::vector<std::string> strVectorInput5{ "flower", "flow", "flight", "fragrance" };
        std::string answer5{ "f" };
        REQUIRE(mySolution.longestCommonPrefix(strVectorInput5) == answer5);
        std::vector<std::string> strVectorInput6{ "carson", "carport", "car" };
        std::string answer6{ "car" };
        REQUIRE(mySolution.longestCommonPrefix(strVectorInput6) == answer6);
        std::vector<std::string> strVectorInput7{ "c", "c"};
        std::string answer7{ "c" };
        REQUIRE(mySolution.longestCommonPrefix(strVectorInput7) == answer7);
    }
}
