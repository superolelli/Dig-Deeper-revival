#pragma once

#include <SFML/Graphics.hpp>
#include "../../Framework/Patterns/singleton.hpp"

#define g_pFonts CFontManager::Get()
class CFontManager : public TSingleton<CFontManager>
{
public:
	//Loads all fonts
	void LoadFonts();

	//returns a font
	sf::Font f_opine;
	sf::Font f_valken;
	sf::Font f_plantc;
	sf::Font f_ltromatic;
};