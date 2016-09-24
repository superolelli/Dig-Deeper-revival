#include "Options.hpp"




void COptions::Init(CGameEngine *_engine)
{
	m_pGameEngine = _engine;


	//Loads the background
	m_Background.Load(g_pTextures->t_backgroundMainMenu);
	m_Background.SetScale(m_pGameEngine->m_ScaleFactor, m_pGameEngine->m_ScaleFactor);

	//Load the buttons
	m_Buttons[Settings].Load(g_pTextures->t_buttonMainMenu, _engine->GetWindowSize().x / 2 - 100, _engine->GetWindowSize().y / 10, Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_settings]);
	m_Buttons[Upgrades].Load(g_pTextures->t_buttonMainMenu, _engine->GetWindowSize().x / 2 - 100, 3 * (_engine->GetWindowSize().y / 10), Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_upgrades]);
	m_Buttons[Achievements].Load(g_pTextures->t_buttonMainMenu, _engine->GetWindowSize().x / 2 - 100, 5 * (_engine->GetWindowSize().y / 10), Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_achievements]);
	m_Buttons[Return].Load(g_pTextures->t_buttonMainMenu, _engine->GetWindowSize().x / 2 - 100, 7 * (_engine->GetWindowSize().y / 10), Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_return]);

	//Set the scale and text for the buttons
	for (auto &b : m_Buttons)
	{
		b.SetButtontext(g_pFonts->f_valken, 30, sf::Color::Black);
		b.SetScale(m_pGameEngine->m_ScaleFactor, m_pGameEngine->m_ScaleFactor);
		b.SetPos(_engine->GetWindowSize().x / 2 - b.GetRect().width / 2, b.GetRect().top);
	}
}


void COptions::Cleanup()
{
	m_pGameEngine = nullptr;
}



void COptions::Pause()
{
}



void COptions::Resume()
{
}




void COptions::HandleEvents()
{
	m_pGameEngine->ProcessEvents();
}



void COptions::Update()
{

}


void COptions::Render(double _normalizedTimestep)
{
	m_pGameEngine->ClearWindow(sf::Color::Black);

	//Renders everything
	m_Background.Render(m_pGameEngine->GetWindow());
	RenderButtons();

	m_pGameEngine->FlipWindow();
}


//renders all buttons
void COptions::RenderButtons()
{
	m_Buttons[Settings].Render(*m_pGameEngine);
	m_Buttons[Upgrades].Render(*m_pGameEngine);
	m_Buttons[Achievements].Render(*m_pGameEngine);

	//if the quit button was pressed: quit the game
	if (m_Buttons[Return].Render(*m_pGameEngine) == true)
		m_pGameEngine->PopState();
}
