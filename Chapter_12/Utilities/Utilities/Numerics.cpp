#define CATCH_CONFIG_MAIN
#include "catch.h"

#include <complex>

TEST_CASE("std::complex has a real and imaginary component") {
	std::complex<double> a{ 0.5, 14.13 };
	REQUIRE(std::real(a) == Approx(0.5));
	REQUIRE(std::imag(a) == Approx(14.13));
}

#include <cmath>
#include <boost/math/constants/constants.hpp>

TEST_CASE("boost::math offers constants") {
	using namespace boost::math::double_constants;
	auto sphere_volume = four_thirds_pi * std::pow(10, 3);
	REQUIRE(sphere_volume == Approx(4188.7902047));
}

#include <random>

TEST_CASE("mt19937_64 is pseudorandom") {
	std::mt19937_64 mt_engine{ 91586 };
	REQUIRE(mt_engine() == 8346843996631475880);
	REQUIRE(mt_engine() == 2237671392849523263);
	REQUIRE(mt_engine() == 7333164488732543658);
}

TEST_CASE("std::random_device is invocable") {
	std::random_device rd_engine{};
	REQUIRE_NOTHROW(rd_engine());
}

TEST_CASE("std::uniform_int_distribution produces uniform ints") {
	std::mt19937_64 mt_engine{ 102787 };
	std::uniform_int_distribution<int> int_d{ 0,10 };
	const size_t n{ 1'000'000 };
	int sum{};
	for (size_t i{}; i < n; i++)
		sum += int_d(mt_engine);
	const auto sample_mean = sum / double{ n };
	REQUIRE(sample_mean == Approx(5).epsilon(.1));
}

#include <limits>

TEST_CASE("std::numeric_limits::min provides the smallest finite value.") {
	auto my_cup = std::numeric_limits<int>::min();
	auto underfloweth = my_cup - 1;
	REQUIRE(my_cup < underfloweth);
}

#include <boost/numeric/conversion/converter.hpp>
using double_to_int = boost::numeric::converter<int, double>;

TEST_CASE("boost::converter offers the static method convert") {
	REQUIRE(double_to_int::convert(3.14159) == 3);
}

TEST_CASE("boost::numeric::converter implements operator()") {
	double_to_int dti;
	REQUIRE(dti(3.14159) == 3);
	REQUIRE(double_to_int{}(3.14159) == 3);
}

TEST_CASE("boost::numeric::converter checks for overflow") {
	auto yuge = std::numeric_limits<double>::max();
	double_to_int dti;
	REQUIRE_THROWS_AS(dti(yuge), boost::numeric::positive_overflow);
}

#include <boost/numeric/conversion/cast.hpp>

TEST_CASE("boost::boost::numeric_cast checks overflow") {
	auto yuge = std::numeric_limits<double>::max();
	REQUIRE_THROWS_AS(boost::numeric_cast<int>(yuge),
		boost::numeric::positive_overflow);
}

#include <ratio>

TEST_CASE("std::ratio") {
	using ten = std::ratio<10, 1>;
	using two_thirds = std::ratio<2, 3>;
	using result = std::ratio_multiply<ten, two_thirds>;
	REQUIRE(result::num == 20);
	REQUIRE(result::den == 3);
}