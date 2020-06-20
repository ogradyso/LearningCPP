//#define CATCH_CONFIG_MAIN
//#include "catch.h"
//
//#include <stdexcept>
//#include <optional>
//template <typename To, typename From>
//std::optional<To> narrow_cast(From value) {
//	const auto converted = static_cast<To>(value);
//	const auto backwards = static_cast<From>(converted);
//	if (value != backwards) return std::nullopt;
//	return converted;
//}
//
//
//TEST_CASE("narrow_cast takes a std::optional") {
//	int myNum{ 5 };
//	REQUIRE(bool{narrow_cast<double>(myNum)});
//}
//
//TEST_CASE("narrow_cast returns an empty value when narrow cast is made") {
//	int myNum{ 12895734 };
//	auto outputAnswer = narrow_cast<short>(myNum);
//	REQUIRE_FALSE(outputAnswer.has_value());
//}

//int main() {
//	int perfect{ 496 };
//	const auto perfect_short = narrow_cast<short>(perfect);
//	printf("perfect_short: %d\n", perfect_short);
//	try {
//		int cyclic{ 142857 };
//		const auto cyclic_short = narrow_cast<short>(cyclic);
//		printf("cyclci_short: %d\n", cyclic_short);
//	}
//	catch (const std::runtime_error& e) {
//		printf("Exception: %s\n", e.what());
//	}
//}