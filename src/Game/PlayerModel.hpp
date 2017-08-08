#pragma once

#include "../Framework/Gameengine.hpp"

#include "../Framework/Animations/sfml_implementation/exampleobjectfactory.h"
#include "../Framework/Animations/sfml_implementation/examplefilefactory.h"

// include to use Spriter animations
#include "../Framework/Animations/spriterengine.h"
#include "../Framework/Animations/global/settings.h"

enum class Direction {left, right};

class PlayerModel
{
public:

	void Init(CGameEngine *_engine);
	void Quit();

	sf::FloatRect &GetRect() { return playerRect; }
	const SpriterEngine::point &GetExtrapolatedPos() { return body->getPosition(); }

	void Move(float x, float y);
	void ExtrapolationMove(float x, float y);
	void SetAnimation(std::string animation);
	void SetDirection(Direction direction);

	void Render(int speed);



private:
	SpriterEngine::SpriterModel *model;
	SpriterEngine::EntityInstance *body;
	SpriterEngine::EntityInstance * arm;

	SpriterEngine::UniversalObjectInterface* armpoint;

	sf::FloatRect playerRect;

	void SetPos(float x, float y);

};