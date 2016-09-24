#include "MainMenu.hpp"






void CMainMenu::Init(CGameEngine *_engine)
{
	m_pGameEngine = _engine;


	//Loads the background
	m_Background.Load(g_pTextures->t_backgroundMainMenu);
	m_Background.SetScale(m_pGameEngine->m_ScaleFactor, m_pGameEngine->m_ScaleFactor);

	//Load the buttons
	m_Buttons[Play].Load(g_pTextures->t_buttonMainMenu, _engine->GetWindowSize().x / 2 - 100, _engine->GetWindowSize().y / 10, Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_play]);
	m_Buttons[Options].Load(g_pTextures->t_buttonMainMenu, _engine->GetWindowSize().x / 2 - 100, 3 * (_engine->GetWindowSize().y / 10), Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_options]);
	m_Buttons[Highscore].Load(g_pTextures->t_buttonMainMenu, _engine->GetWindowSize().x / 2 - 100, 5 * (_engine->GetWindowSize().y / 10), Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_highscore]);
	m_Buttons[Quit].Load(g_pTextures->t_buttonMainMenu, _engine->GetWindowSize().x / 2 - 100, 7 * (_engine->GetWindowSize().y / 10), Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_quit]);
	
	//Set the scale and text for the buttons
	for (auto &b : m_Buttons)
	{
		b.SetButtontext(g_pFonts->f_valken, 32, sf::Color::Black);
		b.SetScale(m_pGameEngine->m_ScaleFactor, m_pGameEngine->m_ScaleFactor);
		b.SetPos(_engine->GetWindowSize().x / 2 - b.GetRect().width / 2, b.GetRect().top);
	}
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
	if (m_Buttons[Play].Render(*m_pGameEngine))
		m_pGameEngine->PushState(new CGameMenu());

	//if the options button was pressed: open the options page
	if (m_Buttons[Options].Render(*m_pGameEngine))
		m_pGameEngine->PushState(new COptions());

	m_Buttons[Highscore].Render(*m_pGameEngine);

	//if the quit button was pressed: quit the game
	if (m_Buttons[Quit].Render(*m_pGameEngine))
		m_pGameEngine->StopEngine();
}
