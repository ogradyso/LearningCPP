#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <boost/smart_ptr/scoped_ptr.hpp>

struct DeadMenOfDunharrow {
	DeadMenOfDunharrow(const char* m = "")
		: message{ m } {
		oaths_to_fulfill++;
	}
	~DeadMenOfDunharrow() {
		oaths_to_fulfill--;
	}
	const char* message;
	static int oaths_to_fulfill;
};

int DeadMenOfDunharrow::oaths_to_fulfill{};
using ScopedOathbreakers = boost::scoped_ptr<DeadMenOfDunharrow>;

TEST_CASE("ScopedPtr evaluates to") {
	SECTION("true when full") {
		ScopedOathbreakers aragorn{ new DeadMenOfDunharrow{} };
		REQUIRE(aragorn);
	}
	SECTION("false when empty") {
		ScopedOathbreakers aragorn;
		REQUIRE_FALSE(aragorn);
	}
}

TEST_CASE("ScopedPtr is an RAII wrapper.") {
	REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 0);
	ScopedOathbreakers aragorn{ new DeadMenOfDunharrow{} };
	REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1); 
	{
		ScopedOathbreakers legolas{ new DeadMenOfDunharrow{} };
		REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 2);
	}
	REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
}

TEST_CASE("ScopedPtr supports pointer semantics, like") {
	auto message = "The way is shut";
	ScopedOathbreakers aragorn{ new DeadMenOfDunharrow{message} };
	SECTION("operator*") {
		REQUIRE((*aragorn).message == message);
	}
	SECTION("operator->") {
		REQUIRE(aragorn->message == message);
	}
	SECTION("get(), which returns a raw pointer") {
		REQUIRE(aragorn.get() != nullptr);
	}
}

TEST_CASE("ScopedPtr supports comparison with nullptr") {
	SECTION("operator==") {
		ScopedOathbreakers legolas{};
		REQUIRE(legolas == nullptr);
	}
	SECTION("operator!=") {
		ScopedOathbreakers aragorn{ new DeadMenOfDunharrow{} };
		REQUIRE(aragorn != nullptr);
	}
}

TEST_CASE("ScopedPtr supports swap") {
	auto message1 = "The way is shut.";
	auto message2 = "Until the time comes.";
	ScopedOathbreakers aragorn{
		new DeadMenOfDunharrow{message1}
	};
	ScopedOathbreakers legolas{
		new DeadMenOfDunharrow{message2}
	};
	aragorn.swap(legolas);
	REQUIRE(legolas->message == message1);
	REQUIRE(aragorn->message == message2);
}

TEST_CASE("ScopedPtr reset") {
	ScopedOathbreakers aragorn{ new DeadMenOfDunharrow{} };
	SECTION("destructs owned object.") {
		aragorn.reset();
		REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 0);
	}
	SECTION("can replace an owned object.") {
		auto message = "It was made by those who are Dead.";
		auto new_dead_men = new DeadMenOfDunharrow{ message };
		REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 2);
		aragorn.reset(new_dead_men);
		REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
		REQUIRE(aragorn->message == new_dead_men->message);
		REQUIRE(aragorn.get() == new_dead_men);
	}
}