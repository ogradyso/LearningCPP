#include <ctime>
#pragma warning(disable: 4996)


struct TimerClass {
	TimerClass() {
		std::time_t timestamp = std::time(nullptr);
	}
private:
	time_t timestamp;
};

//int main() {
//	TimerClass myTimer;
//
//}