#define CATCH_CONFIG_MAIN
#include "catch.h"

#include <vector>
#include <string>

//non-modifying sequence operations
#include <algorithm>

TEST_CASE("all_of") {
	std::vector<std::string> words{ "Auntie", "Anne's", "alligator" };
	const auto starts_with_a =
		[](const auto& word) {
		if (word.empty()) return false;
		return word[0] == 'A' || word[0] == 'a';
	};
	REQUIRE(all_of(words.cbegin(), words.cend(), starts_with_a));
	const auto has_length_six = [](const auto& word) {
		return word.length() == 6;
	};
	REQUIRE_FALSE(all_of(words.cbegin(), words.cend(), has_length_six));
}

