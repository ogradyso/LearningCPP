////helper function which will be imported into the C++Quest Game
//#include "tinyxml2.h"
//#include "tinyxml2.cpp"
//#include <iostream>
//#include <string>
//#include <vector>
//#include <filesystem>
//
//#ifndef XMLCheckResult
//#define XMLCheckResult(a_eResult) if (a_eResult != tinyxml2::XML_SUCCESS) {printf("Error: %i\n", a_eResult); return "Error parsing XML";}
//#endif
//
//std::vector<std::string> getLessonPrompts(const char* gameFilePath) {
//	tinyxml2::XMLDocument xmlDoc;
//
//	tinyxml2::XMLError eResult = xmlDoc.LoadFile("Lesson1.xml");
//
//	//XMLCheckResult(eResult);
//
//	//xtracting data from an XMLDocument:
//	tinyxml2::XMLNode* pRoot = xmlDoc.FirstChildElement("HelloWorld");
//	std::vector<std::string> vecList;
//	//if (pRoot == nullptr) std::cout << tinyxml2::XML_ERROR_FILE_READ_ERROR << "\n"; vecList.push_back("Error"); return vecList;
//
//	//get the elements of a list: 
//	//requires a vector in the XML document:
//
//	//tinyxml2::XMLElement* pElement = pRoot->FirstChildElement("LessonPrompts");
//	//if (pElement == nullptr) return tinyxml2::XML_ERROR_PARSING_ELEMENT;
//
//	tinyxml2::XMLElement* pListElement = pRoot->FirstChildElement("LessonPrompts")->FirstChildElement("Prompt");
//
//	while (pListElement != nullptr)
//	{
//		const char* prompt = pListElement->GetText();
//		std::string strPrompt{ prompt };
//		//XMLCheckResult(eResult);
//
//		vecList.push_back(prompt);
//
//		pListElement = pListElement->NextSiblingElement("Prompt");
//	}
//	return vecList;
//
//};
//
//
//int main() {
//	char gameFilePath[] = { 'L','e','s','s','o','n','1','.','x','m','l' };
//	std::string lessonName = "prompt";
//	const char* charPtrLessonName = lessonName.c_str();
//	std::vector<std::string> lessonPrompts = getLessonPrompts(gameFilePath);
//	for (auto prompt : lessonPrompts)
//	{
//		std::cout << prompt << "\n";
//	}
//	/*tinyxml2::XMLDocument xmlDoc;
//	tinyxml2::XMLError eResult = xmlDoc.LoadFile("Lesson1.xml");
//	if (eResult != tinyxml2::XML_SUCCESS) std::cout << "Failed at load";
//	tinyxml2::XMLNode* pRoot = xmlDoc.FirstChildElement("HelloWorld");
//	if (pRoot == nullptr) std::cout << "Failed to get root element.";
//	tinyxml2::XMLElement* pListElement = pRoot->FirstChildElement("LessonPrompts");
//	if (pListElement == nullptr) std::cout << "Failed to get list element.";*/
//
//}