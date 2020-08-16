#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"

// includes for Leet submission:
#include <string>


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
    int romanToInt(std::string s) {
        char currentChar;
        int totalVal = 0;
        char lastChar = 'Z';

        if (s.empty()) return {0};
        while (!s.empty())
        {
            currentChar = s.back();
            if (currentChar == 'I') {
                if (lastChar == 'V' || lastChar == 'X') {
                    totalVal = totalVal - 1;
                }
                else {
                    totalVal = totalVal + 1;
                }
            }
            if (currentChar == 'V') totalVal = totalVal + 5;
            if (currentChar == 'X') {
                if (lastChar == 'L' || lastChar == 'C') {
                    totalVal = totalVal - 10;
                }
                else {
                    totalVal = totalVal + 10;
                }
            }
            if (currentChar == 'L') totalVal = totalVal + 50;
            if (currentChar == 'C') {
                if (lastChar == 'D' || lastChar == 'M') {
                    totalVal = totalVal - 100;
                }
                else {
                    totalVal = totalVal + 100;
                }
            }
            if (currentChar == 'D') totalVal = totalVal + 500;
            if (currentChar == 'M') totalVal = totalVal + 1000;
            lastChar = currentChar;
            s.pop_back();
        }
        return{totalVal};
    //I can be placed before V(5) and X(10) to make 4 and 9.
    //X can be placed before L(50) and C(100) to make 40 and 90.
    //C can be placed before D(500) and M(1000) to make 400 and 900.
    }

};

//Solution mySolution{};
//
//TEST_CASE("romanToInt ") {
//    SECTION("passess the initial examples") {
//        std::string numberInput1{ "III" };
//        int answer1{ 3 };
//        REQUIRE(mySolution.romanToInt(numberInput1) == answer1);
//        std::string numberInput2{ "IV" };
//        int answer2{ 4 };
//        REQUIRE(mySolution.romanToInt(numberInput2) == answer2);
//        std::string numberInput3{ "IX" };
//        int answer3{ 9 };
//        REQUIRE(mySolution.romanToInt(numberInput3) == answer3);
//        std::string numberInput4{ "LVIII" };
//        int answer4{ 58 };
//        REQUIRE(mySolution.romanToInt(numberInput4) == answer4);
//        std::string numberInput5{ "MCMXCIV" };
//        int answer5{ 1994 };
//        REQUIRE(mySolution.romanToInt(numberInput5) == answer5);
//        std::string numberInput7{ "MMMCDLXXXII" };
//        int answer7{ 3482 };
//        REQUIRE(mySolution.romanToInt(numberInput7) == answer7);
//        std::string numberInput8{ "MMMMDLXI" };
//        int answer8{ 4561 };
//        REQUIRE(mySolution.romanToInt(numberInput8) == answer8);
//    }
//    SECTION("returns empty vector if nums is empty") {
//        std::string numberInput6{};
//        int answer6 = { 0 };
//        REQUIRE(mySolution.romanToInt(numberInput6) == answer6);
//    }
//}