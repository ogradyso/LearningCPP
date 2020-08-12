#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"

// includes for Leet submission:


//Determine whether an integer is a palindrome.An integer is a palindrome when it reads the same backward as forward.
//
//Example 1:
//
//Input: 121
//Output : true
//Example 2 :
//
//    Input : -121
//    Output : false
//    Explanation : From left to right, it reads - 121. From right to left, it becomes 121 - .Therefore it is not a palindrome.
//    Example 3 :
//
//    Input : 10
//    Output : false
//    Explanation : Reads 01 from right to left.Therefore it is not a palindrome.
//    Follow up :
//
//Coud you solve it without converting the integer to a string ?

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x > 0) 
        { 
            int ones = x % 10;
            x /= 10;
        }
        return {false};
    }

};

Solution mySolution{};

TEST_CASE("isPalindrome ") {
    SECTION("passess the initial examples") {
        int numberInput1{121};
        bool answer1{ true };
        REQUIRE(mySolution.isPalindrome(numberInput1) == answer1);
        int numberInput2{ -121 };
        bool answer2{ false};
        REQUIRE(mySolution.isPalindrome(numberInput2) == answer2);
        int numberInput3{ 10 };
        bool answer3{ false };
        REQUIRE(mySolution.isPalindrome(numberInput3) == answer3);
    }
    SECTION("returns empty vector if nums is empty") {
        int numberInput4{ 0 };
        bool answer4 = { true };
        REQUIRE(mySolution.isPalindrome(numberInput4) == answer4);
        int numberInput5{};
        int answer5 = {};
        REQUIRE(mySolution.isPalindrome(numberInput5) == answer5);
    }
    SECTION("works with integer consisting of the same number or a pattern") {
        int numberInput6 = { 1111 };
        bool answer6 = { true };
        REQUIRE(mySolution.isPalindrome(numberInput6) == answer6);
        int numberInput7 = { 202020 };
        bool answer7 = { false };
        REQUIRE(mySolution.isPalindrome(numberInput7) == answer7);
    }
    SECTION("works with odd numbers") {
        int numberInput6 = { 32123 };
        bool answer6 = { true };
        REQUIRE(mySolution.isPalindrome(numberInput6) == answer6);
        int numberInput7 = { 321123 };
        bool answer7 = { true };
        REQUIRE(mySolution.isPalindrome(numberInput7) == answer7);
        int numberInput8 = { 320023 };
        bool answer8 = { true };
        REQUIRE(mySolution.isPalindrome(numberInput8) == answer8);
    }
}