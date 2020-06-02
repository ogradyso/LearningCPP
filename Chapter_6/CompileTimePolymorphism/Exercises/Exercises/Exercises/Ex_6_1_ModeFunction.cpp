#include <cstdio>

int mode(const int* values, size_t length) {
	int currentMode =0;
	int modeCount =0;
	int currentCount = 0;

	for (size_t i{}; i < length; i++) {
		printf("Counting all %ds\n", values[i]);
		currentCount = 0;
		for (size_t j{}; j < length; j++) {
			printf("Current value: %d\n", values[j]);
			if (i != j || values[j] != currentMode) {
				if (values[i] == values[j]) {
					currentCount++;
				}
			}
		}
		if (currentCount > modeCount) {
			currentMode = values[i];
			modeCount = currentCount;
		}
		else if (currentCount == modeCount) {
			currentMode = 0;
		}
	}

	return currentMode;
}

//int main() {
//	int arr[10] = { 1,2,4,4,2,2,5,4,7,5 };
//	size_t arrLength = sizeof(arr) / sizeof(int);
//	int arrMode = mode(arr, arrLength);
//	printf("Mode is: %d", arrMode);
//}