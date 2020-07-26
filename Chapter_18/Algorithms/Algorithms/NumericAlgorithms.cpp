#define CATCH_CONFIG_MAIN
#include "catch.h"

using namespace std;

#include <functional>
TEST_CASE("plus") {
	plus<short> adder;
	REQUIRE(3 == adder(1, 2));
	REQUIRE(3 == plus<short>{}(1, 2));
}

//iota
#include <numeric>
#include <array>

TEST_CASE("iota") {
	array<int, 3> easy_as;
	iota(easy_as.begin(), easy_as.end(), 1);
	REQUIRE(easy_as == array<int, 3>{1, 2, 3});
}

//accumulate
TEST_CASE("accumulate") {
	vector<int> nums{ 1,2,3 };
	const auto result1 = accumulate(nums.begin(), nums.end(), -1);
	REQUIRE(result1 == 5);

	const auto result2 = accumulate(nums.begin(), nums.end(), 2, multiplies());

	REQUIRE(result2 == 12);
}

//reduce
TEST_CASE("reduce") {
	vector<int> nums{ 1,2,3 };
	const auto result1 = reduce(nums.begin(), nums.end(), -1);
	REQUIRE(result1 == 5);
	const auto result2 = reduce(nums.begin(), nums.end(), 2, multiplies<>());

	REQUIRE(result2 == 12);
}

//inner_product
TEST_CASE("inner_product") {
	vector<int> nums1{ 1,2,3,4,5 };
	vector<int> nums2{ 1, 0, -1, 0, 1 };
	const auto result = inner_product(nums1.begin(), nums1.end(), nums2.begin(), 10);
	REQUIRE(result == 13);
}

//adjacent_difference
TEST_CASE("adjacent_differences") {
	vector<int> fib{ 1,1,2,3,5,8 }, fib_diff;
	adjacent_difference(fib.begin(), fib.end(), back_inserter(fib_diff));
	REQUIRE(fib_diff == vector<int>{1, 0, 1, 1, 2, 3});
}

//partial_sum
TEST_CASE("partial_sum") {
	vector<int> num{ 1,2,3,4 }, result;
	partial_sum(num.begin(), num.end(), back_inserter(result));
	REQUIRE(result == vector<int>{1, 3, 6, 10});
}

