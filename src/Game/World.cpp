#include "World.hpp"



void World::Init()
{
	background.Init();
}



void World::GenerateWorld(int width, int height)
{
	SetWorldSize(width, height);

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (y > 4)
			{
				placeables[x][y] = new Placeable;
				placeables[x][y]->Init(1);
				placeables[x][y]->SetPos(x * 100, y * 100);
			}
			else
				placeables[x][y] = nullptr;
		}
	}
}



void World::SetWorldSize(int x, int y)
{
	worldWidth = x;
	worldHeight = y;

	placeables.resize(x);
	for (int i = 0; i < x; i++)
		placeables[i].resize(y);
}


void World::Update()
{
	background.Update(sf::IntRect(0, 0, 1920, 1080));
}


void World::Render(sf::RenderTarget &_target, double _normalizedTimestep)
{
	background.Render(0, 0, _target);

	RenderPlaceables(_target);	


}



void World::RenderPlaceables(sf::RenderTarget &_target)
{
	for (int y = 0; y < worldHeight; y++)
	{
		for (int x = 0; x < worldWidth; x++)
		{
			if (placeables[x][y] != nullptr)
				placeables[x][y]->Render(_target);
		}
	}
}