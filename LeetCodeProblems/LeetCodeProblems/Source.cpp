
#pragma once
#include <chrono>
#include <cstdio>
#include <cstdint>
#include <random>
#include <iostream>

//#include "twoSum.h"
//#include <vector>

//#include "reverseInteger.h"
//#include <limits.h>

//#include "palindromeNumber.h"

//#include "RomanToInteger.h"

//#include "longestPrefix.h"

//#include "validParentheses.h"

//#include "MergeLinkedLists.h"

//#include "removeDuplicates.h"

//#include "removeElement.h"

//#include "strStr.h"

//#include "searchInsert.h"

//#include "countAndSay.h"

//#include "maxSubArray.h"

#include "lengthOfLastWord.h"

////timing for optimization:
struct Stopwatch {
    Stopwatch(std::chrono::nanoseconds& result)
        : result{ result },
        start{ std::chrono::high_resolution_clock::now() } {}
    ~Stopwatch() {
        result = std::chrono::high_resolution_clock::now() - start;
    }
private:
    std::chrono::nanoseconds& result;
    const std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

using namespace std;

//TwoSum:
//int main() {
//    std::chrono::nanoseconds timeToSearch;
//    {
//        int number = 100'000;
//        vector<int> nums4;
//        std::mt19937_64 mt_engine{ 91586 };
//        std::uniform_int_distribution<int> int_d{ 0,100 };
//        for (int i{}; i < number; i++)
//            nums4.emplace_back(int_d(mt_engine));
//        cout << nums4.size() << endl;
//        vector<int> answer;
//        {
//            Stopwatch stopwatch{ timeToSearch };
//            answer = mySolution.twoSumBruteForce(nums4, 37);
//        }
//        auto totalTime_sec = timeToSearch.count();
//        cout << "Indices: [" << answer[0] << "," << answer[1] << "]" << endl;
//        printf("Brute force took %gms to complete.", totalTime_sec / 1.0e9);
//        {
//            Stopwatch stopwatch{ timeToSearch };
//            answer = mySolution.twoSumDifferenceSearch(nums4, 37);
//        }
//        auto totalTime_sec = timeToSearch.count();
//        cout << "Indices: [" << answer[0] << "," << answer[1] << "]" << endl;
//        printf("Difference search took %gms to complete.", totalTime_sec / 1.0e9);
//    }
//}

//ReverseInteger
//int main() {
//    std::chrono::nanoseconds timetosearch;
//    {
//        int numberinput{0};
//        int answer{};
//        {
//            Stopwatch stopwatch{ timetosearch };
//            answer = mySolution.reverseInteger(numberinput);
//        }
//        auto totaltime_sec = timetosearch.count();
//        cout << "answer: " << answer << endl;
//        printf("brute force took %gms to complete.", totaltime_sec / 1.0e9);
//
//    }
//}

//PalindromeNumber
//int main() {
//    std::chrono::nanoseconds timetosearch;
//        {
//            int numberinput{0};
//            int answer{};
//            {
//                Stopwatch stopwatch{ timetosearch };
//                answer = mySolution.isPalindrome(numberinput);
//            }
//            auto totaltime_sec = timetosearch.count();
//            cout << "answer: " << answer << endl;
//            printf("brute force took %gms to complete.", totaltime_sec / 1.0e9);
//    
//        }
//}

//RomanToInteger
//int main() {
//    std::chrono::nanoseconds timetosearch;
//        {
//            std::string numberinput{"IV"};
//            int answer{4};
//            {
//                Stopwatch stopwatch{ timetosearch };
//                answer = mySolution.romanToInt(numberinput);
//            }
//            auto totaltime_sec = timetosearch.count();
//            cout << "answer: " << answer << endl;
//            printf("brute force took %gms to complete.", totaltime_sec / 1.0e9);
//    
//        }
//}

//LongestPrefix
//int main() {
//    std::vector<std::string> strVectorInput7{ "c", "c" };
//    std::string answer7{ "c" };
//    mySolution.longestCommonPrefix(strVectorInput7);
//}

//validParentheses
//int main() {
//    std::string input1{ "()" };
//    bool answer1{ true };
//    std::cout << (mySolution.isValid(input1) == answer1);
//}

//mergeTwoLists
//int main() {
//    ListNode input13{ 4 };
//    ListNode input12{ 2, &input13 };
//    ListNode input11{ 1, &input12 };
//    ListNode input23{ 4 };
//    ListNode input22{ 3, &input23 };
//    ListNode input21{ 1, &input22 };
//    ListNode* answer1 = mySolution.mergeTwoLists(&input11, &input21);
//    while (answer1->next != nullptr) {
//        answer1 = answer1->next;
//        std::cout << answer1->val << endl;
//    }
//}

//removeDuplicates
//#include <vector>
//int main() {
//    /*vector<int> nums1 = { 1,1,2 };
//    int answer1 = { 2 };
//    mySolution.removeDuplicates(nums1) == answer1;*/
//    std::vector<int> nums2 = { 0,0,1,1,1,2,2,3,3,4 };
//    int answer2 = { 5 };
//    mySolution.removeDuplicates(nums2) == answer2;
//}

//removeElement
//#include <vector>
//int main() {
//int input4{ 4 };
//std::string answer4{ "1211" };
//mySolution.countAndSay(input4) == answer4;
//}

//LengthOfLastWord
//int main() {
//    std::string input{ "Hello World!" };
//    int answer{ 5 };
//    mySolution.lengthOfLastWord(input) == answer;
//}