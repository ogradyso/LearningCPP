#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <iostream>
//Given a non - empty array of digits representing a non - negative integer, increment one to the integer.
//
//The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
//
//You may assume the integer does not contain any leading zero, except the number 0 itself.
//
//
//
//Example 1:
//
//Input: digits = [1, 2, 3]
//Output : [1, 2, 4]
//Explanation : The array represents the integer 123.
//Example 2 :
//
//    Input : digits = [4, 3, 2, 1]
//    Output : [4, 3, 2, 2]
//    Explanation : The array represents the integer 4321.
//    Example 3 :
//
//    Input : digits = [0]
//    Output : [1]
//
//
//    Constraints :
//
//    1 <= digits.length <= 100
//    0 <= digits[i] <= 9
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.back() < 9) {
            digits.back() = digits.back() + 1;
            return { digits };
        }
        else if (digits.size() == 1 && digits.back() == 9) {
            return {1,0};
        }
        else {
            vector<int> nextIteration = digits;
            nextIteration.pop_back();
            nextIteration = plusOne(nextIteration);
            nextIteration.push_back(0);
            return { nextIteration };
        }
    }
};


Solution mySolution{};

TEST_CASE("searchInsert ") {
    SECTION("passess the initial examples") {
        std::vector input{ 1,2,3 };
        std::vector answer{ 1,2,4 };
        REQUIRE(mySolution.plusOne(input) == answer);
        std::vector input2{ 4,3,2,1 };
        std::vector answer2{ 4,3,2,2 };
        REQUIRE(mySolution.plusOne(input2) == answer2);
        std::vector input3{ 0 };
        std::vector answer3{ 1 };
        REQUIRE(mySolution.plusOne(input3) == answer3);
        std::vector input4{ 9 };
        std::vector answer4{ 1,0 };
        REQUIRE(mySolution.plusOne(input4) == answer4);
        std::vector input5{ 9,9 };
        std::vector answer5{ 1,0,0 };
        REQUIRE(mySolution.plusOne(input5) == answer5);
        std::vector input6{ 9,9,9 };
        std::vector answer6{ 1,0,0,0 };
        REQUIRE(mySolution.plusOne(input6) == answer6);
        std::vector input7{ 9,9,9,9 };
        std::vector answer7{ 1,0,0,0,0 };
        REQUIRE(mySolution.plusOne(input7) == answer7);
    }
}
