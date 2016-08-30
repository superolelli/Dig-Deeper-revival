#include "Examplestate.hpp"






void CGame::Init(CGameEngine *_engine)
{
	m_pGameEngine = _engine;

	m_texture.loadFromFile("Data/play_button.png");
	m_button.Load(m_texture, 300, 300, Buttontypes::Motion_Down);
}

void CGame::Cleanup()
{
	m_pGameEngine = nullptr;
}

void CGame::Pause()
{
}

void CGame::Resume()
{
}


void CGame::HandleEvents()
{
	m_pGameEngine->ProcessEvents();
}

void CGame::Update()
{
	if (m_pGameEngine->GetKeystates(KeyID::Escape) == Keystates::Released)
		m_pGameEngine->StopEngine();
}

void CGame::Render(double _normalizedTimestep)
{
	m_pGameEngine->ClearWindow(sf::Color::Black);

	m_button.Render(*m_pGameEngine);

	m_pGameEngine->FlipWindow();
}
