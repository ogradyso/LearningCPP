#include <cstdint>

constexpr uint8_t max(uint8_t a, uint8_t b) {
	return a > b ? a : b;
}

constexpr uint8_t max(uint8_t a, uint8_t b, uint8_t c) {
	return max(max(a,b), max(a,c));
}

constexpr uint8_t min(uint8_t a, uint8_t b) {
	return a < b ? a : b;
}

constexpr uint8_t min(uint8_t a, uint8_t b, uint8_t c) {
	return min(min(a, b), min(a, c));
}

constexpr float modulo(float dividend, float divisor) {
	const auto quotient = dividend / divisor;
	return divisor * (quotient - static_cast<uint8_t>(quotient));
}