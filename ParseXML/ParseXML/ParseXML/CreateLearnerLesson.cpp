//#include "tinyxml2.h"
//#include "tinyxml2.cpp"
//#include <iostream>
//#include <string>
//#include <vector>
//
//#ifndef XMLCheckResult
//#define XMLCheckResult(a_eResult) if (a_eResult != tinyxml2::XML_SUCCESS) {printf("Error: %i\n", a_eResult); return a_eResult;}
//#endif
//
//
//int main() {
//	//create a document:
//	tinyxml2::XMLDocument xmlDoc;
//	//add an element (int)
//	tinyxml2::XMLNode* pRoot = xmlDoc.NewElement("HelloWorld");
//	xmlDoc.InsertFirstChild(pRoot);
//
//	std::vector<std::string> prompts;
//
//	prompts.push_back("In this lesson we are going to write our first C++ program to print \"Hello World!\" to the conosle. Enter OK:\n");
//	prompts.push_back("The first few lines of a C++ progam usually containg the code libraries the program needs to run properly. These are referred to as \"inlcude\" statements and look like this:\n\n#inlcude &lt;NameOfLibrary&gt;\n\nSometimes these inlcude statments will vary in how they are written but we are getting ahead of ourselves.\nWrite the include statement for the input-output stream (iostream) library:\n");
//	prompts.push_back("Every C++ program uses a driver function named \"main()\" which represents the entry point for the program. The main function returns an integer so it preceeded by the keyword \"int\". Enter the proper main function now:\n");
//	prompts.push_back("The scope of the main function begins with a curly brace \"{\" which is usually placed on the following line. Begin the scope of the main function by entering an opening curly brace:\n");
//	prompts.push_back("Now you can use the iostream library we entered on the first line to print to the console. You can do this by calling the cout function from the std (standard, often pronounced \"stood\") library.\n You do this by typing \"std::cout and then using the input operator \"<<\" followed by the output you would like to print: \"Hello World!\\n\" and remember to end the line with a semicolon (;)");
//	prompts.push_back("Finally, you need to close out the scope of the main function to tell the compiler that the function is complete. You do this by entering a closing curly brace: ");
//
//	std::vector<std::string> answers;
//
//	answers.push_back("OK");
//	answers.push_back("#include &lt;iostream&gt;");
//	answers.push_back("int main()");
//	answers.push_back("{");
//	answers.push_back("std::cout << \"Hello World!\";");
//	answers.push_back("}");
//
//	tinyxml2::XMLElement* pElement = xmlDoc.NewElement("LessonPrompts");
//	//We then iterate through the vector, creating a new XMLElement for each itemand attaching it as a child of the List element.
//
//	for (const auto& item : prompts)
//	{
//		tinyxml2::XMLElement* pListElement = xmlDoc.NewElement("Prompt");
//		pListElement->SetText(item.c_str());
//
//		pElement->InsertEndChild(pListElement);
//	}
//	pRoot->InsertEndChild(pElement);
//
//	/*tinyxml2::XMLElement* aElement = xmlDoc.NewElement("LessonAnswers");
//	for (const auto& item : answers)
//	{
//		tinyxml2::XMLElement* pListElement = xmlDoc.NewElement("Answer");
//		pListElement->SetText(item.c_str());
//
//		pElement->InsertEndChild(pListElement);
//	}
//
//	pRoot->InsertEndChild(aElement);*/
//	//If we want to, we can also tell the List element how many members it has, though this is not strictly necessary.
//	//pElement->SetAttribute("itemCount", vecGroup.size());
//
//	//saving the XML Document to an xml file
//	tinyxml2::XMLError eResult = xmlDoc.SaveFile("Lesson1.xml");
//	XMLCheckResult(eResult);
//}