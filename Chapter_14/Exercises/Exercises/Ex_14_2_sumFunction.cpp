//#define CATCH_CONFIG_MAIN
//#include "catch.h"
//
//template<typename openContainer>
//auto sumFun(openContainer valsToSum) {
//	int sumOfVals{};
//	auto itr = valsToSum.begin();
//	while (itr < valsToSum.end()) {
//		sumOfVals += *itr;
//		itr++;
//	}
//	return sumOfVals;
//}
//
//TEST_CASE("sumFun returns the sum of a vector") {
//	std::vector<int> myVals{ 1,4,7,2,5,7 };
//	REQUIRE(sumFun(myVals) == 26);
//}