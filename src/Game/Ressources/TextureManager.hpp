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
	sf::Texture t_button;
};