#include "Player.hpp"



void Player::Init(CGameEngine *_engine, CollisionDetector *_collisionDetector)
{
	gameEngine = _engine;
	collisionDetector = _collisionDetector;

	playerModel.Init(_engine);

	xVelocity = 0;
	yVelocity = 0;

	jumpCounter = 0;
	isAirborne = false;
	isJumping = false;
}



void Player::Quit()
{
	playerModel.Quit();
}



void Player::Update()
{
	CheckMovement();

	playerModel.Move(xVelocity, yVelocity);
}



void Player::CheckMovement()
{
	xVelocity = 0;
	yVelocity = 0;


	if (gameEngine->GetMousePos().x < GetRect().left + GetRect().width/2)
		playerModel.SetDirection(Direction::left);
	else
		playerModel.SetDirection(Direction::right);
	

	if (gameEngine->GetKeystates(KeyID::A) == Keystates::Held)
		xVelocity = -2;

	if (gameEngine->GetKeystates(KeyID::D) == Keystates::Held)
		xVelocity = 2;



	if (gameEngine->GetKeystates(KeyID::W) == Keystates::Pressed && isAirborne == false && isJumping == false)
	{
		isJumping = true;
		isAirborne = true;
		jumpCounter = 100;
	}


	if (isJumping)
	{
		yVelocity = -3;
		jumpCounter -= 3;
	}
	else
		yVelocity = 2;

	if (jumpCounter <= 0)
		isJumping = false;


	CheckCollisions();
}



void Player::CheckCollisions()
{
	sf::FloatRect tempRect = playerModel.GetRect();
	tempRect.top += yVelocity;

	if (collisionDetector->CollisionWithWorld(tempRect))
	{
		yVelocity = yVelocity / 2;

		tempRect.top -= yVelocity;
		if (collisionDetector->CollisionWithWorld(tempRect))
		{
			yVelocity = 0;
			isJumping = false;
			isAirborne = false;
		}
	}
}


void Player::Render(double timeElapsed)
{
	if (isAirborne)
		playerModel.SetAnimation("jump");
	else if (xVelocity != 0)
		playerModel.SetAnimation("walk");
	else
		playerModel.SetAnimation("idle");
	
	playerModel.Render((timeElapsed * abs(xVelocity)) / 2);
}




void Player::ExtrapolationUpdate(double normalizedTimestep)
{
	playerModel.ExtrapolationMove(round(xVelocity * normalizedTimestep), round(yVelocity * normalizedTimestep));
}