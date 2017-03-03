#pragma once

#include "../../Framework/Patterns/singleton.hpp"
#include <map>


#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>


struct PlaceableAttributes
{
	bool is_visible;
	bool is_solid;
	bool is_breakable;

	int hardness;
};



#define g_pObjectProperties ObjectPropertiesManager::Get()
class ObjectPropertiesManager : public TSingleton<ObjectPropertiesManager>
{
public:
	void LoadObjectProperties();

	std::map<int, PlaceableAttributes> placeableAttributes;
};

