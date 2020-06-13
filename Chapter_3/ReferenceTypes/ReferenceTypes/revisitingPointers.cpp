#include <iostream>
using namespace std;

int main() {
	int someArray[10] = { 3,6,9,12,15,18,21,24,27,30 };

	int* pLocation6 = &someArray[6];
	int* pLocation0 = &someArray[0];  /// same as int *pLocation0 = someArray;

	/*cout << "Some array index 6" << (int)pLocation6 << endl;
	cout << "Some array index 0" << (int)pLocation0 << endl;
	cout << "Difference" << pLocation6 - pLocation0 << endl;
	cout << endl;

	size_t numElements = sizeof(someArray) / sizeof(int);
	for (size_t i{}; i < numElements; i++) {
		cout << someArray[i] << endl;
	}*/

	//size_t numElements = sizeof(someArray) / sizeof(int);
	////print memory addresses and values:
	//for (size_t i{}; i < numElements; i++) {
	//	//cout << someArray + i << " = " << *(someArray + i) << endl;
	//	
	//	cout << pLocation0 << " = " << *pLocation0 << endl;
	//	pLocation0++;
	//}

	/*char SomeString[] = "Hello!";
	char* pSomeString = SomeString;
	cout << "pSomeString = " << SomeString << endl;

	char* pLocation3 = &SomeString[3];
	char* pLocation0 = &SomeString[0];

	cout << "pLocation3 = " << (int)pLocation3 << endl;
	cout << "pLocation0 = " << (int)pLocation0 << endl;*/

	struct sSomeObject {
		int x = 0xA3A2A1A0;
		int y = 0xB3B2B1B0;
	};

	//Stack allocation (compile time)
	sSomeObject pSomeObject[10];

	//Heap allocation (runtime

	cout << endl; system("pause"); return 0;
}