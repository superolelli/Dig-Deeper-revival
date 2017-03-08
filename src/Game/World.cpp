#include "World.hpp"



void World::Init()
{
	background.Init();
}


void World::GenerateWorld()
{

}


void World::Update()
{
	background.Update(sf::IntRect(0, 0, 1920, 1080));
}


void World::Render(sf::RenderTarget &_target, double _normalizedTimestep)
{
	background.Render(0, 0, _target);
}
