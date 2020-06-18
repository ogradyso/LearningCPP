#define CATCH_CONFIG_MAIN
#include "catch.h"

#include <boost/logic/tribool.hpp>

// boost::tribool
using boost::logic::indeterminate;
boost::logic::tribool t = true, f = false, i = indeterminate;

TEST_CASE("Boost tribool converts to bool") {
	REQUIRE(t);
	REQUIRE_FALSE(f);
	REQUIRE(!f);
	REQUIRE_FALSE(!t);
	REQUIRE(indeterminate(i));
	REQUIRE_FALSE(indeterminate(t));
}

TEST_CASE("Boost Tribool supports Boolean operations") {
	auto t_or_f = t || f;
	REQUIRE(t_or_f);
	REQUIRE(indeterminate(t && indeterminate));
	REQUIRE(indeterminate(f || indeterminate));
	REQUIRE(indeterminate(!i));
}

TEST_CASE("Boost Tribool works nicely with if statements") {
	if (i) FAIL("Indeterminate is true.");
	else if (!i) FAIL("Indeterminate is false.");
	else {} // Ok, indeterminate
}

// std::optional
#include <optional>

struct TheMatrix {
	TheMatrix(int x) : iteration{ x } {}
	const int iteration;
};

enum Pill {Red, Blue};

std::optional<TheMatrix> take(Pill pill) {
	if (pill == Pill::Blue) return TheMatrix{ 6 };
	return std::nullopt;
}

TEST_CASE("std::optional contains types") {
	if (auto matrix_opt = take(Pill::Blue)) {
		REQUIRE(matrix_opt->iteration == 6);
		auto& matrix = matrix_opt.value();
		REQUIRE(matrix.iteration == 6);
	}
	else {
		FAIL("The optional evaluated to false.");
	}
}

TEST_CASE("std::optional can be empty") {
	auto matrix_opt = take(Pill::Red);
	if (matrix_opt) FAIL("The Matrix is not empty.");
	REQUIRE_FALSE(matrix_opt.has_value());
}