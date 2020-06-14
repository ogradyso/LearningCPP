#pragma once
#define BOOST_TEST_MODULE AutoBrakeTest
#include <boost/test/unit_test.hpp>
#include <exception>
#include <functional>

struct SpeedUpdate {
	double velocity_mps;
};

struct CarDetected {
	double distance_m;
	double velocity_mps;
};

struct BrakeCommand {
	double time_to_collision_s;
};

using SpeedUpdateCallback = std::function<void(const SpeedUpdate&)>;
using CarDetectedCallback = std::function<void(const CarDetected&)>;

struct IServiceBus {
	virtual ~IServiceBus() = default;
	virtual void publish(const BrakeCommand&) = 0;
	virtual void subscribe(SpeedUpdateCallback) = 0;
	virtual void subscribe(CarDetectedCallback) = 0;
};

//mock service bus:
struct MockServiceBus : IServiceBus {
	void publish(const BrakeCommand& cmd) override {
		commands_published++;
		last_command = cmd;
	}
	void subscribe(SpeedUpdateCallback callback) override {
		speed_update_callback = callback;
	}
	void subscribe(CarDetectedCallback callback) override {
		car_detected_callback = callback;
	}
	BrakeCommand last_command{};
	int commands_published{};
	SpeedUpdateCallback speed_update_callback{};
	CarDetectedCallback car_detected_callback{};
};

struct AutoBrake {
	AutoBrake(IServiceBus& bus)
		: collision_threshold_s{ 5 }/*,
		speed_mps{ 0 }*/ {
		bus.subscribe([this](const SpeedUpdate& update) {
			speed_mps = update.velocity_mps;
			});
		bus.subscribe([this, &bus](const CarDetected& cd) {
			const auto relative_velocity_mps = speed_mps - cd.velocity_mps;
			const auto time_to_collision_s = cd.distance_m / relative_velocity_mps;
			if (time_to_collision_s > 0 &&
				time_to_collision_s <= collision_threshold_s) {
				bus.publish(BrakeCommand{ time_to_collision_s });
			}
			});
	}
	void set_collision_threshold_s(double x) {
		if (x < 1)
			throw std::exception{ "Collision less than 1" };
		collision_threshold_s = x;
	}
	double get_collision_threshold_s() const {
		return collision_threshold_s;
	}
	double get_speed_mps() const {
		return speed_mps;
	}

private:
	double collision_threshold_s;
	double speed_mps;
};