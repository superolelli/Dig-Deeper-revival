#pragma once

#include "Placeable.hpp"


class World
{
public:

	void Init();
	void GenerateWorld();
	void Update();
	void Render(sf::RenderTarget &_target, double _normalizedTimestep);

private:

	Placeable placeable;
};