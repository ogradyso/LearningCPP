//#define CATCH_CONFIG_MAIN
//#include "catch.h"
//
//#include <boost/logic/tribool.hpp>
//
//// boost::tribool
//using boost::logic::indeterminate;
//boost::logic::tribool t = true, f = false, i = indeterminate;
//
//TEST_CASE("Boost tribool converts to bool") {
//	REQUIRE(t);
//	REQUIRE_FALSE(f);
//	REQUIRE(!f);
//	REQUIRE_FALSE(!t);
//	REQUIRE(indeterminate(i));
//	REQUIRE_FALSE(indeterminate(t));
//}
//
//TEST_CASE("Boost Tribool supports Boolean operations") {
//	auto t_or_f = t || f;
//	REQUIRE(t_or_f);
//	REQUIRE(indeterminate(t && indeterminate));
//	REQUIRE(indeterminate(f || indeterminate));
//	REQUIRE(indeterminate(!i));
//}
//
//TEST_CASE("Boost Tribool works nicely with if statements") {
//	if (i) FAIL("Indeterminate is true.");
//	else if (!i) FAIL("Indeterminate is false.");
//	else {} // Ok, indeterminate
//}
//
//// std::optional
//#include <optional>
//
//struct TheMatrix {
//	TheMatrix(int x) : iteration{ x } {}
//	const int iteration;
//};
//
//enum Pill { Red, Blue };
//
//std::optional<TheMatrix> take(Pill pill) {
//	if (pill == Pill::Blue) return TheMatrix{ 6 };
//	return std::nullopt;
//}
//
//TEST_CASE("std::optional contains types") {
//	if (auto matrix_opt = take(Pill::Blue)) {
//		REQUIRE(matrix_opt->iteration == 6);
//		auto& matrix = matrix_opt.value();
//		REQUIRE(matrix.iteration == 6);
//	}
//	else {
//		FAIL("The optional evaluated to false.");
//	}
//}
//
//TEST_CASE("std::optional can be empty") {
//	auto matrix_opt = take(Pill::Red);
//	if (matrix_opt) FAIL("The Matrix is not empty.");
//	REQUIRE_FALSE(matrix_opt.has_value());
//}
//
//#include <utility>
//
//struct Socialite { const char* birthname; };
//struct Valet { const char* surname; };
//Socialite bertie{ "Wilberforce" };
//Valet reginald{ "Jeeves" };
//
//TEST_CASE("std::pair permits acces to members") {
//	std::pair<Socialite, Valet> inimitable_duo{ bertie, reginald };
//	REQUIRE(inimitable_duo.first.birthname == bertie.birthname);
//	REQUIRE(inimitable_duo.second.surname == reginald.surname);
//}
//
//TEST_CASE("std::pair works with structured binding") {
//	std::pair<Socialite, Valet> inimitable_duo{ bertie, reginald };
//	auto& [idle_rich, butler] = inimitable_duo;
//	REQUIRE(idle_rich.birthname == bertie.birthname);
//	REQUIRE(butler.surname == reginald.surname);
//}
//
//struct Acquaintance { const char* nickname; };
//Acquaintance hildebrand{ "Tuppy" };
//
//TEST_CASE("std::tuple permits access to members with std::get") {
//	using Trio = std::tuple < Socialite, Valet, Acquaintance>;
//	Trio truculent_trio{ bertie, reginald, hildebrand };
//	auto& bertie_ref = std::get<0>(truculent_trio);
//	REQUIRE(bertie_ref.birthname == bertie.birthname);
//
//	auto& tuppy_ref = std::get<Acquaintance>(truculent_trio);
//	REQUIRE(tuppy_ref.nickname == hildebrand.nickname);
//}
//
//#include <any>
//
//struct EscapeCapsule {
//	EscapeCapsule(int x) : weight_kg{ x } {}
//	int weight_kg;
//};
//
//TEST_CASE("std::any allows us to std::any_cast  into a type") {
//	std::any hagunemnon;
//	hagunemnon.emplace<EscapeCapsule>(600);
//	auto capsule = std::any_cast<EscapeCapsule>(hagunemnon);
//	REQUIRE(capsule.weight_kg == 600);
//	REQUIRE_THROWS_AS(std::any_cast<float>(hagunemnon), std::bad_any_cast);
//}
//
//#include <variant>
//
//struct BugblatterBeast {
//	BugblatterBeast() : is_ravenous{ true }, weight_kg{ 20000 } {}
//	bool is_ravenous;
//	int weight_kg;
//};
//
//std::variant<BugblatterBeast, EscapeCapsule> hagunemnon;
//
//TEST_CASE("std::variant") {
//	std::variant<BugblatterBeast, EscapeCapsule> hagunemnon;
//	REQUIRE(hagunemnon.index() == 0);
//
//	hagunemnon.emplace<EscapeCapsule>(600);
//	REQUIRE(hagunemnon.index() == 1);
//
//	REQUIRE(std::get<EscapeCapsule>(hagunemnon).weight_kg == 600);
//	REQUIRE(std::get<1>(hagunemnon).weight_kg == 600);
//	REQUIRE_THROWS_AS(std::get<0>(hagunemnon), std::bad_variant_access);
//}
//
//TEST_CASE("std::variant with std:visit to call a function") {
//	std::variant<BugblatterBeast, EscapeCapsule> hagunemnon;
//	hagunemnon.emplace<EscapeCapsule>(600);
//	auto lbs = std::visit([](auto& x) {return 2.2 * x.weight_kg; }, hagunemnon);
//	REQUIRE(lbs == 1320);
//}
