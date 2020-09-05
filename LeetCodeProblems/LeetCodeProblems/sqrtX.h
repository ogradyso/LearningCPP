#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <iostream>

//Implement int sqrt(int x).
//
//Computeand return the square root of x, where x is guaranteed to be a non - negative integer.
//
//Since the return type is an integer, the decimal digits are truncatedand only the integer part of the result is returned.
//
//Example 1:
//
//Input: 4
//Output : 2
//Example 2 :
//
//    Input : 8
//    Output : 2
//    Explanation : The square root of 8 is 2.82842..., and since
//    the decimal part is truncated, 2 is returned.

using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        size_t num{0};
        while (num * num <= x) {
            num++;
        }
        int ans = static_cast<int>(num-1);
        return {ans};
    }
};


Solution mySolution{};

TEST_CASE("searchInsert ") {
    SECTION("passess the initial examples") {
        int input{ 4 };
        int answer{ 2 };
        REQUIRE(mySolution.mySqrt(input) == answer);
        int input1{ 8 };
        int answer1{ 2 };
        REQUIRE(mySolution.mySqrt(input1) == answer1);
        int input2{ 9 };
        int answer2{ 3 };
        REQUIRE(mySolution.mySqrt(input2) == answer2);
        int input3{ 2147395600 };
        int answer3{ 46'340 };
        REQUIRE(mySolution.mySqrt(input3) == answer3);
    }
}
