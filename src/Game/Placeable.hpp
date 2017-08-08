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

	const sf::IntRect &GetRect() { return sprite.GetRect(); }

	bool IsSolid() { return attributes.is_solid; }

private:

	CSprite sprite;

	int ID;
	PlaceableAttributes attributes;

};