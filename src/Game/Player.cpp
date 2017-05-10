#include "Player.hpp"



void Player::Init(CGameEngine *_engine)
{
	gameEngine = _engine;

	SpriterEngine::Settings::setErrorFunction(SpriterEngine::Settings::simpleError);

	model = new SpriterEngine::SpriterModel("./Data/Dwarf/dwarf.scml", new SpriterEngine::ExampleFileFactory(&gameEngine->GetWindow()), new SpriterEngine::ExampleObjectFactory(&gameEngine->GetWindow()));
	body = model->getNewEntityInstance("body");
	arm = model->getNewEntityInstance("arm");

	body->setCurrentAnimation("idle");

	body->setScale(SpriterEngine::point(1, 1));
	body->setPosition(SpriterEngine::point(400, 500));
	body->reprocessCurrentTime();

	SpriterEngine::UniversalObjectInterface* armpoint = body->getObjectInstance("armpoint");

	arm->setCurrentAnimation("idle");

	arm->setScale(SpriterEngine::point(1, 1));
	arm->setPosition(SpriterEngine::point(armpoint->getPosition()));

	xVelocity = 0;
	yVelocity = 0;
}



void Player::Quit()
{
	SAFE_DELETE(body);
	SAFE_DELETE(arm);
	SAFE_DELETE(model);
}



void Player::Update()
{
	CheckMovement();

	body->setPosition(SpriterEngine::point(body->getPosition().x + xVelocity, body->getPosition().y));
	arm->setPosition(SpriterEngine::point(arm->getPosition().x + xVelocity, arm->getPosition().y));
}



void Player::CheckMovement()
{
	xVelocity = 0;

	if (gameEngine->GetMousePos().x < body->getPosition().x)
	{
		body->setScale(SpriterEngine::point(-1, 1));
		arm->setScale(SpriterEngine::point(-1, 1));
	}
	else
	{
		body->setScale(SpriterEngine::point(1, 1));
		arm->setScale(SpriterEngine::point(1, 1));
	}

	if (gameEngine->GetKeystates(KeyID::A) == Keystates::Held)
		xVelocity = -2;

	if (gameEngine->GetKeystates(KeyID::D) == Keystates::Held)
		xVelocity = 2;
}




void Player::Render(double timeElapsed)
{
	if (xVelocity != 0)
	{
		body->setCurrentAnimation("walk");
		arm->setCurrentAnimation("walk");
	}
	else
	{
		body->setCurrentAnimation("idle");
		arm->setCurrentAnimation("idle");
	}


	body->setTimeElapsed(timeElapsed * abs(xVelocity) * 18);
	body->render();

	arm->setTimeElapsed(timeElapsed * abs(xVelocity) * 18);
	arm->render();
}
