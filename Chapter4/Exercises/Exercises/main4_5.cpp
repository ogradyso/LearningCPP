#include <ctime>
#include <cstdio>
#include <utility>
#pragma warning(disable: 4996)


struct TimerClass {
	TimerClass(const char* myName)
		: name{ myName } {
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
		other.timestamp = 0;
		return *this;
	}
	~TimerClass() {
		if (timestamp == 0) {
			printf("%s has been moved. No age data available.", name);
		}
		else {
			time_t timeOfDeath = time(0);
			//printf("Seconds since January 1, 1970 = %lld\n", timeOfDeath);
			long long ageOfObject = difftime(timeOfDeath, timestamp);
			printf("%s was alive for %lld secs.\n", name, (long long)ageOfObject);
		}
	}
private:
	time_t timestamp;
	const char* name;
};

int main() {
	TimerClass myTimer("a");
	TimerClass mySecondTimer("b");

	mySecondTimer = std::move(myTimer);
	return 0;

}