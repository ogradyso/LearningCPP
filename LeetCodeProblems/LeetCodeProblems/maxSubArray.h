#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"

//Given an integer array nums, find the contiguous subarray(containing at least one number) which has the largest sumand return its sum.
//
//Example:
//
//Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4] ,
//Output : 6
//Explanation : [4, -1, 2, 1] has the largest sum = 6.
//Follow up :
//
//If you have figured out the O(n) solution, try coding another solution using the divideand conquer approach, which is more subtle.

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return {};
    }
};


Solution mySolution{};

TEST_CASE("searchInsert ") {
    SECTION("passess the initial examples") {
        std::vector<int> input{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
        int answer{ 6 };
        REQUIRE(mySolution.maxSubArray(input) == answer);

    }
}
