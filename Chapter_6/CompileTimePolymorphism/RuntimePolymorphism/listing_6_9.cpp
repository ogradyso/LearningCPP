#include <cstddef>

long mean(const long* values, size_t length) {
	long result{};
	for (size_t i{}; i < length; i++) {
		result += values[i];
	}
	return result / length;
}