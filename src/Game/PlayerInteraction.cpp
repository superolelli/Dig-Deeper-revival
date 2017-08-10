#include "PlayerInteraction.hpp"



void PlayerInteraction::Init(World *_world, CGameEngine*_engine)
{
	world = _world; 
	engine = _engine;

	breakingAnimation.Load(g_pTextures->t_breakingAnimation, 3, 100, 100);

	blockBreakingTime = 0.0f;
	blockHardness = 0;
}


void PlayerInteraction::Update()
{
	CheckBlockBreaking();
}



void PlayerInteraction::CheckBlockBreaking()
{
	int x = engine->GetMousePos().x / 100 * 100;
	int y = engine->GetMousePos().y / 100 * 100;


	if (engine->GetButtonstates(ButtonID::Left) == Held)
	{
		if (blockBreakingTime > 0 && breakingAnimation.GetRect().left == x && breakingAnimation.GetRect().top == y)
		{
			blockBreakingTime -= g_pTimer->GetElapsedTime().asSeconds();

			if (blockBreakingTime <= 0)
				world->DeleteBlock(x / 100, y / 100);
		}
		else
		{
			blockHardness = blockBreakingTime = world->GetBlockHardness(x / 100, y / 100);	
			breakingAnimation.SetPos(x, y);
		}
	}
	else if (engine->GetButtonstates(ButtonID::Left) == Released)
		blockBreakingTime = 0;
}



void PlayerInteraction::Render()
{
	if(blockBreakingTime > 0)
		breakingAnimation.Render(engine->GetWindow(), ((float)blockHardness - blockBreakingTime) / ((float)blockHardness / 3.0f));
}
