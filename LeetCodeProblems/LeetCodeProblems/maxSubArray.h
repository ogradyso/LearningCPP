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

#include <numeric>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int absMax = INT_MIN;
        int max_to_i = 0;

        if (nums.size() == 0) return 0;
        for (int i = 0; i < nums.size(); i++)
        {
            max_to_i = max_to_i + nums[i];
            if (absMax < max_to_i)
                absMax = max_to_i;

            if (max_to_i < 0)
                max_to_i = 0;
        }
        return absMax;
    }
};


Solution mySolution{};

TEST_CASE("searchInsert ") {
    SECTION("passess the initial examples") {
        std::vector<int> input{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
        int answer{ 6 };
        REQUIRE(mySolution.maxSubArray(input) == answer);
    }
    
    SECTION("passess the initial examples") {
        std::vector<int> input2{  };
        int answer2{ 0 };
        REQUIRE(mySolution.maxSubArray(input2) == answer2);
    }

    SECTION("passess the initial examples") {
        std::vector<int> input3{ 1,0,0,-2,0,0,3 };
        int answer3{ 3 };
        REQUIRE(mySolution.maxSubArray(input3) == answer3);
    }
    SECTION("passess the initial examples") {
        std::vector<int> input4{ 1,0,0,-2,0,0,1 };
        int answer4{ 1 };
        REQUIRE(mySolution.maxSubArray(input4) == answer4);
    }
}
