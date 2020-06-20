//#define CATCH_CONFIG_MAIN
//#include "catch.h"
//
//#include <boost/date_time/gregorian/gregorian.hpp>
//
//TEST_CASE("boost::gregorian::date default-constructs to a not_a_date") {
//	boost::gregorian::date d;
//	REQUIRE(d.as_special() == boost::gregorian::not_a_date_time);
//}
//
//TEST_CASE("Invalid boost::gregorian::dates throw exceptions") {
//	using boost::gregorian::date;
//	using boost::gregorian::bad_day_of_month;
//
//	REQUIRE_THROWS_AS(date(1986, 9, 32), bad_day_of_month);
//}
//
//TEST_CASE("boostLLgregorian::date supports basic calendar functions") {
//	boost::gregorian::date d{ 1986,9,15 };
//	REQUIRE(d.year() == 1986);
//	REQUIRE(d.month() == 9);
//	REQUIRE(d.day() == 15);
//	REQUIRE(d.day_of_year() == 258);
//	REQUIRE(d.day_of_week() == boost::date_time::Monday);
//}
//
//TEST_CASE("boost::gregorian::date supports calendar arithmetic") {
//	boost::gregorian::date d1{ 1986, 9, 15 };
//	boost::gregorian::date d2{ 2019, 8, 1 };
//	auto duration = d2 - d1;
//	REQUIRE(duration.days() == 12008);
//}
//
//TEST_CASE("date and date_duration support addition") {
//	boost::gregorian::date d1{ 1986, 9, 15 };
//	boost::gregorian::date_duration dur{ 12008 };
//	auto d2 = d1 + dur;
//	REQUIRE(d2 == boost::gregorian::from_string("2019/8/1"));
//}
//
//TEST_CASE("boost::gregorian::date supports periods") {
//	boost::gregorian::date d1{ 1986,9,15 };
//	boost::gregorian::date d2{ 2019,8,1 };
//	boost::gregorian::date_period p{ d1, d2 };
//	REQUIRE(p.contains(boost::gregorian::date{ 1987,10,27 }));
//}
//
//TEST_CASE("std::chrono supports several clocks") {
//	auto sys_now = std::chrono::system_clock::now();
//	auto hires_now = std::chrono::high_resolution_clock::now();
//	auto steady_now = std::chrono::steady_clock::now();
//
//	REQUIRE(sys_now.time_since_epoch().count() > 0);
//	REQUIRE(hires_now.time_since_epoch().count() > 0);
//	REQUIRE(steady_now.time_since_epoch().count() > 0);
//}
//
//#include <chrono>
//
//TEST_CASE("std::chrono supports several units of measurement") {
//	using namespace std::literals::chrono_literals;
//	auto one_s = std::chrono::seconds(1);
//	auto thousand_ms = 1000ms;
//	REQUIRE(one_s == thousand_ms);
//}
//
////casting durations:
//TEST_CASE("std::chrono supports duration_cast") {
//	using namespace std::chrono;
//	auto billion_ns_as_s = duration_cast<seconds>(1'000'000'000ns);
//	REQUIRE(billion_ns_as_s.count() == 1);
//}
//
//#include <thread>
//TEST_CASE("std::chrono used to sleep") {
//	using namespace std::literals::chrono_literals;
//	auto start = std::chrono::system_clock::now();
//	std::this_thread::sleep_for(100ms);
//	auto end = std::chrono::system_clock::now();
//	REQUIRE(end - start >= 100ms);
//}
//
////timing for optimization:
//struct Stopwatch {
//	Stopwatch(std::chrono::nanoseconds& result)
//		: result{result},
//		start{ std::chrono::high_resolution_clock::now() } {}
//	~Stopwatch() {
//		result = std::chrono::high_resolution_clock::now() - start;
//	}
//private:
//	std::chrono::nanoseconds& result;
//	const std::chrono::time_point<std::chrono::high_resolution_clock> start;
//};
//
//#include <cstdio>
//#include <cstdint>
//
////int main() {
////	const size_t n = 1'000'000;
////	std::chrono::nanoseconds elapsed;
////	{
////		Stopwatch stopwatch{ elapsed };
////		volatile double result{ 1.23e45 };
////		for (double i = 1; i < n; i++) {
////			result /= i;
////		}
////	}
////	auto time_per_division = elapsed.count() / double{ n };
////	printf("Took %gns per division.", time_per_division);
////}