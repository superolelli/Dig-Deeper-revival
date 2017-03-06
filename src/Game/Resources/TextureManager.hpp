#pragma once

#include <SFML/Graphics.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include "../../Framework/Patterns/singleton.hpp"

#define g_pTextures CTextureManager::Get()
class CTextureManager : public TSingleton<CTextureManager>
{
public:
	//Loads all textures
	void LoadTextures();

	//menu backgrounds
	sf::Texture t_backgroundMainMenu;
	sf::Texture t_backgroundLoadingScreen;
	sf::Texture t_backgroundNewGame;

	//basic buttons
	sf::Texture t_buttonMainMenu;
	sf::Texture t_buttonLoadGame;

	//navigation buttons
	sf::Texture t_buttonUp;
	sf::Texture t_buttonDown;
	sf::Texture t_buttonLeft;
	sf::Texture t_buttonRight;
	sf::Texture t_buttonPlus;
	sf::Texture t_buttonMinus;

	//Load menu button
	sf::Texture t_buttonLoadMenu;     

	//settings menu
	sf::Texture t_buttonOptions;
	sf::Texture t_buttonLanguageSettings;
	sf::Texture t_buttonLanguageOptions;
	sf::Texture t_buttonHelpPageTopic;
	
	//New game menu
	sf::Texture t_newGameWorldSize;
	sf::Texture t_newGameMiner;
	sf::Texture t_newGameBuilder;
	sf::Texture t_newGameWarrior;
	sf::Texture t_newGameMage;


	sf::Texture t_backgroundUnderground;
	sf::Texture t_backgroundSky;

	std::map<int, sf::Texture> t_placeables;
};