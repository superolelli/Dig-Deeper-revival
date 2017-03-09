#pragma once

#include "Placeable.hpp"
#include "Background.hpp"


class World
{
public:

	void Init();
	void GenerateWorld(int width, int height);
	void Update();
	void Render(sf::RenderTarget &_target, double _normalizedTimestep);

private:

	Background background;
	std::vector< std::vector<Placeable*> > placeables;

	int worldWidth;
	int worldHeight;

	void RenderPlaceables(sf::RenderTarget &_target);

	void SetWorldSize(int x, int y);
};