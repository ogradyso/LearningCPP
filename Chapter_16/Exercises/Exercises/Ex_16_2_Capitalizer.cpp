#include <iostream>
#include <algorithm>
#include <string>

int main() {
	std::string str;
	std::cout << "Please enter some input to capitalize: ";
	std::cin >> str;
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	std::cout << str;
}