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