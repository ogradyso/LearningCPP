#include <cstddef>

double mean(const double* values, size_t length) {
	double result{};
	for (size_t i{}; i < length; i++) {
		result += values[i];
	}
	return result / length;
}