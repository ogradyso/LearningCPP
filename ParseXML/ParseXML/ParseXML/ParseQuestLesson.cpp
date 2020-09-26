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

std::vector<std::string> getLessonPrompts(const char* gameFilePath) {
	tinyxml2::XMLDocument xmlDoc;

	tinyxml2::XMLError eResult = xmlDoc.LoadFile(gameFilePath);

	//XMLCheckResult(eResult);

	//xtracting data from an XMLDocument:
	tinyxml2::XMLNode* pRoot = xmlDoc.FirstChild();

	//if (pRoot == nullptr) std::cout << tinyxml2::XML_ERROR_FILE_READ_ERROR << "\n"; return "Error Loading XML file";

	//get the elements of a list: 
	//requires a vector in the XML document:

	//tinyxml2::XMLElement* pElement = pRoot->FirstChildElement("LessonPrompts");
	//if (pElement == nullptr) return tinyxml2::XML_ERROR_PARSING_ELEMENT;

	tinyxml2::XMLElement *pListElement = pRoot->FirstChildElement("LessonPrompts");
	std::vector<std::string> vecList;

	while (pListElement != nullptr)
	{
		std::string prompt;
		prompt = pListElement->GetText();
		//XMLCheckResult(eResult);

		vecList.push_back(prompt);

		pListElement = pListElement->NextSiblingElement("Prompt");
	}
	return vecList;
	
};


int main() {
	char gameFilePath[] = { 'L','e','s','s','o','n','1','.','x','m','l'};
	std::string lessonName = "prompt";
	const char* charPtrLessonName = lessonName.c_str();
	std::vector<std::string> lessonPrompts = getLessonPrompts(gameFilePath);
	for (auto prompt : lessonPrompts) 
	{
		std::cout << prompt << "\n";
	}
}


