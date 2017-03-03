#include "ObjectPropertiesManager.hpp"




void ObjectPropertiesManager::LoadObjectProperties()
{
	// populate tree structure pt
	using boost::property_tree::ptree;
	using boost::property_tree::xml_parser::no_comments;
	ptree pt;

	read_xml("Data/Xml/Placeables.xml", pt, no_comments);
	 

	PlaceableAttributes defaultAtb;
	defaultAtb.is_visible = pt.get("placeables.default.<xmlattr>.is_visible", true);
	defaultAtb.is_solid = pt.get("placeables.default.<xmlattr>.is_solid", true);
	defaultAtb.is_breakable = pt.get("placeables.default.<xmlattr>.is_breakable", true);
	defaultAtb.hardness = pt.get("placeables.default.<xmlattr>.hardness", 0);



	for(auto v : pt.get_child("placeables"))
	{
		PlaceableAttributes atb;

		atb.is_visible = v.second.get("<xmlattr>.is_visible", defaultAtb.is_visible);
		atb.is_solid = v.second.get("<xmlattr>.is_solid", defaultAtb.is_solid);
		atb.is_breakable = v.second.get("<xmlattr>.is_breakable", defaultAtb.is_breakable);
		atb.hardness = v.second.get("<xmlattr>.hardness", defaultAtb.hardness);

		placeableAttributes[v.second.get("<xmlattr>.ID", 0)] = atb;
	}

	pt.clear();
}