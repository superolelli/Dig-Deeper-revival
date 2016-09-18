#include "MainMenu.hpp"






void CMainMenu::Init(CGameEngine *_engine)
{
	m_pGameEngine = _engine;


	m_button.Load(g_pTextures->t_button, 300, 300, Buttontypes::Motion_Up, "Knopf");
	m_button.SetButtontext(g_pFonts->f_opine, 25, sf::Color::Black, sf::Text::Style::Bold);
}


void CMainMenu::Cleanup()
{
	m_pGameEngine = nullptr;
}

void CMainMenu::Pause()
{
}

void CMainMenu::Resume()
{
}


void CMainMenu::HandleEvents()
{
	m_pGameEngine->ProcessEvents();
}

void CMainMenu::Update()
{
	if (m_pGameEngine->GetKeystates(KeyID::Escape) == Keystates::Released)
		m_pGameEngine->StopEngine();
}

void CMainMenu::Render(double _normalizedTimestep)
{
	m_pGameEngine->ClearWindow(sf::Color::Black);

	m_button.Render(*m_pGameEngine);

	m_pGameEngine->FlipWindow();
}
