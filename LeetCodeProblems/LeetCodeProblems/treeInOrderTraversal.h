#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <iostream>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

    }
};

Solution mySolution{};

TEST_CASE("searchInsert ") {
    SECTION("passess the initial examples") {
        std::string input_a{ "11" };
        std::string input_b{ "1" };
        std::string answer{ "100" };
        REQUIRE(mySolution.addBinary(input_a, input_b) == answer);
        std::string input_a2{ "1010" };
        std::string input_b2{ "1011" };
        std::string answer2{ "10101" };
        REQUIRE(mySolution.addBinary(input_a2, input_b2) == answer2);
        std::string input_a3{ "0" };
        std::string input_b3{ "0" };
        std::string answer3{ "0" };
        REQUIRE(mySolution.addBinary(input_a3, input_b3) == answer3);
        std::string input_a4{ "10" };
        std::string input_b4{ "1111" };
        std::string answer4{ "10001" };
        REQUIRE(mySolution.addBinary(input_a4, input_b4) == answer4);
        std::string input_a5{ "" };
        std::string input_b5{ "1111" };
        std::string answer5{ "1111" };
        REQUIRE(mySolution.addBinary(input_a5, input_b5) == answer5);
        std::string input_a6{ "0" };
        std::string input_b6{ "1" };
        std::string answer6{ "1" };
        REQUIRE(mySolution.addBinary(input_a6, input_b6) == answer6);
        std::string input_a7{ "1111" };
        std::string input_b7{ "1111" };
        std::string answer7{ "11110" };
        REQUIRE(mySolution.addBinary(input_a7, input_b7) == answer7);
        std::string input_a8{ "100100001101100010011100010110000001001111110111010111110100" };
        std::string input_b8{ "111100011011010001100011011000111001011010111101111111010000" };
        std::string answer8{ "1100000101000110011111111101110111010101010110101010111000100" };
        REQUIRE(mySolution.addBinary(input_a8, input_b8) == answer8);
    }
}
