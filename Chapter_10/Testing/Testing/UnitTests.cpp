#include "AutoBrake.cpp"
#include <stdexcept>

constexpr void assert_that(bool statement, const char* message) {
	if (!statement) throw std::runtime_error{ message };
}

void initial_speed_is_zero() {
	MockServiceBus bus{};
	AutoBrake auto_brake{ bus };
	assert_that(auto_brake.get_speed_mps() == 0L, "Speed not equal to 0.");
}

void initial_sensitivity_is_five() {
	MockServiceBus bus{};
	AutoBrake auto_brake{ bus };
	assert_that(auto_brake.get_collision_threshold_s() == 5L, "sensitivity is not 5");
}

void sensitivity_greater_than_1() {
	MockServiceBus bus{};
	AutoBrake auto_brake{ bus };
	try {
		auto_brake.set_collision_threshold_s(0.5L);
	} catch (const std::exception&) {
		return;
	}
	assert_that(false, "no exception thrown");
}

void speed_is_saved() {
	MockServiceBus bus{};
	AutoBrake auto_brake{ bus };

	bus.speed_update_callback(SpeedUpdate{ 100L });
	assert_that(100L == auto_brake.get_speed_mps(), "speed not saved to 100");
	bus.speed_update_callback(SpeedUpdate{ 50L });
	assert_that(50L == auto_brake.get_speed_mps(), "speed not saved to 50");
	bus.speed_update_callback(SpeedUpdate{ 0L });
	assert_that(0L == auto_brake.get_speed_mps(), "speed not saved to 0");
	
}

void run_test(void(*unit_test)(), const char* name) {
	try {
		unit_test();
		printf("[+] Test %s successful.\n", name);
	}
	catch (const std::exception& e) {
		printf("[-] Test failure in %s. %s. \n", name, e.what());
	}
}

void alert_when_iminent() {
	MockServiceBus bus{};
	AutoBrake auto_brake{ bus };
	auto_brake.set_collision_threshold_s(10L);
	bus.speed_update_callback(SpeedUpdate{ 100L });
	bus.car_detected_callback(CarDetected{ 100L, 0L });
	assert_that(bus.commands_published == 1, "1 brake command was not published");
	assert_that(bus.last_command.time_to_collision_s == 1L,
		"time to collision not computed correctly.");
}

void no_alert_when_not_iminent() {
	MockServiceBus bus{};
	AutoBrake auto_brake{ bus };
	auto_brake.set_collision_threshold_s(2L);
	bus.speed_update_callback(SpeedUpdate{ 100L });
	bus.car_detected_callback(CarDetected{ 1000L, 50L });
	assert_that(bus.commands_published == 0, "brake commands were published");
}

int main() {
	run_test(initial_speed_is_zero, "initial speed is zero");
	run_test(initial_sensitivity_is_five, "initial sensitivity is 5");
	run_test(sensitivity_greater_than_1, "sensitivity greater than 1");
	run_test(speed_is_saved, "speed is saved.");
	run_test(alert_when_iminent, "alert when iminent");
	run_test(no_alert_when_not_iminent, "no alert when not iminent");
}