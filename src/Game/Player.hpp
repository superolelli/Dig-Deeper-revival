#pragma once

#include "../Framework/Makros.hpp"

#include "../Framework/Animations/sfml_implementation/exampleobjectfactory.h"
#include "../Framework/Animations/sfml_implementation/examplefilefactory.h"

// include to use Spriter animations
#include "../Framework/Animations/spriterengine.h"
#include "../Framework/Animations/global/settings.h"


class Player
{
public:

	void Init(sf::RenderWindow &window);
	void Update();
	void Render(double timeElapsed);
	void Quit();

private:
	SpriterEngine::SpriterModel *model;
	SpriterEngine::EntityInstance *instance;


};