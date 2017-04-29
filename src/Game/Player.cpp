#include "Player.hpp"

void Player::Init(sf::RenderWindow &window)
{
	SpriterEngine::Settings::setErrorFunction(SpriterEngine::Settings::simpleError);

	model = new SpriterEngine::SpriterModel("./Data/Dwarf/dwarf.scml", new SpriterEngine::ExampleFileFactory(&window), new SpriterEngine::ExampleObjectFactory(&window));
	body = model->getNewEntityInstance("body");
	arm = model->getNewEntityInstance("arm");

	body->setCurrentAnimation("walk");

	body->setScale(SpriterEngine::point(1, 1));
	body->setPosition(SpriterEngine::point(400, 500));

	arm->setCurrentAnimation("idle");
	
	arm->setScale(SpriterEngine::point(1, 1));
	arm->setPosition(SpriterEngine::point(408, 467));
}



void Player::Quit()
{
	SAFE_DELETE(body);
	SAFE_DELETE(arm);
	SAFE_DELETE(model);
}



void Player::Update()
{
	body->setPosition(SpriterEngine::point(body->getPosition().x + 1, body->getPosition().y));
	arm->setPosition(SpriterEngine::point(arm->getPosition().x + 1, arm->getPosition().y));
}

void Player::Render(double timeElapsed)
{
	body->setTimeElapsed(timeElapsed * 30);
	body->render();

	arm->setTimeElapsed(timeElapsed * 40);
	arm->render();
}
