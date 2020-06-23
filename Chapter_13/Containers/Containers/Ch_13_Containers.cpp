#define CATCH_CONFIG_MAIN
#include "catch.h"

#include <array>

std::array<int, 10> static_array;

TEST_CASE("std::array") {
	REQUIRE(static_array[0] ==0);

	SECTION("uninitialized without braced initializers") {
		std::array<int, 10> local_array;
		REQUIRE(local_array[0] != 0);
	}

	SECTION("initialized with braced initializers") {
		std::array<int, 10> local_array{ 1,1,2,3 };
		REQUIRE(local_array[0] == 1);
		REQUIRE(local_array[1] == 1);
		REQUIRE(local_array[2] == 2);
		REQUIRE(local_array[3] == 3);
		REQUIRE(local_array[4] == 0);
	}
}

TEST_CASE("std::array access") {
	std::array<int, 4> fib{ 1,1,0,3 };

	SECTION("operator[] can get and set elements") {
		fib[2] = 2;
		REQUIRE(fib[2] == 2);
		// fib[4] = 5; //throws an error
	}
	SECTION("at() can get and set elements") {
		fib.at(2) = 2;
		REQUIRE(fib.at(2) == 2);
		REQUIRE_THROWS_AS(fib.at(4), std::out_of_range);
	}
	SECTION("get can get and set elements") {
		std::get<2>(fib) = 2;
		REQUIRE(std::get<2>(fib) == 2);
		//std::get<4>(fib);
	}
}

TEST_CASE("std::array has convenience methods") {
	std::array<int, 4> fib{ 0,1,2,0 };

	SECTION("front") {
		fib.front() = 1;
		REQUIRE(fib.front() == 1);
		REQUIRE(fib.front() == fib[0]);
	}
	SECTION("back") {
		fib.back() = 3;
		REQUIRE(fib.back() == 3);
		REQUIRE(fib.back() == fib[3]);
	}
}

TEST_CASE("We can obtain a pointer to the first element using") {
	std::array<char, 9> color{ 'o', 'c','t','a','r', 'i','n','e' };
	const auto* color_ptr = color.data();

	SECTION("data") {
		REQUIRE(*color_ptr == 'o');
	}
	SECTION("address-of front") {
		REQUIRE(&color.front() == color_ptr);
	}
	SECTION("address of at(0)") {
		REQUIRE(&color[0] == color_ptr);
	}
	SECTION("address-of [0]") {
		REQUIRE(&color[0] == color_ptr);
	}
}

//iterators:
TEST_CASE("std::array begin/end form a half-open range") {
	std::array<int, 0> e{};
	REQUIRE(e.begin() == e.end());
}

TEST_CASE("std::array iterators are pointer-like") {
	std::array<int, 3> easy_as{ 1,2,3 };
	auto iter = easy_as.begin();
	REQUIRE(*iter == 1);
	++iter;
	REQUIRE(*iter == 2);
	++iter;
	REQUIRE(*iter == 3);
	++iter;
	REQUIRE(iter == easy_as.end());
}

TEST_CASE("std::array can be used as a range expression") {
	std::array<int, 5> fib{ 1,1,2,3,5 };
	int sum{};
	for (const auto element : fib)
		sum += element;
	REQUIRE(sum == 12);
}

#include <vector>

TEST_CASE("std::vector supportsdefault construction") {
	std::vector<const char*> vec;
	REQUIRE(vec.empty());
}

TEST_CASE("std::vector supports braced initialization ") {
	std::vector<int> fib{ 1,1,2,3,5 };
	REQUIRE(fib[4] == 5);
}

TEST_CASE("std::vector supports") {
	SECTION("braced initialization") {
		std::vector<int> five_nine{ 5,9 };
		REQUIRE(five_nine[0] == 5);
		REQUIRE(five_nine[1] == 9);
	}
	SECTION("fill constructor") {
		std::vector<int> five_nines(5, 9);
		REQUIRE(five_nines[0] == 9);

		REQUIRE(five_nines[4] == 9);
	}
}

TEST_CASE("std::vector supports construction from iterators") {
	std::array<int, 5> fib_arr{ 1, 1, 2, 3, 5 };
	std::vector<int> fib_vec(fib_arr.begin(), fib_arr.end());
	REQUIRE(fib_vec[4] == 5);
	REQUIRE(fib_vec.size() == fib_arr.size());
}

TEST_CASE("std::vector assigned replaces existing elements") {
	std::vector<int> message{ 13,80,110,114,102,110,101 };
	REQUIRE(message.size() == 7);
	message.assign({ 67,97,101,115,97,114 });
	REQUIRE(message[5] == 114);
	REQUIRE(message.size() == 6);
}

TEST_CASE("std::vector insert places new elements") {
	std::vector<int> zeros(3,0);
	auto third_element = zeros.begin() + 2;
	zeros.insert(third_element, 10);
	REQUIRE(zeros[2] == 10);
	REQUIRE(zeros.size() == 4);
}

TEST_CASE("std::vector push_back places new element") {
	std::vector<int> zeros(3, 0);
	zeros.push_back(10);
	REQUIRE(zeros[3] == 10);
}

#include <utility>

TEST_CASE("std::vector emplace methods forward arguments") {
	std::vector<std::pair<int, int>> factors;
	factors.emplace_back(2, 30);
	factors.emplace_back(3, 20);
	factors.emplace_back(4, 15);
	factors.emplace(factors.begin(), 1, 60);
	REQUIRE(factors[0].first == 1);
	REQUIRE(factors[0].second == 60);
}

#include <cstdint>
#include <array>

TEST_CASE("std::vector exposes size management methods") {
	std::vector<std::array<uint8_t, 1024>> kb_store;
	REQUIRE(kb_store.max_size() > 0);
	REQUIRE(kb_store.empty());

	size_t elements{ 1024 };
	kb_store.reserve(elements);
	REQUIRE(kb_store.empty());
	REQUIRE(kb_store.capacity() == elements);

	kb_store.emplace_back();
	kb_store.emplace_back();
	kb_store.emplace_back();
	REQUIRE(kb_store.capacity() >= 3);

	kb_store.shrink_to_fit();
	REQUIRE(kb_store.capacity() >= 3);

	kb_store.clear();
	REQUIRE(kb_store.empty());
	REQUIRE(kb_store.capacity() >= 3);

}

#include <deque>

TEST_CASE("std::deque supports front insertion") {
	std::deque<char> deckard;
	deckard.push_front('a');  //a
	deckard.push_back('i');	  //ai
	deckard.push_front('c');  //cai
	deckard.push_back('n');   //cain
	REQUIRE(deckard[0] == 'c');
	REQUIRE(deckard[1] == 'a');
	REQUIRE(deckard[2] == 'i');
	REQUIRE(deckard[3] == 'n');
}

#include <list>
TEST_CASE("std::list supports front insertion") {
	std::list<int> odds{ 11,22,33,44,55 };
	odds.remove_if([](int x) { return x % 2 == 0; });
	auto odds_iter = odds.begin();
	REQUIRE(*odds_iter == 11);
	++odds_iter;
	REQUIRE(*odds_iter == 33);

	++odds_iter;
	REQUIRE(*odds_iter == 55);
	++odds_iter;
	REQUIRE(odds_iter == odds.end());
}

#include <stack>

TEST_CASE("std::stack supports push/pop/top operations") {
	std::vector<int> vec{ 1,3 };  // 1 3
	std::stack<int, decltype(vec)> easy_as(vec);
	REQUIRE(easy_as.top() == 3);
	easy_as.pop();
	easy_as.push(2);
	REQUIRE(easy_as.top() == 2);
	easy_as.pop();
	REQUIRE(easy_as.top() == 1);
	easy_as.pop();
	REQUIRE(easy_as.empty());
}

#include <queue>

TEST_CASE("std::queue supports push/pop/front/back") {
	std::deque<int> deq{ 1,2 };
	std::queue<int> easy_as(deq);
	REQUIRE(easy_as.front() == 1);
	REQUIRE(easy_as.back() == 2);
	easy_as.pop();
	easy_as.push(3);
	REQUIRE(easy_as.front() == 2);
	REQUIRE(easy_as.back() == 3);
	easy_as.pop();
	REQUIRE(easy_as.front() == 3);
	easy_as.pop();
	REQUIRE(easy_as.empty());
}

#include <queue>

TEST_CASE("std::priority_queue supports push/pop") {
	std::priority_queue<double> prique;
	prique.push(1.0); //1.0
	prique.push(2.0); //2.0, 1.0
	prique.push(1.5); //2.0, 1.5, 1.0
	REQUIRE(prique.top() == Approx(2.0));
	prique.pop();
	prique.push(1.0);
	REQUIRE(prique.top() == Approx(1.5));
	prique.pop();
	REQUIRE(prique.top() == Approx(1.0));
	prique.pop();
	REQUIRE(prique.top() == Approx(1.0));
	prique.pop();
	REQUIRE(prique.empty());

}

#include <bitset>

TEST_CASE("std::bitset supports integer initialization") {
	std::bitset<4> bs(0b0101);
	REQUIRE(bs[0]==true);
	REQUIRE(bs[1]==false);
	REQUIRE(bs[2]==true);
	REQUIRE(bs[3]==false);
}

TEST_CASE("std::bitset supports string initialization") {
	std::bitset<4> bs1(0b0110);
	std::bitset<4> bs2("0110");
	REQUIRE(bs1 == bs2);
}

#include <set>

TEST_CASE("std::set supports") {
	std::set<int> emp;
	std::set<int> fib{ 1,1,2,3,5 };
	SECTION("default construction") {
		REQUIRE(emp.empty());
	}
	SECTION("braced initialization") {
		REQUIRE(fib.size() == 4);
	}
	SECTION("copy construction") {
		auto fib_copy(fib);
		REQUIRE(fib.size() == 4);
		REQUIRE(fib_copy.size() == 4);
	}
	SECTION("move construction") {
		auto fib_moved(std::move(fib));
		REQUIRE(fib.empty());
		REQUIRE(fib_moved.size() == 4);
	}
	SECTION("range construction") {
		std::array<int, 5> fib_array{ 1,1,2,3,5 };
		std::set<int> fib_set(fib_array.cbegin(), fib_array.cend());
		REQUIRE(fib_set.size() == 4);
	}
}

TEST_CASE("std::set allows access") {
	std::set<int> fib{ 1,1,2,3,5 };
	SECTION("with find") {
		REQUIRE(*fib.find(3) == 3);
		REQUIRE(fib.find(100) == fib.end());
	}
	SECTION("with count") {
		REQUIRE(fib.count(3) == 1);
		REQUIRE(fib.count(100) == 0);
	}
	SECTION("with lower_bound") {
		auto itr = fib.lower_bound(3);
		REQUIRE(*itr == 3);
	}
	SECTION("with upper_bound") {
		auto itr = fib.upper_bound(3);
		REQUIRE(*itr == 5);
	}
	SECTION("with equal_range") {
		auto pair_itr = fib.equal_range(3);
		REQUIRE(*pair_itr.first == 3);
		REQUIRE(*pair_itr.second == 5);
	}
}