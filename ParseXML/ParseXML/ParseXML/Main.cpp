//#include "tinyxml2.h"
//#include "tinyxml2.cpp"
//#include <iostream>
//#include <string>
//#include <vector>
//
//#ifndef XMLCheckResult
//	#define XMLCheckResult(a_eResult) if (a_eResult != tinyxml2::XML_SUCCESS) {printf("Error: %i\n", a_eResult); return a_eResult;}
//#endif
//
//
//int main() {
//	////create a document:
//	//tinyxml2::XMLDocument xmlDoc;
//	////add an element (int)
//	//tinyxml2::XMLNode* pRoot = xmlDoc.NewElement("Root");
//	//xmlDoc.InsertFirstChild(pRoot);
//	//tinyxml2::XMLElement* pElement = xmlDoc.NewElement("IntValue");
//	//pElement->SetText(10);
//	//pRoot->InsertEndChild(pElement);
//	////add an element (float)
//	//pElement = xmlDoc.NewElement("FloatValue");
//	//pElement->SetText(0.5f);
//	//pRoot->InsertEndChild(pElement);
//	////setting an attribute:value pair:
//	//pElement = xmlDoc.NewElement("Date");
//	//pElement->SetAttribute("day", 26);
//	//pElement->SetAttribute("month", "April");
//	//pElement->SetAttribute("year", 2020);
//	//pElement->SetAttribute("dateFormat", "26/04/2014");
//	//pRoot->InsertEndChild(pElement);
//
//
//	////next elements within a tree structure:
//	////needs a vector:
//
//	///*It is often useful to nest XML elements within other elements in a tree structure, particularly when storing a group of related data.
//	//Let’s assume that we have a std::vector<int> containing an unknown quantity of values, each of which we want to store in its own element, 
//	//and that we want to group this list of elements within the XML file.To do this, we first create a parent XMLElement which can be 
//	//responsible for identifying its children as members of a list.*/
//
//	//pElement = xmlDoc.NewElement("List");
//	////We then iterate through the vector, creating a new XMLElement for each itemand attaching it as a child of the List element.
//
//	//for (const auto& item : vecList)
//	//{
//	//	XMLElement* pListElement = xmlDoc.NewElement("Item");
//	//	pListElement->SetText(item);
//
//	//	pElement->InsertEndChild(pListElement);
//	//}
//	////If we want to, we can also tell the List element how many members it has, though this is not strictly necessary.
//
//	//pElement->SetAttribute("itemCount", vecGroup.size());
//	////Don’t forget to attach the List element to the XMLDocument!
//
//	//pRoot->InsertEndChild(pElement);
//
//	////saving the XML Document to an xml file
//	//tinyxml2::XMLError eResult = xmlDoc.SaveFile("SampleData.xml");
//	//XMLCheckResult(eResult);
//
//	//Loading an XML file into a new XMLDocument
//	tinyxml2::XMLDocument xmlDoc;
//
//	tinyxml2::XMLError eResult = xmlDoc.LoadFile("SampleData.xml");
//
//	XMLCheckResult(eResult);
//
//	//xtracting data from an XMLDocument:
//	tinyxml2::XMLNode* pRoot = xmlDoc.FirstChild();
//
//	if (pRoot == nullptr) return tinyxml2::XML_ERROR_FILE_READ_ERROR;
//
//	//get a single element by name:
//	tinyxml2::XMLElement* pElement = pRoot->FirstChildElement("IntValue");
//	if (pElement == nullptr) return tinyxml2::XML_ERROR_PARSING_ELEMENT;
//
//	int iOutInt;
//	eResult = pElement->QueryIntText(&iOutInt);
//	XMLCheckResult(eResult);
//
//	pElement = pRoot->FirstChildElement("FloatValue");
//	if (pElement == nullptr) return tinyxml2::XML_ERROR_PARSING_ELEMENT;
//
//	float fOutFloat;
//	eResult = pElement->QueryFloatText(&fOutFloat);
//	XMLCheckResult(eResult);
//
//	pElement = pRoot->FirstChildElement("Date");
//	if (pElement == nullptr) return tinyxml2::XML_ERROR_PARSING_ELEMENT;
//
//	//extracting attribute data:
//	int iOutDay, iOutYear;
//
//	eResult = pElement->QueryIntAttribute("day", &iOutDay);
//	XMLCheckResult(eResult);
//
//	eResult = pElement->QueryIntAttribute("year", &iOutYear);
//	XMLCheckResult(eResult);
//
//	const char* szAttributeText = nullptr;
//	szAttributeText = pElement->Attribute("month");
//	if (szAttributeText == nullptr) return tinyxml2::XML_ERROR_PARSING_ATTRIBUTE;
//	std::string strOutMonth = szAttributeText;
//
//	szAttributeText = pElement->Attribute("dateFormat");
//	if (szAttributeText == nullptr) return tinyxml2::XML_ERROR_PARSING_ATTRIBUTE;
//	std::string strOutFormat = szAttributeText;
//
//	//get the elements of a list: 
//	//requires a vector in the XML document:
//	/*pElement = pRoot->FirstChildElement("List");
//	if (pElement == nullptr) return tinyxml2::XML_ERROR_PARSING_ELEMENT;
//
//	tinyxml2::XMLElement* pListElement = pElement->FirstChildElement("Item");
//	std::vector<int> vecList;
//
//	while (pListElement != nullptr)
//	{
//		int iOutListValue;
//		eResult = pListElement->QueryIntText(&iOutListValue);
//		XMLCheckResult(eResult);
//
//		vecList.push_back(iOutListValue);
//
//		pListElement = pListElement->NextSiblingElement("Item");
//	}*/
//
//	return tinyxml2::XML_SUCCESS;
//	/*tinyxml2::XMLDocument doc;
//	tinyxml2::XMLError eResult = doc.LoadFile("\GameFiles\LearnerLessons.xml");
//	XMLCheckResult(eResult);
//	tinyxml2::XMLNode* pRoot = doc.FirstChild();*/
//
//	//std::cout << pRoot;
//
//	/*const char* arrLessonName = doc.FirstChildElement("PLAY")->FirstChildElement("TITLE")->GetText();
//	std::string lessonName{arrLessonName};
//	std::cout << "Name of play (1):\n" + lessonName;*/
//}