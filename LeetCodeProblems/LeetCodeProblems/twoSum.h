#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <iostream>
#include <vector>
#include <map>

using namespace::std;

/*Problem description:
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

//BRUTE FORCE SOLUTION:
class Solution {
public:
    vector<int> twoSumBruteForce(vector<int>& nums, int target) {
        int thisSum;
        for (int i{}; i < nums.size(); i++)
            for (int j{}; j < nums.size(); j++)
                if (j != i) {
                    thisSum = nums[i] + nums[j];
                    if (thisSum == target) {
                        return{ i,j };
                    }
                }
        return {};
    }

    vector<int> twoSumHashMap(vector<int>& nums, int target) {
        std::map<int, int> valDiffsDictionary;
        int difference;
        for (int i = 0; i < nums.size(); i++)
        {
            difference = target - nums[i];
            if (valDiffsDictionary.find(difference) != valDiffsDictionary.end())
            {
                return { valDiffsDictionary[difference],i };
            } 
            else 
            {
                if (valDiffsDictionary.find(nums[i]) == valDiffsDictionary.end())
                {
                    valDiffsDictionary.insert({ nums[i],i });
                }
            }
        }
        return { };
    }
};

Solution mySolution{};

TEST_CASE("twoSumBruteForce ") {
    SECTION("passess the initial example") {
        vector<int> nums1 = { 2, 7, 11, 15 };
        vector<int> answer1 = { 0,1 };
        REQUIRE(mySolution.twoSumBruteForce(nums1, 9) == answer1);
    }
    SECTION("returns empty vector if nums is empty") {
        vector<int> nums2;
        vector<int> answer2 = {  };
        REQUIRE(mySolution.twoSumBruteForce(nums2, 9) == answer2);
    }
    SECTION("works with unsorted vectors") {
        vector<int> nums3 = { 1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,3,3,34,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,5,5, };
        vector<int> answer3 = { 12,19 };
        REQUIRE(mySolution.twoSumBruteForce(nums3, 37) == answer3);
    }
    SECTION("twoSum with no answer") {
        vector<int> nums4 = { 1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,5,5, };
        vector<int> answer4 = {};
        REQUIRE(mySolution.twoSumBruteForce(nums4, 37) == answer4);
    }
}

TEST_CASE("twoSumDifferenceSearch ") {
    SECTION("passess the initial example") {
        vector<int> nums1 = { 2, 7, 11, 15 };
        vector<int> answer1 = { 0,1 };
        REQUIRE(mySolution.twoSumHashMap(nums1, 9) == answer1);
    }
    SECTION("returns empty vector if nums is empty") {
        vector<int> nums2;
        vector<int> answer2 = {  };
        REQUIRE(mySolution.twoSumHashMap(nums2, 9) == answer2);
    }
    SECTION("works with unsorted vectors") {
        vector<int> nums3 = { 1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,3,3,34,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,5,5, };
        vector<int> answer3 = { 12,19 };
        REQUIRE(mySolution.twoSumHashMap(nums3, 37) == answer3);
    }
    SECTION("twoSum with no answer") {
        vector<int> nums4 = { 1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,5,5, };
        vector<int> answer4 = {};
        REQUIRE(mySolution.twoSumHashMap(nums4, 37) == answer4);
    }
}