#include <stdexcept>

template <typename To, typename From>
To narrow_cast(From value) {
	const auto converted = static_cast<To>(value);
	const auto backwards = static_cast<From>(converted);
	if (value != backwards) throw std::runtime_error{ "Narrowed!" };
	return converted;
}