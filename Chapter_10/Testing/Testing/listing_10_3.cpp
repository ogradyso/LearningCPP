

struct SpeedUpdate {
	double Velocity_mps;
};

struct CarDetected {
	double distance_m;
	double velocity_mps;
};

struct BrakeCommand {
	double time_to_collision_s;
};

struct ServiceBus {
	void publish(const BrakeCommand&);
	//add code here
};

template <typename T>
struct AutoBrake {
	AutoBrake(const T& publish);
	void observe(const SpeedUpdate&);
	void observe(const CarDetected&);
private:
	const T& publish;
	//add code here
};

//int main() {
//	ServiceBus bus;
//	AutoBrake auto_brake{ [&bus](const auto& cmd) {
//							bus.publish(cmd);
//						}
//	};
//	while (true) { //Service bus's event loop
//		auto_brake.observe(SpeedUpdate{ 10L });
//		auto_brake.observe(CarDetected{ 250L, 25L });
//	}
//}