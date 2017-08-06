#pragma once

#include "../Framework/Gamestate.hpp"

#include "../Framework/Makros.hpp"

#include "../Framework/Animations/sfml_implementation/exampleobjectfactory.h"
#include "../Framework/Animations/sfml_implementation/examplefilefactory.h"

// include to use Spriter animations
#include "../Framework/Animations/spriterengine.h"
#include "../Framework/Animations/global/settings.h"


class Player
{
public:

	void Init(CGameEngine *_engine);
	void Update();
	void Render(double timeElapsed);
	void Quit();

	const sf::FloatRect &GetRect() { return playerRect; }

private:
	CGameEngine *gameEngine;

	SpriterEngine::SpriterModel *model;
	SpriterEngine::EntityInstance *body;
	SpriterEngine::EntityInstance * arm;

	sf::FloatRect playerRect;

	int xVelocity;
	int yVelocity;

	void CheckMovement();

	void ExtrapolationUpdate(double normalizedTimestep);

	void LoadPlayerModel();


};