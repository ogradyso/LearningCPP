#include <stdexcept>

struct CheckedInteger {
	CheckedInteger(unsigned int value) : value{value} {}

	CheckedInteger operator+(unsigned int other) const {
		CheckedInteger result{ value + other };
		if (result.value < value) throw std::runtime_error{ "Overflow!" };
		return result;
	}
	const unsigned int value;
};