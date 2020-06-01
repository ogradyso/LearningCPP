#include <stdexcept>

int& get(int(&arr)[10], size_t index) {
	if (index >= 10) throw std::out_of_range{ "Out of bounds" };
	return arr[index];
}