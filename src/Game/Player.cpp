#include "Player.hpp"

void Player::Init(sf::RenderWindow &window)
{
	SpriterEngine::Settings::setErrorFunction(SpriterEngine::Settings::simpleError);

	model = new SpriterEngine::SpriterModel("./Data/Dwarf/dwarf.scon", new SpriterEngine::ExampleFileFactory(&window), new SpriterEngine::ExampleObjectFactory(&window));
	instance = model->getNewEntityInstance("dwarf");

	instance->setCurrentAnimation("idle");

	instance->setScale(SpriterEngine::point(0.2, 0.2));
	instance->setPosition(SpriterEngine::point(500, 450));
}



void Player::Quit()
{
	SAFE_DELETE(instance);
	SAFE_DELETE(model);
}



void Player::Update()
{
}

void Player::Render(double timeElapsed)
{
	instance->setTimeElapsed(timeElapsed * 10);
	instance->render();
}
