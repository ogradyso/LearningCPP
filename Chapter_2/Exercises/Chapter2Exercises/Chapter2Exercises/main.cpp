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

int main() {
	Operation myOperation = Operation::Add;
	Calculator myAddingCalc{ myOperation };
	int sumval = myAddingCalc.calculate(3, 4);
	printf("Sum: %d\n", sumval);

	myOperation = Operation::Subtract;
	Calculator mySubtractingCalc{ myOperation };
	int result = mySubtractingCalc.calculate(3, 4);
	printf("Result: %d\n", result);

	myOperation = Operation::Multiply;
	Calculator myMultiplyingCalc{ myOperation };
	int product = myMultiplyingCalc.calculate(3, 4);
	printf("Product: %d\n", product);

	myOperation = Operation::Divide;
	Calculator myDividingCalc{ myOperation };
	double quotient = myDividingCalc.calculate(3, 4);
	printf("Quotient: %d\n", quotient);

}
