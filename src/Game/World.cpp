#include "World.hpp"



void World::Init()
{
	placeable.Init(1);
}


void World::GenerateWorld()
{

}


void World::Update()
{
	placeable.SetPos(400, 300);
}


void World::Render(sf::RenderTarget &_target, double _normalizedTimestep)
{
	placeable.Render(_target);
}
