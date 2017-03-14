#include "Game.hpp"



void Game::Init(CGameEngine * _engine)
{
	m_pGameEngine = _engine;

	world.Init();
	world.GenerateWorld(50, 50);

	player.Init(m_pGameEngine->GetWindow());
}


void Game::Cleanup()
{
	player.Quit();

	m_pGameEngine = nullptr;
}


void Game::Pause()
{
}


void Game::Resume()
{
}


void Game::HandleEvents()
{
	m_pGameEngine->ProcessEvents();
}


void Game::Update()
{
	if(m_pGameEngine->GetKeystates(KeyID::Escape) == Keystates::Pressed)
		m_pGameEngine->ChangeState(new CMainMenu());

	world.Update();
	player.Update();
}



void Game::Render(double _normalizedTimestep)
{
	m_pGameEngine->ClearWindow(sf::Color::Black);

	world.Render(m_pGameEngine->GetWindow(), _normalizedTimestep);

	player.Render(_normalizedTimestep);

	m_pGameEngine->FlipWindow();
}
