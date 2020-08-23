#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <string>

//The count - and -say sequence is the sequence of integers with the first five terms as following :
//
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//
//Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count - and -say sequence.You can do so recursively, 
//in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.
//
//Note: Each term of the sequence of integers will be represented as a string.
//
//
//
//Example 1 :
//
//	Input : 1
//	Output : "1"
//	Explanation : This is the base case.
//	Example 2:
//
//	Input: 4
//		Output : "1211"
//		Explanation : For n = 3 the term was "21" in which we have two groups "2" and "1", "2" can be read as "12" 
//		which means frequency = 1 and value = 2, the same way "1" is read as "11", so the answer is the concatenation 
//		of "12" and "11" which is "1211".

using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "0";
        if (n == 1) return "1";
        string previousStr = countAndSay(n - 1);
        string currentStr{};
        int strIterator{ 0 };
        int currentNum = { 0 };
        size_t strEnd = previousStr.size();
        while (strIterator != strEnd) {
            int count{ 0 };
            
            while (previousStr[strIterator] == previousStr[currentNum]) {
                if (strIterator != strEnd) {
                    count++;
                    strIterator++;
                }
            }
            currentStr += std::to_string(count);

            strIterator--;
            currentStr += previousStr[strIterator];
            strIterator++;
            currentNum = strIterator;
        }
        return {currentStr};
        /*if (n == 1) return "1";
        if (n == 2)  return "11";
        string s = countAndSay(n - 1), res = "";
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (j < s.size() and s[j] == s[i]) j++;
            res += to_string(j - i) + s[i];
            i = j;
        }
        return res;*/
    }
};


Solution mySolution{};

TEST_CASE("searchInsert ") {
    SECTION("passess the initial examples") {
        int input{ 1 };
        std::string answer{ "1" };
        REQUIRE(mySolution.countAndSay(input) == answer);
        int input2{ 2 };
        std::string answer2{ "11" };
        REQUIRE(mySolution.countAndSay(input2) == answer2);
        int input3{ 3 };
        std::string answer3{ "21" };
        REQUIRE(mySolution.countAndSay(input3) == answer3);
        int input4{ 4 };
        std::string answer4{ "1211" };
        REQUIRE(mySolution.countAndSay(input4) == answer4);
        int input5{ 5 };
        std::string answer5{ "111221" };
        REQUIRE(mySolution.countAndSay(input5) == answer5);
        int input6{ 6 };
        std::string answer6{ "312211" };
        REQUIRE(mySolution.countAndSay(input6) == answer6);
        int input7{ 7 };
        std::string answer7{ "13112221" };
        REQUIRE(mySolution.countAndSay(input7) == answer7);
        int input8{ 8 };
        std::string answer8{ "1113213211" };
        REQUIRE(mySolution.countAndSay(input8) == answer8);
        int input9{ 9 };
        std::string answer9{ "31131211131221" };
        REQUIRE(mySolution.countAndSay(input9) == answer9);
        int input10{ 10 };
        std::string answer10{ "13211311123113112211" };
        REQUIRE(mySolution.countAndSay(input10) == answer10);
        int input11{ 11 };
        std::string answer11{ "11131221133112132113212221" };
        REQUIRE(mySolution.countAndSay(input11) == answer11);

    }
}

