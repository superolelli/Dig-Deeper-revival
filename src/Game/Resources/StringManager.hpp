#pragma once

#include "../../Framework/Patterns/singleton.hpp"
#include <map>

#include "StringNames.hpp"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>


//the class for loading all properties at once
#define g_pStringContainer CStringContainer::Get()
class CStringContainer : public TSingleton<CStringContainer>
{
public:
	//the possible languages
	enum class Languages { German, English };

	//loads all strings for the specific language
	void LoadStrings(Languages _language);

	//the string container
	std::map<int, std::string> m_Strings;

};