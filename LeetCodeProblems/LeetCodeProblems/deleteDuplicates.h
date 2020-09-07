#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <iostream>

//Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//Example 1:
//
//Input: 1->1->2
//Output : 1->2
//Example 2 :
//
//    Input : 1->1->2->3->3
//    Output : 1->2->3

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto listTracker = head;
        if (!head) return nullptr;
        ListNode* previous = head;
        while (listTracker) {
            if (listTracker->val != previous->val) {
                //remove duplicate
                previous->next = listTracker;
                previous = listTracker;
            }
            listTracker = listTracker->next;
        }
        previous->next = nullptr;
        return head;
    }
};


Solution mySolution{};

TEST_CASE("searchInsert ") {
    SECTION("passess the initial examples") {
        ListNode input1{1};
        ListNode input2{ 1 };
        ListNode input3{ 2 };
        input1.next = &input2;
        input2.next = &input3;
        ListNode* answer1 = mySolution.deleteDuplicates(&input1);
        REQUIRE(answer1->val == 1);
        answer1 = answer1->next;
        REQUIRE(answer1->val == 2);
        ListNode input1_b{ 1 };
        ListNode input2_b{ 1 };
        ListNode input3_b{ 2 };
        ListNode input4_b{ 3 };
        ListNode input5_b{ 3 };
        input1_b.next = &input2_b;
        input2_b.next = &input3_b;
        input3_b.next = &input4_b;
        input4_b.next = &input5_b;
        ListNode* answer1_b = mySolution.deleteDuplicates(&input1_b);
        REQUIRE(answer1_b->val == 1);
        answer1_b = answer1_b->next;
        REQUIRE(answer1_b->val == 2);
        answer1_b = answer1_b->next;
        REQUIRE(answer1_b->val == 3);
        ListNode input1_c{ 1 };
        ListNode input2_c{ 1 };
        ListNode input3_c{ 1 };
        input1_c.next = &input2_c;
        input2_c.next = &input3_c;
        ListNode* answer1_c = mySolution.deleteDuplicates(&input1_c);
        REQUIRE(answer1_c->val == 1);
        REQUIRE(answer1_c->next == NULL);
        ListNode input1_d{};
        ListNode* answer1_d = mySolution.deleteDuplicates(&input1_d);
        REQUIRE(answer1_d->val == NULL);

    }
};
