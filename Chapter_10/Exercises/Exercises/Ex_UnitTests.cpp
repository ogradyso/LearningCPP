#define BOOST_TEST_MODULE auto_brake_unit_tests
#include <boost/test/included/unit_test.hpp>
#include "AutoBrake.h"

struct AutoBrakeTest {
	MockServiceBus bus{};
	AutoBrake auto_brake{ bus };
};

BOOST_FIXTURE_TEST_CASE(InitialCarSpeedIsZero, AutoBrakeTest) {
	BOOST_TEST(0 == auto_brake.get_speed_mps());
}

BOOST_FIXTURE_TEST_CASE(InitialSensitivityIsFive, AutoBrakeTest) {
	BOOST_TEST(5 == auto_brake.get_collision_threshold_s());
}

BOOST_FIXTURE_TEST_CASE(SensitivityGreaterThanOne, AutoBrakeTest) {
	BOOST_REQUIRE_THROW(auto_brake.set_collision_threshold_s(0.5L),
		std::exception);
}

BOOST_FIXTURE_TEST_CASE(SpeedIsSaved, AutoBrakeTest) {
	bus.speed_update_callback(SpeedUpdate{ 100L });
	BOOST_TEST(100 == auto_brake.get_speed_mps());
	bus.speed_update_callback(SpeedUpdate{ 50L });
	BOOST_TEST(50 == auto_brake.get_speed_mps());
	bus.speed_update_callback(SpeedUpdate{ 0L });
	BOOST_TEST(0 == auto_brake.get_speed_mps());
}

BOOST_FIXTURE_TEST_CASE(NoAlertWhenNotIminent, AutoBrakeTest) {
	auto_brake.set_collision_threshold_s(2L);
	bus.speed_update_callback(SpeedUpdate{ 100L });
	bus.car_detected_callback(CarDetected{ 1000L,50L });
	BOOST_TEST(0 == bus.commands_published);
}

BOOST_FIXTURE_TEST_CASE(AlertWhenIminent, AutoBrakeTest) {
	auto_brake.set_collision_threshold_s(10L);
	bus.speed_update_callback(SpeedUpdate{ 100L });
	bus.car_detected_callback(CarDetected{ 100L,0L });
	BOOST_TEST(1 == bus.commands_published);
	BOOST_TEST(1L == bus.last_command.time_to_collision_s);
}

BOOST_FIXTURE_TEST_CASE(InitialSpeedLimitIs39, AutoBrakeTest) {
	BOOST_TEST(39 == auto_brake.get_speed_limit());
}