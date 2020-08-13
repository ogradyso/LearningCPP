#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"

// includes for Leet submission:



//Roman numerals are represented by seven different symbols : I, V, X, L, C, Dand M.
//
//Symbol       Value
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
//
//Roman numerals are usually written largest to smallest from left to right.However, the numeral for four is not IIII.Instead, the number four is written as IV.Because the one is before the five we subtract it making four.The same principle applies to the number nine, which is written as IX.There are six instances where subtraction is used :
//
//I can be placed before V(5) and X(10) to make 4 and 9.
//X can be placed before L(50) and C(100) to make 40 and 90.
//C can be placed before D(500) and M(1000) to make 400 and 900.
//Given a roman numeral, convert it to an integer.Input is guaranteed to be within the range from 1 to 3999.
//
//Example 1:
//
//Input: "III"
//Output : 3
//Example 2 :
//
//	Input : "IV"
//	Output : 4
//	Example 3 :
//
//	Input : "IX"
//	Output : 9
//	Example 4 :
//
//	Input : "LVIII"
//	Output : 58
//	Explanation : L = 50, V = 5, III = 3.
//	Example 5 :
//
//	Input : "MCMXCIV"
//	Output : 1994
//	Explanation : M = 1000, CM = 900, XC = 90 and IV = 4.

class Solution {
public:
    bool isPalindrome(int x) {
        int nextDigit;
        int reversed = 0;
        int copyX = x;
        if (x >= 0)
        {
            while (x > 0)
            {
                nextDigit = x % 10;
                x /= 10;
                if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && nextDigit > 7)) return false;
                if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && nextDigit < -8)) return false;
                reversed = reversed * 10 + nextDigit;
            }
            if (copyX == reversed)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return { false };
    }
    bool isPalindromeLeetAnswer(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int reversed = 0;
        while (x > reversed)
        {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        if (x == reversed || x == (reversed /= 10)) {
            return{ true };
        }
        else {
            return { false };
        }
    }

};

Solution mySolution{};

TEST_CASE("isPalindrome ") {
    SECTION("passess the initial examples") {
        int numberInput1{ 121 };
        bool answer1{ true };
        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput1) == answer1);
        int numberInput2{ -121 };
        bool answer2{ false };
        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput2) == answer2);
        int numberInput3{ 10 };
        bool answer3{ false };
        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput3) == answer3);
    }
    SECTION("returns empty vector if nums is empty") {
        int numberInput4{ 0 };
        bool answer4 = { true };
        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput4) == answer4);
        int numberInput5{};
        int answer5 = { true };
        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput5) == answer5);
    }
    SECTION("works with integer consisting of the same number or a pattern") {
        int numberInput6 = { 1111 };
        bool answer6 = { true };
        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput6) == answer6);
        int numberInput7 = { 202020 };
        bool answer7 = { false };
        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput7) == answer7);
    }
    SECTION("works with odd numbers") {
        int numberInput6 = { 32123 };
        bool answer6 = { true };
        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput6) == answer6);
        int numberInput7 = { 321123 };
        bool answer7 = { true };
        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput7) == answer7);
        int numberInput8 = { 320023 };
        bool answer8 = { true };
        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput8) == answer8);
    }
    SECTION("returns false with overflow") {
        int numberInput8 = { 1'463'847'422 };
        int answer8 = { false };
        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput8) == answer8);
        int numberInput9 = { -1'463'847'422 };
        int answer9 = { false };
        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput9) == answer9);
    }
}