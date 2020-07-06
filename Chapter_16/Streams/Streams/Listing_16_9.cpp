//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//template <typename T>
//ostream& operator<<(ostream& s, vector<T> v) {
//	s << "Size: " << v.size()
//		<< "\nCapacity: " << v.capacity()
//		<< "\nELements: \n";
//	for (const auto& element : v)
//		s << "\n" << element << "\n";
//	return s;
//}
//
//int main() {
//	const vector<string> characters{
//		"Bobby Shaftoe",
//		"Lawerence Waterhouse",
//		"Gunter Bischoff",
//		"Earl Comstock"
//	};
//	cout << characters << endl;
//
//	const vector<bool> bits{ true, false, true, false };
//	cout << boolalpha << bits << endl;
//}