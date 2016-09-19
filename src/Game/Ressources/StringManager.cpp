#include "StringManager.hpp"


void CStringContainer::LoadStrings(Languages _language)
{
	// populate tree structure pt
	using boost::property_tree::ptree;
	ptree pt;


	switch (_language)
	{
	case(Languages::German):
		read_xml("Data/Xml/TextFileGerman.xml", pt);
		break;
	case(Languages::English):
		read_xml("Data/Xml/TextFileEnglish.xml", pt);
		break;
	}


	//loads the attributes of each start class type into a map
	for (auto v : pt.get_child("stringtable"))
	{
		if (v.first == "string")
			m_Strings[v.second.get("<xmlattr>.ID", 0)] = v.second.get<std::string>("<xmlattr>.value");
	}


	pt.clear();
}