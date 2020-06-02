#include <cstdio>
#include <type_traits>

template<typename T>
T mode(T* values, size_t length) {
	static_assert(!std::is_floating_point<T>(),
		"Type cannot be floating point.");
	int currentMode = 0;
	int modeCount = 0;
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
//	int arr[10] = { 1,2,4,4,2,2,5,2,7,5 };
//	size_t arrLength = sizeof(arr) / sizeof(int);
//	int arrMode = mode<int>(arr, arrLength);
//	printf("Mode is: %d", arrMode);
//
//	float arr2[4] = { 5.0, 6.5, 3.2, 1.1 };
//	size_t arr2Length = sizeof(arr2) / sizeof(float);
//	float arrMode2 = mode<float>(arr2, arr2Length);
//}