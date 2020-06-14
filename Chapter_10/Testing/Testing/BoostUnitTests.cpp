#define BOOST_TEST_MODULE test_module_name
#include <boost/test/included/unit_test.hpp>
#include "BoostAutoBrake.h"

BOOST_AUTO_TEST_CASE(InitialCarSpeedIsZero) {
	MockServiceBus bus{};
	AutoBrake auto_brake{ bus };
	BOOST_TEST(0 == auto_brake.get_speed_mps());
}