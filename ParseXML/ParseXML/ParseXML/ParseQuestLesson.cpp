//helper function which will be imported into the C++Quest Game
#include "tinyxml2.h"
#include "tinyxml2.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != tinyxml2::XML_SUCCESS) {printf("Error: %i\n", a_eResult); return a_eResult;}
#endif

std::vector<std::string> getLessonPrompts(const char* lessonRoot,const char* lessonLevel, const char* gameFilePath) {
	tinyxml2::XMLDocument xmlDoc;

	tinyxml2::XMLError eResult = xmlDoc.LoadFile("IntroLessons.xml");

	//XMLCheckResult(eResult);

	//xtracting data from an XMLDocument:
	tinyxml2::XMLNode* LessonRoot = xmlDoc.FirstChildElement(lessonRoot);
	std::vector<std::string> vecList;
	//if (LessonRoot == nullptr) std::cout << tinyxml2::XML_ERROR_FILE_READ_ERROR << "\n"; vecList.push_back("Error"); return vecList;
	
	//get the elements of a list: 
	//requires a vector in the XML document:

	//tinyxml2::XMLElement* pElement = pRoot->FirstChildElement("LessonPrompts");
	//if (pElement == nullptr) return tinyxml2::XML_ERROR_PARSING_ELEMENT;

	tinyxml2::XMLElement* pListElement = LessonRoot->FirstChildElement(lessonLevel)->FirstChildElement("LessonPrompts")->FirstChildElement("Prompt");

	while (pListElement != nullptr)
	{
		const char* prompt = pListElement->GetText();
		std::string strPrompt{prompt};
		//XMLCheckResult(eResult);

		vecList.push_back(prompt);

		pListElement = pListElement->NextSiblingElement("Prompt");
	}
	return vecList;
	
};


int main() {
	std::vector<std::string> lessonPrompts = getLessonPrompts("IntroLessons", "Lesson1", "IntroLessons.xml");
	std::string lessonName;
	for (auto prompt : lessonPrompts) 
	{
		std::cout << prompt << "\n";
	}
	std::cout << "\n\nNew Lesson\n\n";
	lessonPrompts = getLessonPrompts("IntroLessons", "Lesson2", "IntroLessons.xml");
	for (auto prompt : lessonPrompts)
	{
		std::cout << prompt << "\n";
	}

}


