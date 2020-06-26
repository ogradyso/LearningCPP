//#define CATCH_CONFIG_MAIN
//#include "catch.h"
//#include <set>
//
//using namespace std;

//int char_type(const char x) {
//	if (isupper(x)) {
//		return 0;
//	}
//	if (islower(x)) {
//		return 1;
//	}
//	if (isdigit(x)) {
//		return 2;
//	}
//	return 3;
//}
//
//int CharCompare(const char x, const char y) {
//	if (char_type(x) == char_type(y)) {
//		return (x < y);
//	}
//	else return char_type(x) > char_type(y);
//}
//
//struct CharStarCompare {
//	bool operator() (const char* lhs, const char* rhs) const {
//		int iteleft = 0;
//		int iteright = 0;
//		//compare each character in	 strings
//		while (lhs[iteleft] != NULL && rhs[iteright] != NULL) {
//			if (lhs[iteleft] < rhs[iteright]) return true;
//			if (lhs[iteleft] > rhs[iteright]) return false;
//			iteleft++;
//			iteright++;
//		}
//		return true;
//	}
//};
//
//
//int main(int argc, char** argv) {
//	set<const char*, CharStarCompare> arguments{};
//	for (size_t i{1}; i < argc; i++) {
//		arguments.insert(argv[i]);
//	}
//	for (auto iter = arguments.begin(); iter != arguments.end(); ++iter) {
//		cout << *iter << endl;
//	}
//}