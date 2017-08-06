#include "Player.hpp"



void Player::Init(CGameEngine *_engine)
{
	gameEngine = _engine;

	SpriterEngine::Settings::setErrorFunction(SpriterEngine::Settings::simpleError);

	LoadPlayerModel();

	SpriterEngine::UniversalObjectInterface* hitbox = body->getObjectInstance("hitbox");

	playerRect.width = hitbox->getSize().x;
	playerRect.height = hitbox->getSize().y;
	playerRect.left = hitbox->getPosition().x;
	playerRect.top = hitbox->getPosition().y;

	xVelocity = 0;
	yVelocity = 0;
}



void Player::LoadPlayerModel()
{
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

	playerRect.left += xVelocity;

	body->setPosition(SpriterEngine::point(playerRect.left, body->getPosition().y));
	arm->setPosition(SpriterEngine::point(playerRect.left, arm->getPosition().y));
}



void Player::CheckMovement()
{
	xVelocity = 0;
	yVelocity = 0;


	if (gameEngine->GetMousePos().x < GetRect().left + GetRect().width/2)
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
	ExtrapolationUpdate(timeElapsed);

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
	
	body->setTimeElapsed( abs(xVelocity) * 8);
	body->render();

	arm->setTimeElapsed( abs(xVelocity) * 8);
	arm->render();
}




void Player::ExtrapolationUpdate(double normalizedTimestep)
{
	body->setPosition(SpriterEngine::point(playerRect.left + round(xVelocity * normalizedTimestep), body->getPosition().y));
	arm->setPosition(SpriterEngine::point(playerRect.left + round(xVelocity * normalizedTimestep), arm->getPosition().y));
}