#include "MainMenu.hpp"






void CMainMenu::Init(CGameEngine *_engine)
{
	m_pGameEngine = _engine;

	//TODO: Scale the buttons!

	//Loads the background
	m_Background.Load(g_pTextures->t_backgroundMainMenu);
	m_Background.SetScale(m_pGameEngine->m_ScaleFactor, m_pGameEngine->m_ScaleFactor);

	m_PlayButton.Load(g_pTextures->t_buttonMainMenu, _engine->GetWindowSize().x / 2 - 100, _engine->GetWindowSize().y / 10, Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_play]);
	m_PlayButton.SetButtontext(g_pFonts->f_valken, 32, sf::Color::Black);

	m_OptionsButton.Load(g_pTextures->t_buttonMainMenu, _engine->GetWindowSize().x / 2 - 100, 3 * (_engine->GetWindowSize().y / 10), Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_options]);
	m_OptionsButton.SetButtontext(g_pFonts->f_valken, 32, sf::Color::Black);

	m_HighscoreButton.Load(g_pTextures->t_buttonMainMenu, _engine->GetWindowSize().x / 2 - 100, 5 * (_engine->GetWindowSize().y / 10), Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_highscore]);
	m_HighscoreButton.SetButtontext(g_pFonts->f_valken, 32, sf::Color::Black);

	m_QuitButton.Load(g_pTextures->t_buttonMainMenu, _engine->GetWindowSize().x / 2 - 100, 7 * (_engine->GetWindowSize().y / 10), Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_quit]);
	m_QuitButton.SetButtontext(g_pFonts->f_valken, 32, sf::Color::Black);
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

	//Renders everything
	m_Background.Render(m_pGameEngine->GetWindow());
	RenderButtons();

	m_pGameEngine->FlipWindow();
}


//renders all buttons
void CMainMenu::RenderButtons()
{
	m_PlayButton.Render(*m_pGameEngine);
	m_OptionsButton.Render(*m_pGameEngine);
	m_HighscoreButton.Render(*m_pGameEngine);

	if (m_QuitButton.Render(*m_pGameEngine) == true)
		m_pGameEngine->StopEngine();
}
