#include "TextureManager.hpp"



void CTextureManager::LoadTextures()
{
	//backgrounds
	t_backgroundMainMenu.loadFromFile("Data/Sprites/Menu.png");
	t_backgroundLoadingScreen.loadFromFile("Data/Sprites/Loading_screen.png");
	t_backgroundNewGame.loadFromFile("Data/Sprites/NewGame/background_NewGame.png");

	//basic buttons
	t_buttonMainMenu.loadFromFile("Data/Sprites/Buttons/menu_button_blank.png");
	t_buttonLoadGame.loadFromFile("Data/Sprites/Buttons/load_game_button_blank.png");

	//navigation buttons
	t_buttonUp.loadFromFile("Data/Sprites/Buttons/button_up.png");
	t_buttonDown.loadFromFile("Data/Sprites/Buttons/button_down.png");
	t_buttonLeft.loadFromFile("Data/Sprites/NewGame/button_left.png");
	t_buttonRight.loadFromFile("Data/Sprites/NewGame/button_right.png");
	t_buttonPlus.loadFromFile("Data/Sprites/Buttons/plus.png");
	t_buttonMinus.loadFromFile("Data/Sprites/Buttons/minus.png");

	//Load menu button
	t_buttonLoadMenu.loadFromFile("Data/Sprites/Buttons/button_blank.png");

	//settings menu
	t_buttonOptions.loadFromFile("Data/Sprites/Buttons/button_options_blank.png");
	t_buttonLanguageOptions.loadFromFile("Data/Sprites/Buttons/button_language_blank.png");
	t_buttonLanguageSettings.loadFromFile("Data/Sprites/Buttons/button_language_settings.png");
	t_buttonHelpPageTopic.loadFromFile("Data/Sprites/Buttons/button_helpPageTopic.png");

	//new game menu
	t_newGameWorldSize.loadFromFile("Data/Sprites/NewGame/world_size_blank.png");
	t_newGameMiner.loadFromFile("Data/Sprites/NewGame/startClass_miner.png");
	t_newGameBuilder.loadFromFile("Data/Sprites/NewGame/startClass_builder.png");
	t_newGameWarrior.loadFromFile("Data/Sprites/NewGame/startClass_warrior.png");
	t_newGameMage.loadFromFile("Data/Sprites/NewGame/startClass_mage.png");


	t_backgroundUnderground.loadFromFile("Data/Sprites/Background_game.png");
	t_backgroundSky.loadFromFile("Data/Sprites/Background_sky.png");


	//load placeable textures
	using boost::property_tree::ptree;
	using boost::property_tree::xml_parser::no_comments;
	ptree pt;

	read_xml("Data/Xml/Placeables.xml", pt, no_comments);

	for (auto v : pt.get_child("placeables"))
	{
		sf::Texture newTexture;
		newTexture.loadFromFile(v.second.get("<xmlattr>.texture", ""));

		t_placeables[v.second.get("<xmlattr>.ID", 0)] = newTexture;
	}

	pt.clear();
}


