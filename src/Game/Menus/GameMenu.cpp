#include "GameMenu.hpp"



void CGameMenu::Init(CGameEngine *_engine)
{
	m_pGameEngine = _engine;


	//Loads the background
	m_Background.Load(g_pTextures->t_backgroundMainMenu);
	m_Background.SetScale(m_pGameEngine->m_ScaleFactor, m_pGameEngine->m_ScaleFactor);

	//Load the buttons
	m_Buttons[NewGame].Load(g_pTextures->t_buttonMainMenu, _engine->GetWindowSize().x / 2 - 100, _engine->GetWindowSize().y / 10, Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_new_game]);
	m_Buttons[LoadGame].Load(g_pTextures->t_buttonMainMenu, _engine->GetWindowSize().x / 2 - 100, 3 * (_engine->GetWindowSize().y / 10), Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_load_game]);
	m_Buttons[Return].Load(g_pTextures->t_buttonMainMenu, _engine->GetWindowSize().x / 2 - 100, 7 * (_engine->GetWindowSize().y / 10), Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_return]);


	//Set the scale and text for the buttons
	for (auto &b : m_Buttons)
	{
		b.SetButtontext(g_pFonts->f_valken, 32, sf::Color::Black);
		b.SetScale(m_pGameEngine->m_ScaleFactor, m_pGameEngine->m_ScaleFactor);
		b.SetPos(_engine->GetWindowSize().x / 2 - b.GetRect().width / 2, b.GetRect().top);
	}
}


void CGameMenu::Cleanup()
{
	m_pGameEngine = nullptr;
}



void CGameMenu::Pause()
{
}



void CGameMenu::Resume()
{
}




void CGameMenu::HandleEvents()
{
	m_pGameEngine->ProcessEvents();
}



void CGameMenu::Update()
{

}

void CGameMenu::Render(double _normalizedTimestep)
{
	m_pGameEngine->ClearWindow(sf::Color::Black);

	//Renders everything
	m_Background.Render(m_pGameEngine->GetWindow());
	RenderButtons();

	m_pGameEngine->FlipWindow();
}


//renders all buttons
void CGameMenu::RenderButtons()
{
	m_Buttons[NewGame].Render(*m_pGameEngine);
	m_Buttons[LoadGame].Render(*m_pGameEngine);


	//if the quit button was pressed: quit the game
	if (m_Buttons[Return].Render(*m_pGameEngine))
		m_pGameEngine->PopState();
}
