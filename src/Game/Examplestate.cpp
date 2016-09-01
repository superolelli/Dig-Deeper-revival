#include "Examplestate.hpp"






void CGame::Init(CGameEngine *_engine)
{
	m_pGameEngine = _engine;

	m_ButtonTexture.loadFromFile("Data/play_button.png");
	m_button.Load(m_ButtonTexture, 300, 300, Buttontypes::Motion_Down);

	m_BeamFrameTexture.loadFromFile("Data/life_frame.png");
	m_BeamTexture.loadFromFile("Data/life_beam.png");

	m_value = 10;
	m_maxValue = 10;
	m_beam.Load(m_BeamTexture, m_BeamFrameTexture, &m_value, &m_maxValue);
	m_beam.SetPos(20, 20);
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

	if (m_button.Render(*m_pGameEngine))
		m_value--;

	m_beam.Render(m_pGameEngine->GetWindow());

	m_pGameEngine->FlipWindow();
}
