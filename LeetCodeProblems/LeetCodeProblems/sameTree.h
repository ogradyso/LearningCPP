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
        //if both p and q are null we have reached the end of both trees
        /*if (!p && !q) {
            return true;
        }
        return p && q && p->val == q->val &&
            isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right);*/

        //Why is this soltuion faster than above?
        if (p == NULL && q == NULL) return true;
        else if (p == NULL && q != NULL) return false;
        else if (p != NULL && q == NULL) return false;

        if (p->val != q->val) return false;

        if (!isSameTree(p->left, q->left)) return false;
        if (!isSameTree(p->right, q->right)) return false;
        return true;
    }
};

Solution mySolution{};

TEST_CASE("searchInsert ") {
    SECTION("passess the initial examples") {
        TreeNode input_1_3 = TreeNode(3);
        TreeNode input_1_2 = TreeNode(2);
        TreeNode input_1_1 = TreeNode(1, &input_1_2, &input_1_3);
        TreeNode input_2_3 = TreeNode(3);
        TreeNode input_2_2 = TreeNode(2);
        TreeNode input_2_1 = TreeNode(1, &input_2_2, &input_2_3);
        bool answer1{ true };
        REQUIRE(mySolution.isSameTree(&input_1_1, &input_2_1)==answer1);

        TreeNode input_3_3 = TreeNode(1);
        TreeNode input_3_2 = TreeNode(2);
        TreeNode input_3_1 = TreeNode(1, &input_3_2, &input_3_3);
        TreeNode input_4_3 = TreeNode(2);
        TreeNode input_4_2 = TreeNode(1);
        TreeNode input_4_1 = TreeNode(1, &input_4_2, &input_4_3);
        bool answer2{ false };
        REQUIRE(mySolution.isSameTree(&input_3_1, &input_4_1) == answer2);
    }
    SECTION("one node tree") {
        TreeNode input_1_1 = TreeNode(1);
        TreeNode input_2_3 = TreeNode(3);
        TreeNode input_2_2 = TreeNode(2);
        TreeNode input_2_1 = TreeNode(1, &input_2_2, &input_2_3);
        bool answer1{ false };
        REQUIRE(mySolution.isSameTree(&input_1_1, &input_2_1) == answer1);
    }
    SECTION("null prt tree") {
        TreeNode input_1_1 = NULL;
        TreeNode input_2_1 = NULL;
        bool answer1{ true };
        REQUIRE(mySolution.isSameTree(&input_1_1, &input_2_1) == answer1);
    }
}