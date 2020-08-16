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
        return {false};
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

//TEST_CASE("isPalindrome ") {
//    SECTION("passess the initial examples") {
//        int numberInput1{121};
//        bool answer1{ true };
//        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput1) == answer1);
//        int numberInput2{ -121 };
//        bool answer2{ false};
//        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput2) == answer2);
//        int numberInput3{ 10 };
//        bool answer3{ false };
//        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput3) == answer3);
//    }
//    SECTION("returns empty vector if nums is empty") {
//        int numberInput4{ 0 };
//        bool answer4 = { true };
//        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput4) == answer4);
//        int numberInput5{};
//        int answer5 = {true};
//        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput5) == answer5);
//    }
//    SECTION("works with integer consisting of the same number or a pattern") {
//        int numberInput6 = { 1111 };
//        bool answer6 = { true };
//        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput6) == answer6);
//        int numberInput7 = { 202020 };
//        bool answer7 = { false };
//        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput7) == answer7);
//    }
//    SECTION("works with odd numbers") {
//        int numberInput6 = { 32123 };
//        bool answer6 = { true };
//        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput6) == answer6);
//        int numberInput7 = { 321123 };
//        bool answer7 = { true };
//        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput7) == answer7);
//        int numberInput8 = { 320023 };
//        bool answer8 = { true };
//        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput8) == answer8);
//    }
//    SECTION("returns false with overflow") {
//        int numberInput8 = { 1'463'847'422 };
//        int answer8 = { false };
//        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput8) == answer8);
//        int numberInput9 = { -1'463'847'422 };
//        int answer9 = { false };
//        REQUIRE(mySolution.isPalindromeLeetAnswer(numberInput9) == answer9);
//    }
//}