#pragma once

#include "World.hpp"


class CollisionDetector
{
public:

	void Init(World *_world);

	bool CollisionWithWorld(sf::FloatRect &rect);


private:

	World *world;
};