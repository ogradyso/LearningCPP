#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <iostream>

//You are climbing a stair case.It takes n steps to reach to the top.
//
//Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top ?
//
//Example 1 :
//
//    Input : 2
//    Output : 2
//    Explanation : There are two ways to climb to the top.
//    1. 1 step + 1 step
//    2. 2 steps
//    Example 2 :
//
//    Input : 3
//    Output : 3
//    Explanation : There are three ways to climb to the top.
//    1. 1 step + 1 step + 1 step
//    2. 1 step + 2 steps
//    3. 2 steps + 1 step
//
//
//    Constraints :
//
//1 <= n <= 45

using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        /*if (n <= 3) {
            return n;
        }
        else {
            return  (climbStairs(n - 1) + climbStairs(n - 2));
        }*/
        if (n == 1) {
            return 1;
        }
        
    }
};


Solution mySolution{};

TEST_CASE("searchInsert ") {
    SECTION("passess the initial examples") {
        int input{ 2 };
        int answer{ 2 };
        REQUIRE(mySolution.climbStairs(input) == answer);
        int input1{ 3 };
        int answer1{ 3 };
        REQUIRE(mySolution.climbStairs(input1) == answer1);
        int input2{ 4 };
        int answer2{ 5 };
        REQUIRE(mySolution.climbStairs(input2) == answer2);
        int input3{ 5 };
        int answer3{ 8 };
        REQUIRE(mySolution.climbStairs(input3) == answer3);
        int input4{ 10 };
        int answer4{ 89 };
        REQUIRE(mySolution.climbStairs(input4) == answer4);
    }
};
