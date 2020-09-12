#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"

//Given two binary trees, write a function to check if they are the same or not.
//
//Two binary trees are considered the same if they are structurally identicaland the nodes have the same value.
//
//Example 1:
//
//Input:     1         1
/// \ / \
//2   3     2   3
//
//[1, 2, 3], [1, 2, 3]
//
//Output: true
//Example 2 :
//
//    Input : 1         1
//    / \
//    2             2
//
//    [1, 2], [1, null, 2]
//
//    Output: false
//    Example 3 :
//
//    Input : 1         1
//    / \ / \
//    2   1     1   2
//
//    [1, 2, 1], [1, 1, 2]
//
//    Output: false


//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

    }
};

Solution mySolution{};

TEST_CASE("searchInsert ") {
    SECTION("passess the initial examples") {
        /*vector<int> input1{ 1,2,3,0,0,0 };
        vector<int> input2{ 2,5,6 };
        vector<int> answer{ 1,2,2,3,5,6 };
        mySolution.merge(input1, 3, input2, 3);
        REQUIRE(input1 == answer);*/
    }
}