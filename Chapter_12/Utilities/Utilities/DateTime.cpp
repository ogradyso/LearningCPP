#define CATCH_CONFIG_MAIN
#include "catch.h"

#include <boost/date_time/gregorian/gregorian.hpp>

TEST_CASE("boost::gregorian::date default-constructs to a not_a_date") {
	boost::gregorian::date d;
	REQUIRE(d.as_special() == boost::gregorian::not_a_date_time);
}

TEST_CASE("Invalid boost::gregorian::dates throw exceptions") {
	using boost::gregorian::date;
	using boost::gregorian::bad_day_of_month;

	REQUIRE_THROWS_AS(date(1986, 9, 32), bad_day_of_month);
}

TEST_CASE("boostLLgregorian::date supports basic calendar functions") {
	boost::gregorian::date d{ 1986,9,15 };
	REQUIRE(d.year() == 1986);
	REQUIRE(d.month() == 9);
	REQUIRE(d.day() == 15);
	REQUIRE(d.day_of_year() == 258);
	REQUIRE(d.day_of_week() == boost::date_time::Monday);
}