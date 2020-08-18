#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <vector>

//Given a sorted array nums, remove the duplicates in - place such that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this by modifying the input array in - place with O(1) extra memory.
//
//Example 1:
//
//Given nums = [1, 1, 2],
//
//Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
//
//It doesn't matter what you leave beyond the returned length.
//Example 2:
//
//Given nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4],
//
//Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
//
//It doesn't matter what values are set beyond the returned length.
//Clarification:
//
//Confused why the returned value is an integer but your answer is an array ?
//
//Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
//
//Internally you can think of this :
//
//    // nums is passed in by reference. (i.e., without making a copy)
//    int len = removeDuplicates(nums);
//
//// any modification to nums in your function would be known by the caller.
//// using the length returned by your function, it prints the first len elements.
//for (int i = 0; i < len; i++) {
//    print(nums[i]);
//}

class Solution {
public:
    int removeDuplicates_submitted(std::vector<int>& nums) {
        std::vector<int>::iterator numsIter = nums.begin();
        std::vector<int>::iterator numToErase = nums.begin();
        for (size_t i = 1; i < nums.size(); i++) {
            numsIter++;
            if (nums[i] == nums[i- 1]) {
                numToErase = numsIter;
                numsIter--;
                i--;
                nums.erase(numToErase);
            }
        }
        int arrSize = nums.size();
        return {arrSize};
    }
    int removeDuplicates_unique(std::vector<int>& nums) {
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

Solution mySolution{};

TEST_CASE("removeDuplicates ") {
    SECTION("passess the initial examples") {
        std::vector<int> nums1 = {1,1,2};
        int answer1 = {2};
        REQUIRE(mySolution.removeDuplicates(nums1) == answer1);
        std::vector<int> nums2 = { 0,0,1,1,1,2,2,3,3,4 };
        int answer2 = { 5 };
        REQUIRE(mySolution.removeDuplicates(nums2) == answer2);
    }
    SECTION("empty vector") {
        std::vector<int> nums3 = { };
        int answer3 = 0;
        REQUIRE(mySolution.removeDuplicates(nums3) == answer3);
        std::vector<int> nums4 = { 0 };
        int answer4 = 1;
        REQUIRE(mySolution.removeDuplicates(nums4) == answer4);
        std::vector<int> nums5 = { 1,1,1,1,1,1,1,1 };
        int answer5 = 1;
        REQUIRE(mySolution.removeDuplicates(nums5) == answer5);
    }
}

