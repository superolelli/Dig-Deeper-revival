#include "World.hpp"



void World::Init()
{
	background.Init();
}



World::~World()
{
	for (auto p : placeables)
		for (auto block : p)
			SAFE_DELETE(block);
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

	placeables[7][4] = new Placeable;
	placeables[7][4]->Init(1);
	placeables[7][4]->SetPos(700, 400);
}



void World::SetWorldSize(int x, int y)
{
	worldWidth = x;
	worldHeight = y;

	placeables.resize(x);
	for (int i = 0; i < x; i++)
		placeables[i].resize(y);
}


void World::Update(const sf::IntRect &view)
{
	background.Update(view);
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


void World::DeleteBlock(int x, int y)
{
	if (x >= 0 && x < worldWidth && y >= 0 && y < worldHeight)
		SAFE_DELETE(placeables[x][y]);

}


int World::GetBlockHardness(int x, int y)
{
	if (x >= 0 && x < worldWidth && y >= 0 && y < worldHeight && placeables[x][y] != nullptr)
		return placeables[x][y]->Hardness();
	else
		return 0;
}