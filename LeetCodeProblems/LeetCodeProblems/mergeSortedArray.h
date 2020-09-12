#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <iostream>

//Given two sorted integer arrays nums1and nums2, merge nums2 into nums1 as one sorted array.
//
//Note:
//
//The number of elements initialized in nums1and nums2 are mand n respectively.
//You may assume that nums1 has enough space(size that is equal to m + n) to hold additional elements from nums2.
//Example :
//
//    Input :
//    nums1 = [1, 2, 3, 0, 0, 0], m = 3
//    nums2 = [2, 5, 6], n = 3
//
//    Output : [1, 2, 2, 3, 5, 6]
//
//
//    Constraints :
//
//    -10 ^ 9 <= nums1[i], nums2[i] <= 10 ^ 9
//    nums1.length == m + n
//    nums2.length == n

using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m+n == n) {
            nums1 = nums2;
        }
        else {
            auto nums1_iter = nums1.begin();
            auto nums2_iter = nums2.begin();
            while (nums1_iter != nums1.end() && nums2_iter != nums2.end()) {
                if ((*nums1_iter > * nums2_iter) || (nums1_iter != nums1.begin() && *nums1_iter == 0)) {
                    nums1.insert(nums1_iter, *nums2_iter);
                    nums1.pop_back();
                    nums1_iter = nums1.begin();
                    nums2_iter++;
                }
                nums1_iter++;
            }
        }
    }
};


Solution mySolution{};

TEST_CASE("searchInsert ") {
    SECTION("passess the initial examples") {
        vector<int> input1{ 1,2,3,0,0,0 };
        vector<int> input2{ 2,5,6 };
        vector<int> answer{1,2,2,3,5,6};
        mySolution.merge(input1, 3, input2, 3);
        REQUIRE(input1 == answer);
        vector<int> input1_a{ 0,2,3,0 };
        vector<int> input2_a{ 0 };
        vector<int> answer_a{ 0,0,2,3 };
        mySolution.merge(input1_a, 3, input2_a, 1);
        REQUIRE(input1_a == answer_a);
        vector<int> input1_b{ 5,6,7,8,0,0,0,0 };
        vector<int> input2_b{ -400,-4, -1, 2 };
        vector<int> answer_b{ -400, -4, -1, 2, 5,6,7,8 };
        mySolution.merge(input1_b, 4, input2_b, 4);
        REQUIRE(input1_b == answer_b);
        vector<int> input1_c{ 2,2,2,0,0 };
        vector<int> input2_c{ 2,2 };
        vector<int> answer_c{ 2,2,2,2,2 };
        mySolution.merge(input1_c, 3, input2_c, 2);
        REQUIRE(input1_c == answer_c);
        vector<int> input1_d{ 1,2,3,0,0 };
        vector<int> input2_d{ 2,2 };
        vector<int> answer_d{ 1,2,2,2,3 };
        mySolution.merge(input1_d, 3, input2_d, 2);
        REQUIRE(input1_d == answer_d);
        vector<int> input1_e{ 0 };
        vector<int> input2_e{ 1 };
        vector<int> answer_e{ 1 };
        mySolution.merge(input1_e, 0, input2_e, 1);
        REQUIRE(input1_e == answer_e);
        vector<int> input1_f{ 0 ,0,0};
        vector<int> input2_f{ 1,2,3 };
        vector<int> answer_f{ 1,2,3 };
        mySolution.merge(input1_f, 0, input2_f, 1);
        REQUIRE(input1_f == answer_f);
        vector<int> input1_g {0,0};
        vector<int> input2_g{ 1 };
        vector<int> answer_g{ 0,1 };
        mySolution.merge(input1_g, 1, input2_g, 1);
        REQUIRE(input1_g == answer_g);
        vector<int> input1_h{ -1, 0, 0, 3, 3, 3, 0, 0, 0 };
        vector<int> input2_h{ 1, 2, 2 };
        vector<int> answer_h{ -1, 0, 0, 1, 2, 2, 3, 3, 3 };
        mySolution.merge(input1_h, 6, input2_h, 3);
        REQUIRE(input1_h == answer_h);

    }
};
