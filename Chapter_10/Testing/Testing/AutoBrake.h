#pragma once
#include <exception>
#include <functional>

using SpeedUpdateCallback = std::function<void(const SpeedUpdate&)>;
using CarDetectedCallback = std::function<void(const CarDetected&)>;

struct IServiceBus {
	virtual ~IServiceBus() = default;
	virtual void publish(const BrakeCommand&) = 0;
	virtual void subscribe(SpeedUpdateCallback) = 0;
	virtual void subscribe(CarDetectedCallback) = 0;
};

struct SpeedUpdate {
	double velocity_mps;
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


struct CarDetected {
	double distance_m;
	double velocity_mps;
};

struct BrakeCommand {
	double time_to_collision_s;
};

template <typename T>
struct AutoBrake {
	AutoBrake(const T& publish)
		: collision_threshold_s{ 5 },
		speed_mps{ 0 },
		publish{ publish } {}
	void observe(const SpeedUpdate& x) {
		speed_mps = x.velocity_mps;
	};
	void observe(const CarDetected& cd) {
		const auto relative_velocity_mps = speed_mps - cd.velocity_mps;
		const auto time_to_collision_s = cd.distance_m / relative_velocity_mps;
		if (time_to_collision_s > 0 &&
			time_to_collision_s <= collision_threshold_s) {
			publish(BrakeCommand{ time_to_collision_s });
		}
	};
	void set_collision_threshold_s(double x) {
		if (x < 1) 
			throw std::exception{ "Collision less than 1" };
		collision_threshold_s = x;
	}
	double get_collision_threshold_s() const {
		return collision_threshold_s;
	}
	double get_speed_mps() const{
		return speed_mps;
	}
private:
	double collision_threshold_s;
	double speed_mps;
	const T& publish;
};
