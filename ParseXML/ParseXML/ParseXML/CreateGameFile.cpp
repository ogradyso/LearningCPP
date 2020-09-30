#include "tinyxml2.h"
#include "tinyxml2.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>


#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != tinyxml2::XML_SUCCESS) {printf("Error: %i\n", a_eResult); return a_eResult;}
#endif

std::filesystem::path CreateNewGameFile(std::string playerName, std::string learningClass, std::string characterClass) {
	std::string strGameFilePath = std::filesystem::current_path().string() + "\\GameFiles\\" + playerName + ".xml";
	auto ptrGameFilePath = strGameFilePath.c_str();
	//create a document:
	tinyxml2::XMLDocument xmlDoc;
	//add an element (int)
	tinyxml2::XMLNode* pRoot = xmlDoc.NewElement("GameFile");
	xmlDoc.InsertFirstChild(pRoot);
	tinyxml2::XMLElement* pPlayerElement = xmlDoc.NewElement("PlayerOne");
	pPlayerElement->SetAttribute("PlayerName", playerName.c_str());
	pPlayerElement->SetAttribute("LearningClass", learningClass.c_str());
	pPlayerElement->SetAttribute("CharaccterClass", characterClass.c_str());

	pRoot->InsertEndChild(pPlayerElement);

	tinyxml2::XMLError eResult = xmlDoc.SaveFile(ptrGameFilePath);
	std::filesystem::path gameFilePath{ strGameFilePath };
	return gameFilePath;

}



int main() {
	std::filesystem::path gameFilePath = CreateNewGameFile("Shaun", "Hobbyist", "archer");
	std::cout << gameFilePath;
}