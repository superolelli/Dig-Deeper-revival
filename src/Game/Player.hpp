#pragma once

#include "../Framework/Gamestate.hpp"

#include "../Framework/Makros.hpp"

#include "../Framework/Animations/sfml_implementation/exampleobjectfactory.h"
#include "../Framework/Animations/sfml_implementation/examplefilefactory.h"

// include to use Spriter animations
#include "../Framework/Animations/spriterengine.h"
#include "../Framework/Animations/global/settings.h"


#include "CollisionDetector.hpp"
#include "PlayerModel.hpp"


class Player
{
public:

	void Init(CGameEngine *_engine, CollisionDetector *_collisionDetector);
	void Update();
	void Render(double timeElapsed);
	void Quit();

	const sf::FloatRect &GetRect() { return playerModel.GetRect(); }
	
	const SpriterEngine::point &GetExtrapolatedPos() { return playerModel.GetExtrapolatedPos(); }

	void ExtrapolationUpdate(double normalizedTimestep);

private:
	CGameEngine *gameEngine;
	CollisionDetector *collisionDetector;

	PlayerModel playerModel;

	int xVelocity;
	int yVelocity;

	bool isAirborne;
	bool isJumping;

	float jumpCounter;

	void CheckMovement();
	void CheckCollisions();

};