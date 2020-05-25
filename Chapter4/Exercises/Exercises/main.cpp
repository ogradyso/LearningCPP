#include <ctime>
#include <cstdio>
#include <utility>
#pragma warning(disable: 4996)


struct TimerClass {
	TimerClass(const char* myName)
		: name{ myName } {
		//time_t timestamp;
		time(&timestamp);
		printf("Seconds since January 1, 1970 = %lld\n", ((((timestamp/60)/60)/24)/365));
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
			//printf("%s has been moved. No age data available.", name);
		}
		else {
			time_t timeOfDeath;
			time(&timeOfDeath);
			//printf("Seconds since January 1, 1970 = %lld\n", timeOfDeath);
			double ageOfObject = difftime(timeOfDeath, timestamp);
			printf("%s was alive for %f secs.\n", name, ageOfObject);
		}
	}

private:
	time_t timestamp;
	const char* name;
};

void someArbitraryMath() {
	long long num1 = 50000000;
	long long num2 = 0;
	for (long long i = 0; i <= 50000; i++) {
		for (long long j = 0; j <= 50000; j++) {
			num2 = num2 + j;
		}
	}
}

int main() {
	TimerClass myTimer("a");
	TimerClass mySecondTimer("b");
	someArbitraryMath();

	

}