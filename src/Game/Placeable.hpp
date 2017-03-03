#pragma once


#include "../Framework/Graphics/Sprite.hpp"
#include "../Game/Resources/TextureManager.hpp"
#include "Resources/ObjectPropertiesManager.hpp"




class Placeable
{
public:

	void Init(int id);
	void Render(sf::RenderTarget &target);
	void SetPos(int x, int y);

private:

	CSprite sprite;

	int ID;
	PlaceableAttributes attributes;

};