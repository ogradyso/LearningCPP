#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <vector>
#include <algorithm>
#include <limits>


//Given a sorted arrayand a target value, return the index if the target is found.If not, return the index where it would be if it 
//were inserted in order.
//
//You may assume no duplicates in the array.
//
//Example 1:
//
//Input: [1, 3, 5, 6] , 5
//Output : 2
//Example 2 :
//
//	Input : [1, 3, 5, 6] , 2
//	Output : 1
//	Example 3 :
//
//	Input : [1, 3, 5, 6] , 7
//	Output : 4
//	Example 4 :
//
//	Input : [1, 3, 5, 6] , 0
//	Output : 0

using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto result = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (result <= std::numeric_limits<int>::max()) {
            int retVal = static_cast<int>(result);
            return{ retVal };
        }
        else {
            return{};
        }
    }
};


Solution mySolution{};

TEST_CASE("searchInsert ") {
    SECTION("passess the initial examples") {
        std::vector<int> input{ 1,3,5,6 };
        int target{ 5 };
        int answer{ 2 };
        REQUIRE(mySolution.searchInsert(input, target) == answer);
        std::vector<int> input2{ 1,3,5,6 };
        int target2{ 2 };
        int answer2{ 1 };
        REQUIRE(mySolution.searchInsert(input2, target2) == answer2);
        std::vector<int> input3{ 1,3,5,6 };
        int target3{ 7 };
        int answer3{ 4 };
        REQUIRE(mySolution.searchInsert(input3, target3) == answer3);
        std::vector<int> input4{ 1,3,5,6 };
        int target4{ 0 };
        int answer4{ 0 };
        REQUIRE(mySolution.searchInsert(input4, target4) == answer4);
    }
}