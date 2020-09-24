//helper function which will be imported into the C++Quest Game
#include "tinyxml2.h"
#include "tinyxml2.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != tinyxml2::XML_SUCCESS) {printf("Error: %i\n", a_eResult); return "Error parsing XML";}
#endif

std::string getNextPrompt(const char* gameFilePath) {
	tinyxml2::XMLDocument xmlDoc;

	tinyxml2::XMLError eResult = xmlDoc.LoadFile(gameFilePath);

	XMLCheckResult(eResult);

	//xtracting data from an XMLDocument:
	tinyxml2::XMLNode* pRoot = xmlDoc.FirstChild();

	if (pRoot == nullptr) std::cout << tinyxml2::XML_ERROR_FILE_READ_ERROR << "\n"; return "Error Loading XML file";

	//get a single element by name:
	tinyxml2::XMLElement* pElement = pRoot->FirstChildElement("IntValue");
	if (pElement == nullptr) std::cout << tinyxml2::XML_ERROR_FILE_READ_ERROR << "\nNull pointer found while parsing XML.\n"; return "Error Loading XML file";

	int iOutInt;
	eResult = pElement->QueryIntText(&iOutInt);
	XMLCheckResult(eResult);
};


int main() {
	char gameFilePath[] = { 'L','e','a','r','n','e','r','L','e','s','s','o','n','s','.','x','m','l'};
	std::string lessonName = getNextPrompt(gameFilePath);
}
