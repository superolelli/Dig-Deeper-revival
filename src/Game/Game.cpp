#include "Game.hpp"



void Game::Init(CGameEngine * _engine)
{
	m_pGameEngine = _engine;
}


void Game::Cleanup()
{
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
}



void Game::Render(double _normalizedTimestep)
{
	m_pGameEngine->ClearWindow(sf::Color::Black);



	m_pGameEngine->FlipWindow();
}
