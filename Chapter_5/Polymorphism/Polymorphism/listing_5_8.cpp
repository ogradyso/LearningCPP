#include <cstdio>

struct BaseClass {
	virtual const char* final_message() const =0;  //=0 suffixe combined with virtual creates a pure virtual member
};

struct DerivedClass : BaseClass {
	const char* final_message() const override {
		return "We aplogize for the inconvenience.";
	}
};

//int main() {
//	//BaseClass base; //will not work; cannot initialize a base class with pure virtual methods
//	DerivedClass derived;
//	BaseClass& ref = derived;
//	printf("DerivedClass: %s\n", derived.final_message());
//	printf("BaseClass&:   %s\n", ref.final_message());
//}