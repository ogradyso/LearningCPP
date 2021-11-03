#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <iostream>
/**
 * Definition for a binary tree node.
 */
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        func(root, v);
        return v;
    }
    void func(TreeNode* root, vector<int>& v) {
        if (root == 0)
            return;
        func(root->left, v);
        v.push_back(root->val);
        func(root->right, v);

    }
};

Solution mySolution{};

TEST_CASE("inorderTraversal ") {
    SECTION("passess the initial examples") {
        TreeNode input_1_3 = TreeNode(3);
        TreeNode input_1_2 = TreeNode(2, &input_1_3);
        TreeNode input_1_1 = TreeNode(1, NULL, &input_1_2);
        vector<int> answer1 = [1, null, 2, 3];
        REQUIRE(mySolution.inorderTraversal(&input_1_1) == answer1);
    }
}
