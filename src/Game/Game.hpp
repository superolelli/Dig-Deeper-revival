#pragma once

#include "../Framework/Gamestate.hpp"
#include "Menus\MainMenu.hpp"
#include "World.hpp"
#include "Player.hpp"


class Game : public GameState
{
public:

	void Init(CGameEngine *_engine) override;
	void Cleanup() override;

	void Pause() override;
	void Resume() override;

	void HandleEvents() override;
	void Update() override;
	void Render(double _normalizedTimestep) override;

private:

	World world;
	Player player;
};