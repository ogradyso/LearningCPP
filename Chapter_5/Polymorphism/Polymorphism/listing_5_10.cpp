#include <cstdio>

struct BaseClass {
	virtual ~BaseClass() = default;
};

struct DerivedClass : BaseClass {
	DerivedClass() {
		printf("DerivedClass() invoked.\n");
	}
	~DerivedClass() {  //virtual destructor helps prevent memory leakage
		printf("~DerivedClass() invoked.\n");
	}
};

int main() {
	printf("Constructing DerivedClass x. \n");
	BaseClass* x{ new DerivedClass{} };
	printf("Deleting x as a BaseClass*.\n");
	delete x;
}