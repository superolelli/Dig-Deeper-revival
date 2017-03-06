#include "MainMenu.hpp"






void CMainMenu::Init(CGameEngine *_engine)
{
	m_pGameEngine = _engine;


	//Loads the background
	m_Background.Load(g_pTextures->t_backgroundMainMenu);

	//Load the buttons
	m_Buttons[Play].Load(g_pTextures->t_buttonMainMenu, Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_play]);
	m_Buttons[Options].Load(g_pTextures->t_buttonMainMenu, Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_options]);
	m_Buttons[Highscore].Load(g_pTextures->t_buttonMainMenu, Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_highscore]);
	m_Buttons[Quit].Load(g_pTextures->t_buttonMainMenu, Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_quit]);
	
	auto posNumber = 1;
	//Set the scale and text for the buttons
	for (auto &b : m_Buttons)
	{
		b.SetButtontextFont(g_pFonts->f_valken);
		b.SetButtontextCharactersize(32);
		b.SetPos(_engine->GetWindowSize().x / 2 - b.GetRect().width / 2, posNumber *(_engine->GetWindowSize().y / 10));
		posNumber += 2;
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
	if (m_Buttons[Play].Update(*m_pGameEngine))
		m_pGameEngine->PushState(new CGameMenu());

	//if the options button was pressed: open the options page
	if (m_Buttons[Options].Update(*m_pGameEngine))
		m_pGameEngine->PushState(new COptions());

	m_Buttons[Highscore].Update(*m_pGameEngine);

	//if the quit button was pressed: quit the game
	if (m_Buttons[Quit].Update(*m_pGameEngine))
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
	m_Buttons[Play].Render(*m_pGameEngine);
	m_Buttons[Options].Render(*m_pGameEngine);
	m_Buttons[Highscore].Render(*m_pGameEngine);
	m_Buttons[Quit].Render(*m_pGameEngine);
}
