#include "Placeable.hpp"




void Placeable::Init(int id)
{
	ID = id;
	attributes = g_pObjectProperties->placeableAttributes[ID];

	sprite.Load(g_pTextures->t_placeables[ID]);
}



void Placeable::Render(sf::RenderTarget &target)
{
	sprite.Render(target);
}



void Placeable::SetPos(int x, int y)
{
	sprite.SetPos(x, y);
}
