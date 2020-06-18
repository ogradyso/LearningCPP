#define CATCH_CONFIG_MAIN
#include "catch.h"

#include <boost/logic/tribool.hpp>

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