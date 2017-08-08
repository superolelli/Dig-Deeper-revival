#include "PlayerModel.hpp"



void PlayerModel::Init(CGameEngine *_engine)
{
	SpriterEngine::Settings::setErrorFunction(SpriterEngine::Settings::simpleError);

	model = new SpriterEngine::SpriterModel("./Data/Dwarf/dwarf.scml", new SpriterEngine::ExampleFileFactory(&_engine->GetWindow()), new SpriterEngine::ExampleObjectFactory(&_engine->GetWindow()));
	body = model->getNewEntityInstance("body");
	arm = model->getNewEntityInstance("arm");

	body->setCurrentAnimation("idle");

	body->setScale(SpriterEngine::point(1, 1));
	body->setPosition(SpriterEngine::point(400, 300));
	body->reprocessCurrentTime();

	armpoint = body->getObjectInstance("armpoint");

	arm->setCurrentAnimation("idle");

	arm->setScale(SpriterEngine::point(1, 1));
	arm->setPosition(SpriterEngine::point(armpoint->getPosition()));

	SpriterEngine::UniversalObjectInterface* hitbox = body->getObjectInstance("hitbox");

	playerRect.width = hitbox->getSize().x;
	playerRect.height = hitbox->getSize().y;
	playerRect.left = hitbox->getPosition().x;
	playerRect.top = hitbox->getPosition().y;


}


void PlayerModel::Quit()
{
	SAFE_DELETE(body);
	SAFE_DELETE(arm);
	SAFE_DELETE(model);
}


void PlayerModel::Move(float x, float y)
{
	playerRect.left += x;
	playerRect.top += y;

	SetPos(playerRect.left + x, playerRect.top + playerRect.height + y);
}



void PlayerModel::ExtrapolationMove(float x, float y)
{
	SetPos(playerRect.left + x, playerRect.top + playerRect.height + y);
}


void PlayerModel::SetPos(float x, float y)
{
	body->setPosition(SpriterEngine::point(x, y));
	body->reprocessCurrentTime();
	arm->setPosition(armpoint->getPosition());
}

void PlayerModel::SetAnimation(std::string animation)
{
	body->setCurrentAnimation(animation);
	arm->setCurrentAnimation(animation);
}



void PlayerModel::SetDirection(Direction direction)
{
	if(direction == Direction::left)
	{
		body->setScale(SpriterEngine::point(-1, 1));
		arm->setScale(SpriterEngine::point(-1, 1));
	}
	else
	{
		body->setScale(SpriterEngine::point(1, 1));
		arm->setScale(SpriterEngine::point(1, 1));
	}
}


void PlayerModel::Render(int speed)
{
	body->setTimeElapsed(speed);
	body->render();

	arm->setTimeElapsed(speed);
	arm->render();
}
