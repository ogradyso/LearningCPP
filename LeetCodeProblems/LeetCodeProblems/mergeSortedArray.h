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
            int iterationTracker = 0;
            int nums2_indexTracker = 0;
            while (nums2_iter != nums2.end()) {
                if (*nums1_iter >= *nums2_iter ) {
                    nums1.insert(nums1_iter, *nums2_iter);
                    nums1.pop_back();
                    nums1_iter = nums1.begin() +iterationTracker;
                    nums2_iter++;
                    nums2_indexTracker++;
                }
                else if (iterationTracker >= m+nums2_indexTracker) {
                    while ((*(nums1.end() - 1) == 0) && (nums1.end()-1 != nums1.begin()+(m +nums2_indexTracker-1))) {
                        nums1.pop_back();
                    }
                    while (nums2_iter != nums2.end()) {
                        nums1.push_back(*nums2_iter);
                        nums2_iter++;
                        nums1_iter = nums1.begin();
                    }
                }
                
                nums1_iter++;
                iterationTracker++;
            }
        }
    }
};

//nums1_iter != nums1.end() && 
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
        vector<int> input1_i{ -1, 1, 1, 3, 3, 3, 0, 0, 0 };
        vector<int> input2_i{ 0, 2, 2 };
        vector<int> answer_i{ -1, 0, 1, 1, 2, 2, 3, 3, 3 };
        mySolution.merge(input1_i, 6, input2_i, 3);
        REQUIRE(input1_i == answer_i);
        vector<int> input1_j{ 0, 0, 1, 3, 3, 3, 0, 0, 0 };
        vector<int> input2_j{ 0, 2, 2 };
        vector<int> answer_j{ 0, 0, 0, 1, 2, 2, 3, 3, 3 };
        mySolution.merge(input1_j, 6, input2_j, 3);
        REQUIRE(input1_j == answer_j);
        vector<int> input1_k{ 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        vector<int> input2_k{ 0, 0, 0, 0, 0, 0, 0, 1 };
        vector<int> answer_k{ 0, 0, 0, 0, 0, 0, 0, 0, 1 };
        mySolution.merge(input1_k, 1, input2_k, 8);
        REQUIRE(input1_k == answer_k);
        vector<int> input1_l{ 4, 0, 0, 0, 0, 0 };
        vector<int> input2_l{ 1,2,3,5,6 };
        vector<int> answer_l{ 1,2,3,4,5,6 };
        mySolution.merge(input1_l, 1, input2_l, 5);
        REQUIRE(input1_l == answer_l);
        vector<int> input1_m{ 0, 2, 4, 6, 8, 0,0,0,0,0 };
        vector<int> input2_m{ 1,2,3,5,7 };
        vector<int> answer_m{ 0,1,2,2,3,4,5,6,7,8 };
        mySolution.merge(input1_m, 5, input2_m, 5);
        REQUIRE(input1_m == answer_m);
        vector<int> input1_n{ 1, 2, 3, 5, 7, 0,0,0,0,0 };
        vector<int> input2_n{ 0, 2, 4, 6, 8 };
        vector<int> answer_n{ 0,1,2,2,3,4,5,6,7,8 };
        mySolution.merge(input1_n, 5, input2_n, 5);
        REQUIRE(input1_n == answer_n); 
    }
};
