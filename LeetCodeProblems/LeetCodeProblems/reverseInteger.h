#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"

// includes for Leet submission:
#include <string>


/*
Given a 32 - bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output : 321
Example 2 :

Input : -123
Output : -321
Example 3 :

Input : 120
Output : 21
Note :
Assume we are dealing with an environment which could only store integers within the 32 - bit signed integer range : [−231, 231 − 1] .
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

using namespace std;

class Solution {
public:
    int reverseInteger(int x) {
        bool polarity = x > 0; 
        string numFrom = to_string(x);
        string numTo{};
        char charToPush{};
        charToPush = numFrom[numFrom.end()]
        numTo.push_back(numFrom.end());

        return{};
    }

};

Solution mySolution{};

TEST_CASE("reverseInteger ") {
    SECTION("passess the initial examples") {
        int numberInput1{321};
        int answer1{123};
        REQUIRE(mySolution.reverseInteger(numberInput1) == answer1);
        int numberInput2{ -321 };
        int answer2{ -123 };
        REQUIRE(mySolution.reverseInteger(numberInput2) == answer2);
        int numberInput3{ 120 };
        int answer3{ 21 };
        REQUIRE(mySolution.reverseInteger(numberInput3) == answer3);
    }
    SECTION("returns empty vector if nums is empty") {
        int numberInput4{0};
        int answer4 = {0};
        REQUIRE(mySolution.reverseInteger(numberInput4) == answer4);
        int numberInput5{};
        int answer5 = {};
        REQUIRE(mySolution.reverseInteger(numberInput5) == answer5);
    }
    SECTION("works with integer consisting of the same number or a pattern") {
        int numberInput6 = {1111};
        int answer6 = {1111};
        REQUIRE(mySolution.reverseInteger(numberInput6) == answer6);
        int numberInput7 = { 202020 };
        int answer7 = { 202020 };
        REQUIRE(mySolution.reverseInteger(numberInput7) == answer7);
    }
    SECTION("returns 0 with overflow") {
        int numberInput8 = {1'463'847'422};
        int answer8 = {0};
        REQUIRE(mySolution.reverseInteger(numberInput8) == answer8);
        int numberInput9 = { -1'463'847'422 };
        int answer9 = { 0 };
        REQUIRE(mySolution.reverseInteger(numberInput9) == answer9);
    }
}