#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <vector>

//Given an array nums and a value val, remove all instances of that value in - place and return the new length.
//
//Do not allocate extra space for another array, you must do this by modifying the input array in - place with O(1) extra memory.
//
//The order of elements can be changed.It doesn't matter what you leave beyond the new length.
//
//Example 1:
//
//Given nums = [3, 2, 2, 3], val = 3,
//
//Your function should return length = 2, with the first two elements of nums being 2.
//
//It doesn't matter what you leave beyond the returned length.
//Example 2:
//
//Given nums = [0, 1, 2, 2, 3, 0, 4, 2], val = 2,
//
//Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.
//
//Note that the order of those five elements can be arbitrary.
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
//    int len = removeElement(nums, val);
//
//// any modification to nums in your function would be known by the caller.
//// using the length returned by your function, it prints the first len elements.
//for (int i = 0; i < len; i++) {
//    print(nums[i]);
//}

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        std::vector<int>::iterator numsIter = nums.begin();
        std::vector<int>::iterator numToErase = nums.begin();
        int i = 0;
        while (i < nums.size()) {
            numToErase = numsIter;
            if (nums[i] == val) {
                nums.erase(numToErase);
                numsIter = nums.begin();
                i = 0;
            }
            else
            {
                numsIter++;
                i++;
            };
        }
        if (nums.size() == 1 && nums[0] == val) {
            numsIter = nums.begin();
            nums.erase(numsIter);
        }
        return nums.size();
    }
};


Solution mySolution{};

TEST_CASE("removeDuplicates ") {
    SECTION("passess the initial examples") {
        std::vector<int> nums1 = { 3,2,2,3};
        int val = {3};
        int answer1 = { 2 };
        REQUIRE(mySolution.removeElement(nums1,val) == answer1);
        std::vector<int> nums2 = { 0, 1, 2, 2, 3, 0, 4, 2 };
        int answer2 = { 5 };
        int val2 = { 2 };
        REQUIRE(mySolution.removeElement(nums2,val2) == answer2);
        std::vector<int> nums3 = { 3, 3 };
        int answer3 = {  };
        int val3 = { 3 };
        REQUIRE(mySolution.removeElement(nums3, val3) == answer3);
        std::vector<int> nums4 = { 2,2, 3 };
        int answer4 = { 1 };
        int val4 = { 2 };
        REQUIRE(mySolution.removeElement(nums4, val4) == answer4);
    }
    SECTION("empty vector") {
        std::vector<int> nums3 = { };
        int answer3 = 0;
        int val3 = 0;
        REQUIRE(mySolution.removeElement(nums3, val3) == answer3);
        std::vector<int> nums5 = { 1,1,1,1,1,1,1,1 };
        int val5 = 3;
        int answer5 = 8;
        REQUIRE(mySolution.removeElement(nums5,val5) == answer5);
    }
}