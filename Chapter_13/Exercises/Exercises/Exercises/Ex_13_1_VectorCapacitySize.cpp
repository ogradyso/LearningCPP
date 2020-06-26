//#define CATCH_CONFIG_MAIN
//#include "catch.h"
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//int fibonacciCalculator(int n) {
//	int last;
//	int previous;
//	if ((n == 1)||(n==0)) {
//		return n;
//	}
//	else {
//		return  fibonacciCalculator(n - 1) + fibonacciCalculator(n - 2);
//	}
//}
//
//int main() {
//	vector<ULONG> ulMyVector{};
//
//	cout <<"Capacity: " << ulMyVector.capacity() << endl;
//
//	ulMyVector.reserve(10);
//	for (int i{1}; i < 21; i++) {
//		ulMyVector.push_back(fibonacciCalculator(i));
//	}
//	cout << "Capacity: " << ulMyVector.capacity() << endl;
//	for (int i{ 0 }; i < ulMyVector.size(); i++) {
//		cout << "Number "<< i+1 << ": " << ulMyVector[i] << endl;
//	}
//
//}
