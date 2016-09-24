#include "TextureManager.hpp"



void CTextureManager::LoadTextures()
{
	t_backgroundMainMenu.loadFromFile("Data/Sprites/Menu.png");
	t_backgroundLoadingScreen.loadFromFile("Data/Sprites/Loading_screen.png");

	t_buttonMainMenu.loadFromFile("Data/Sprites/Buttons/menu_button_blank.png");
	t_buttonLoadGame.loadFromFile("Data/Sprites/Buttons/load_game_button_blank.png");

	t_buttonUp.loadFromFile("Data/Sprites/Buttons/button_up.png");
	t_buttonDown.loadFromFile("Data/Sprites/Buttons/button_down.png");
	t_buttonPlus.loadFromFile("Data/Sprites/Buttons/plus.png");
	t_buttonMinus.loadFromFile("Data/Sprites/Buttons/minus.png");

	t_buttonLoadMenu.loadFromFile("Data/Sprites/Buttons/button_blank.png");

	t_buttonOptions.loadFromFile("Data/Sprites/Buttons/button_options_blank.png");
	t_buttonLanguageOptions.loadFromFile("Data/Sprites/Buttons/button_language_blank.png");
	t_buttonLanguageSettings.loadFromFile("Data/Sprites/Buttons/button_language_settings.png");
	t_buttonHelpPageTopic.loadFromFile("Data/Sprites/Buttons/button_helpPageTopic.png");
}


