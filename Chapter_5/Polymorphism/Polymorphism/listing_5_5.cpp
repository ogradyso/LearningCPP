struct BaseClass {};
struct DerivedClass : BaseClass {};
void all_about_that(DerivedClass& derived) {}

//int main() {
//	BaseClass base;
//	//all_about_that(base);  //will not compile becuase derived classes inherit from base class
//	// but not the other way around
//}