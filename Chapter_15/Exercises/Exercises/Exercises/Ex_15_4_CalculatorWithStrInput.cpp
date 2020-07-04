#define CATCH_CONFIG_MAIN
#include "catch.h"

#include <cstdio>

enum class Operation {
	Add,
	Subtract,
	Multiply,
	Divide
};

struct Calculator {
	Calculator(Operation someMath) {
		mathToDo = someMath;
	}
	int calculate(int a, int b) {
		switch (mathToDo) {
		case Operation::Add: {
			return a + b;
		} break;
		case Operation::Subtract: {
			return a - b;
		}break;
		case Operation::Multiply: {
			return a * b;
		} break;
		case Operation::Divide: {
			return a / b;
		} break;
		default: {
			printf("This program does not recognize the operation.");
		}
		}
	}
private:
	Operation mathToDo;
};

TEST_CASE("Calculator "){
	SECTION("performs addition, subtraction, multiplication, and division") {
	Operation myOperation = Operation::Add;
	Calculator myCalc{ myOperation };
	REQUIRE(myCalc.calculate(3, 4) == 7);
	myOperation = Operation::Subtract;
	Calculator mySub{ myOperation };
	REQUIRE(mySub.calculate(3, 4) == -1);
	myOperation = Operation::Multiply;
	Calculator myMult{ myOperation };
	REQUIRE(myMult.calculate(3, 4) == 12);
	myOperation = Operation::Divide;
	Calculator myDiv{ myOperation };
	REQUIRE(myDiv.calculate(12, 3) == 4);

	}
	SECTION("takes string input ") {

	}
}