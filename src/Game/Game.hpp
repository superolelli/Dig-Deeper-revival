#pragma once

#include "../Framework/Gamestate.hpp"
#include "Menus\MainMenu.hpp"
#include "World.hpp"
#include "Player.hpp"
#include "CollisionDetector.hpp"


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
	CollisionDetector collisionDetector;
	sf::View view;

	void SetViewForGUI() { m_pGameEngine->GetWindow().setView(m_pGameEngine->GetWindow().getDefaultView()); }
	void SetViewForPlayer() { m_pGameEngine->GetWindow().setView(view); }

	void UpdateView();

	void ExtrapolationUpdate(double normalizedTimestep);
};