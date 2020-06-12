#include "AutoBrake.cpp"
#include <stdexcept>

constexpr void assert_that(bool statement, const char* message) {
	if (!statement) throw std::runtime_error{ message };
}



void initial_speed_is_zero() {
	AutoBrake auto_brake{ [](const BrakeCommand&) {} };
	assert_that(auto_brake.get_speed_mps() == 0L, "Speed not equal to 0.");
}

int main() {
	assert_that(1 + 2 > 2, "Something is profoundly wrong with the universe.");
	assert_that(24 == 42, "This assertion will generate an exception.");
}