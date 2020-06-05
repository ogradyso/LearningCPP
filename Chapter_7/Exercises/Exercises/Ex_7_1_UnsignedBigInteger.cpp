#include <cstdint>
#include <cstdio>
#include <stdexcept>

struct UnsignedBigInteger {
	UnsignedBigInteger(uint64_t byteArray) : internalRepresentation{ byteArray } {	}

	UnsignedBigInteger operator+(uint64_t other) const {
		UnsignedBigInteger result{ (uint64_t)internalRepresentation + (uint64_t)other };
		try {
			if (result.internalRepresentation < internalRepresentation) throw std::runtime_error{ "Overflow!" };
			return result;
		}
		catch(const std::runtime_error& e) {
			printf("UnsignedBigInteger addition resulted in Exception: %s\n", e.what());
		}
		return 0;
	};

	UnsignedBigInteger operator-(unsigned int other) const {
		UnsignedBigInteger result{ (int)internalRepresentation - other };
		if (result.internalRepresentation < internalRepresentation) throw std::runtime_error{ "Overflow!" };
		return result;
	};

	const uint64_t internalRepresentation[];
};


//code does not work.
//int main() {
//	UnsignedBigInteger myBigNumber{ 4 };
//	try {
//		auto newBigNumber = myBigNumber + 500;
//	}
//	catch (const std::overflow_error& e) {
//		printf("(myBigNumber + 500) Exception: %s\n", e.what());
//	}
//
//}