#pragma once
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <string>
#include <vector>

//Merge two sorted linked listsand return it as a new sorted list.The new list should be made by splicing together the nodes of the first two lists.
//
//Example:
//
//Input: 1->2->4, 1->3->4
//Output : 1->1->2->3->4->4


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return { l2 };
        if (l2 == NULL) return { l1 };
        ListNode* newStart;
        if (l1->val < l2->val) {
            newStart = l1;
            newStart->next = mergeTwoLists(l1->next, l2);
        }
        else {
            newStart = l2;
            newStart->next = mergeTwoLists(l1, l2->next);
        }
        return { newStart };
    }
};

Solution mySolution{};

TEST_CASE("isValid ") {
    SECTION("passess the initial example") {
        ListNode input13{ 4 };
        ListNode input12{ 2, &input13};
        ListNode input11{ 1, &input12};
        ListNode input23{ 4 };
        ListNode input22{ 3, &input23 };
        ListNode input21{ 1, &input22 };
        ListNode* answer1 = mySolution.mergeTwoLists(&input11, &input21);
        REQUIRE(answer1->val == 1);
        answer1 = answer1->next;
        REQUIRE(answer1->val == 1);
        answer1 = answer1->next;
        REQUIRE(answer1->val == 2);
        answer1 = answer1->next;
        REQUIRE(answer1->val == 3);
        answer1 = answer1->next;
        REQUIRE(answer1->val == 4);
        answer1 = answer1->next;
        REQUIRE(answer1->val == 4);
    }
    SECTION("handles all same values") {
        ListNode input13{ 1 };
        ListNode input12{ 1, &input13 };
        ListNode input11{ 1, &input12 };
        ListNode input23{ 1 };
        ListNode input22{ 1, &input23 };
        ListNode input21{ 1, &input22 };
        ListNode* answer1 = mySolution.mergeTwoLists(&input11, &input21);
        REQUIRE(answer1->val == 1);
        answer1 = answer1->next;
        REQUIRE(answer1->val == 1);
        answer1 = answer1->next;
        REQUIRE(answer1->val == 1);
        answer1 = answer1->next;
        REQUIRE(answer1->val == 1);
        answer1 = answer1->next;
        REQUIRE(answer1->val == 1);
        answer1 = answer1->next;
        REQUIRE(answer1->val == 1);
    }
    SECTION("handles l2 vals greater than l1 vals") {
        ListNode input13{ 3 };
        ListNode input12{ 2, &input13 };
        ListNode input11{ 1, &input12 };
        ListNode input23{ 6 };
        ListNode input22{ 5, &input23 };
        ListNode input21{ 4, &input22 };
        ListNode* answer1 = mySolution.mergeTwoLists(&input11, &input21);
        REQUIRE(answer1->val == 1);
        answer1 = answer1->next;
        REQUIRE(answer1->val == 2);
        answer1 = answer1->next;
        REQUIRE(answer1->val == 3);
        answer1 = answer1->next;
        REQUIRE(answer1->val == 4);
        answer1 = answer1->next;
        REQUIRE(answer1->val == 5);
        answer1 = answer1->next;
        REQUIRE(answer1->val == 6);
    }
}
