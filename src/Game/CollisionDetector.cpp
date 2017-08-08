#include "CollisionDetector.hpp"



void CollisionDetector::Init(World * _world)
{
	world = _world;
}



bool CollisionDetector::CollisionWithWorld(sf::FloatRect & rect)
{
	int xStart = (int)(rect.left / 100) - 2;
	if (xStart < 0)
		xStart = 0;

	int yStart = (int)(rect.top / 100) - 2;
	if (yStart < 0)
		yStart = 0;

	int xEnd = xStart + 4;
	if (xEnd > world->worldWidth)
		xEnd = world->worldWidth;

	int yEnd = yStart + 4 + (rect.height / 100);
	if (yEnd > world->worldHeight)
		yEnd = world->worldHeight;

	for (int y = yStart; y < yEnd; y++)
	{
		for (int x = xStart; x < xEnd; x++)
		{
			if (world->placeables[x][y] != nullptr)
			{
				if (world->placeables[x][y]->IsSolid() == true)
				{
					if (rect.intersects((sf::FloatRect)world->placeables[x][y]->GetRect()))
						return true;		
				}
			}
		}
	}

	return false;
}
