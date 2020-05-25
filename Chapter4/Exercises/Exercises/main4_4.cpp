#include <ctime>
#include <cstdio>
#include <utility>
#pragma warning(disable: 4996)


struct TimerClass {
	TimerClass() {
		time_t timestamp;
		timestamp = time(NULL);
		//printf("Seconds since January 1, 1970 = %lld\n", ((((timestamp/60)/60)/24)/365));
	}
	//copy constructor:
	TimerClass(const TimerClass& other) {
		timestamp = other.timestamp;
	}
	// copy assignment
	TimerClass& operator=(const TimerClass& other) {
		if (this == &other) return *this;
		timestamp = 0;
		timestamp = other.timestamp;
		return *this;
	}
	// move constructor:
	TimerClass(TimerClass&& other) noexcept {
		timestamp = other.timestamp;
		other.timestamp = 0;
	}
	//move assignment:
	TimerClass& operator=(TimerClass&& other) noexcept {
		if (this == &other) return *this;
		timestamp = 0;
		timestamp = other.timestamp;
		return *this;
	}
	~TimerClass() {
		time_t timeOfDeath = time(0);
		//printf("Seconds since January 1, 1970 = %lld\n", timeOfDeath);
		long long ageOfObject = difftime(timeOfDeath, timestamp);
		printf("The object was alive for %lld secs.", (long long)ageOfObject);
	}
private:
	time_t timestamp;
};

int main() {
	TimerClass myTimer;
	TimerClass mySecondTimer;

	mySecondTimer = std::move(myTimer);



}