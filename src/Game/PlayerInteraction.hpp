#pragma once

#include "Player.hpp"
#include "World.hpp"



class PlayerInteraction
{
public:

	void Init(World *_world, CGameEngine*_engine);

	void Update();
	void Render();

private:

	World *world;
	CGameEngine *engine;

	float blockBreakingTime;
	int blockHardness;
	CSprite breakingAnimation;


	void CheckBlockBreaking();
};