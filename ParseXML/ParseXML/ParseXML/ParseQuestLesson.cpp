////helper function which will be imported into the C++Quest Game
//#include "tinyxml2.h"
//#include "tinyxml2.cpp"
//#include <iostream>
//#include <string>
//#include <vector>
//#include <filesystem>
//
//#ifndef XMLCheckResult
//	#define XMLCheckResult(a_eResult) if (a_eResult != tinyxml2::XML_SUCCESS) {printf("Error: %i\n", a_eResult); return a_eResult;}
//#endif
//
//void getLessonInfo(const char* lessonRoot, const char* lessonLevel, const schar* gameFilePath, std::string &lessonTitle, std::vector<std::string> & promptList, std::vector<std::string> & AnswerList) {
//	tinyxml2::XMLDocument xmlDoc;
//
//	tinyxml2::XMLError eResult = xmlDoc.LoadFile(gameFilePath);
//
//	tinyxml2::XMLNode* LessonRoot = xmlDoc.FirstChildElement(lessonRoot);
//	
//	tinyxml2::XMLElement* pLessonTitleElement = LessonRoot->FirstChildElement(lessonLevel)->FirstChildElement("LessonTitle");
//	const char* plessonTitle = pLessonTitleElement->GetText();
//	std::string strTitle{ plessonTitle };
//	lessonTitle = strTitle;
//
//	tinyxml2::XMLElement* pListElement = LessonRoot->FirstChildElement(lessonLevel)->FirstChildElement("LessonPrompts")->FirstChildElement("Prompt");
//
//	while (pListElement != nullptr)
//	{
//		const char* prompt = pListElement->GetText();
//		std::string strPrompt{prompt};
//		
//		promptList.push_back(prompt);
//
//		pListElement = pListElement->NextSiblingElement("Prompt");
//	}
//
//	pListElement = LessonRoot->FirstChildElement(lessonLevel)->FirstChildElement("LessonAnswers")->FirstChildElement("Answer");
//
//	while (pListElement != nullptr)
//	{
//		const char* answer = pListElement->GetText();
//		std::string strPrompt{ answer };
//
//		AnswerList.push_back(answer);
//
//		pListElement = pListElement->NextSiblingElement("Answer");
//	}
//	
//};
//
//
//int main() {
//	std::string lessonTitle;
//	std::vector<std::string> lessonPrompts;
//	std::vector<std::string> lessonAnswers;
//	getLessonInfo("IntroLessons", "Lesson1", "GameFiles\\IntroLessons.xml", lessonTitle, lessonPrompts, lessonAnswers);
//	std::cout << "\n\n\n**************************" << lessonTitle << "****************************\n\n\n";
//	for (auto prompt : lessonPrompts) 
//	{
//		std::cout << prompt << "\n";
//	}
//	std::cout << "\n\nNew Lesson\n\n";
//	lessonTitle.erase();
//	lessonPrompts.clear();
//	lessonAnswers.clear();
//	getLessonInfo("IntroLessons", "Lesson2", "GameFiles\\IntroLessons.xml",lessonTitle, lessonPrompts, lessonAnswers);
//	std::cout << "\n\n\n**************************" << lessonTitle << "****************************\n\n\n";
//	for (auto prompt : lessonPrompts)
//	{
//		std::cout << prompt << "\n";
//	}
//
//}
//
//
