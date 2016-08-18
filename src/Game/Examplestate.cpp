#include "Examplestate.hpp"






void CGame::Init(CGameEngine *_engine)
{
	m_pGameEngine = _engine;
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
	m_pGameEngine->GetWindow()->ProcessEvents();
}

void CGame::Update()
{
	if (m_pGameEngine->GetWindow()->GetKeystates(KeyID::Escape) == Keystates::Released)
		m_pGameEngine->StopEngine();
}

void CGame::Render(double _normalizedTimestep)
{
	m_pGameEngine->GetWindow()->Clear(sf::Color::Black);
	m_pGameEngine->GetWindow()->Flip();
}
