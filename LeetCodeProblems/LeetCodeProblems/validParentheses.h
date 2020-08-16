#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <string>
#include <vector>

// includes for Leet submission:
#include <stack>

//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//An input string is valid if:
//
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Note that an empty string is also considered valid.
//
//Example 1:
//
//Input: "()"
//Output : true
//Example 2 :
//
//    Input : "()[]{}"
//    Output : true
//    Example 3 :
//
//    Input : "(]"
//    Output : false
//    Example 4 :
//
//    Input : "([)]"
//    Output : false
//    Example 5 :
//
//    Input : "{[]}"
//    Output : true


class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> scopeChars;
        while (!s.empty()) {
            if (s.size() == 1 && scopeChars.empty()) return{ false };
            switch (s.back()) {
            case ']' : 
                scopeChars.push(s.back());
                break;
            case ')' : 
                scopeChars.push(s.back());
                break;
            case '}' : 
                scopeChars.push(s.back());
                break;
            case '[':
                if (scopeChars.empty()) return { false };
                if (scopeChars.top() == ']') {
                    scopeChars.pop();
                    break;
                }

                else {
                    return { false };
                }
            case '(':
                if (scopeChars.empty()) return { false };
                if (scopeChars.top() == ')') {
                    scopeChars.pop();
                    break;
                }
                else {
                    return { false };
                }
            case '{': 
                if (scopeChars.empty()) return { false };
                if (scopeChars.top() == '}') {
                    scopeChars.pop();
                    break;
                }
                else {
                    return { false };
                }
            default:
                //do nothing
                break;
            }
            s.pop_back();
        }
        if (scopeChars.empty()) {
            return{ true };
        }
        else {
            return{ false };
        }
    }

};

Solution mySolution{};

TEST_CASE("isValid ") {
    SECTION("passess the initial examples") {
        std::string input1{ "()" };
        bool answer1{ true };
        REQUIRE(mySolution.isValid(input1) == answer1);
        std::string input2{ "()[]{}" };
        bool answer2{ true };
        REQUIRE(mySolution.isValid(input2) == answer2);
        std::string input3{ "(]" };
        bool answer3{ false };
        REQUIRE(mySolution.isValid(input3) == answer3);
        std::string input4{ "([)]" };
        bool answer4{ false };
        REQUIRE(mySolution.isValid(input4) == answer4);
        std::string input5{ "{[]}" };
        bool answer5{ true };
        REQUIRE(mySolution.isValid(input5) == answer5);
        std::string input6{ "[" };
        bool answer6{ false };
        REQUIRE(mySolution.isValid(input6) == answer6);
        std::string input7{ "[()" };
        bool answer7{ false };
        REQUIRE(mySolution.isValid(input7) == answer7);
        std::string input8{ "((" };
        bool answer8{ false };
        REQUIRE(mySolution.isValid(input8) == answer8);
        std::string input9{ "(((" };
        bool answer9{ false };
        REQUIRE(mySolution.isValid(input9) == answer9);
        std::string input10{ "]]]" };
        bool answer10{ false };
        REQUIRE(mySolution.isValid(input10) == answer10);
        
    }
    SECTION("handles non-bracketing characters") {
        std::string input1{ "" };
        bool answer1{ true };
        REQUIRE(mySolution.isValid(input1) == answer1);
        std::string input2{ "(s)[f]{j}" };
        bool answer2{ true };
        REQUIRE(mySolution.isValid(input2) == answer2);
        std::string input3{ "(s){f](j}" };
        bool answer3{ false };
        REQUIRE(mySolution.isValid(input3) == answer3);
        std::string input4{ "(s){f](j}" };
        bool answer4{ false };
        REQUIRE(mySolution.isValid(input4) == answer4);
        std::string input5{ "([{]})" };
        bool answer5{ false };
        REQUIRE(mySolution.isValid(input5) == answer5);
    }
    
}