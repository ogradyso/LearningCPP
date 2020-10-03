#include "tinyxml2.h"
#include "tinyxml2.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

#define CATCH_CONFIG_MAIN
#include "catch.h"

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
	pPlayerElement->SetAttribute("CharacterClass", characterClass.c_str());

	pRoot->InsertEndChild(pPlayerElement);

	tinyxml2::XMLError eResult = xmlDoc.SaveFile(ptrGameFilePath);
	std::filesystem::path gameFilePath{ strGameFilePath };
	return gameFilePath;

}



//int main() {
//	std::filesystem::path gameFilePath = CreateNewGameFile("Shaun", "Hobbyist", "archer");
//	std::cout << gameFilePath;
//}

TEST_CASE("CreateNewGameFile ") {
	SECTION("returns a file path for an xml document with the name of the player in the game files location") {
		std::string correctFilePathString = std::filesystem::current_path().string() + "\\GameFiles\\test1.xml";
		std::filesystem::path returnedFilePath = CreateNewGameFile("test1", "test1", "test1");
		REQUIRE(returnedFilePath.string() == correctFilePathString);
		if (returnedFilePath.string() == correctFilePathString) {
			remove(correctFilePathString.c_str());
		}
		else {
			std::cout << "Did not remove";
		}
	}
	SECTION("contains correct initialized player one data") {
		std::string correctFilePathString = std::filesystem::current_path().string() + "\\GameFiles\\test2.xml";
		std::filesystem::path returnedFilePath = CreateNewGameFile("test2", "test2", "test2");
		tinyxml2::XMLDocument xmlDoc;
		tinyxml2::XMLError eResult = xmlDoc.LoadFile(correctFilePathString.c_str());
		tinyxml2::XMLNode* GameFileRoot = xmlDoc.FirstChild();
		REQUIRE(GameFileRoot != nullptr);
		if (GameFileRoot != nullptr) {
			tinyxml2::XMLElement* GameFileElement = GameFileRoot->FirstChildElement("PlayerOne");
			REQUIRE(GameFileElement != nullptr);
			const char* playerNameAttributeText = nullptr;
			const char* learnerClassAttributeText = nullptr;
			const char* characterClassAttributeText = nullptr;

			playerNameAttributeText = GameFileElement->Attribute("PlayerName");
			learnerClassAttributeText = GameFileElement->Attribute("LearningClass");
			characterClassAttributeText = GameFileElement->Attribute("CharacterClass");

			REQUIRE(playerNameAttributeText != nullptr);

			REQUIRE(learnerClassAttributeText != nullptr);
			REQUIRE(characterClassAttributeText != nullptr);

			if (playerNameAttributeText != nullptr && learnerClassAttributeText != nullptr && characterClassAttributeText != nullptr) {
				std::string strOutPlayerName = playerNameAttributeText;
				REQUIRE(strOutPlayerName == "test2");
				std::string strOutLearnerClass = learnerClassAttributeText;
				REQUIRE(strOutLearnerClass == "test2");
				std::string strOutCharacterClass = characterClassAttributeText;
				REQUIRE(strOutCharacterClass == "test2");
				if (strOutCharacterClass == "test2") {
					remove(correctFilePathString.c_str());
				}
				else {
					std::cout << "Did not remove";
				}
			}
		}
	}
}