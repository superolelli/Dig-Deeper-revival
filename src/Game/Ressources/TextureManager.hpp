#pragma once

#include <SFML/Graphics.hpp>
#include "../../Framework/Patterns/singleton.hpp"

#define g_pTextures CTextureManager::Get()
class CTextureManager : public TSingleton<CTextureManager>
{
public:
	//Loads all textures
	void LoadTextures();

	//all textures
	sf::Texture t_backgroundMainMenu;

	sf::Texture t_buttonMainMenu;
	sf::Texture t_buttonLoadGame;

	sf::Texture t_buttonUp;
	sf::Texture t_buttonDown;
	sf::Texture t_buttonPlus;
	sf::Texture t_buttonMinus;

	sf::Texture t_buttonLoadMenu;     

	sf::Texture t_buttonOptions;
	sf::Texture t_buttonLanguageSettings;
	sf::Texture t_buttonLanguageOptions;
	sf::Texture t_buttonHelpPageTopic;
};