#include "FontManager.hpp"



void CFontManager::LoadFonts()
{
	f_opine.loadFromFile("Data/Fonts/opine.ttf");
	f_valken.loadFromFile("Data/Fonts/valken.ttf");
	f_plantc.loadFromFile("Data/Fonts/plantc.ttf");
	f_ltromatic.loadFromFile("Data/Fonts/ltromatic.ttf");
}

