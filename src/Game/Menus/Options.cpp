#include "Options.hpp"




void COptions::Init(CGameEngine *_engine)
{
	m_pGameEngine = _engine;


	//Loads the background
	m_Background.Load(g_pTextures->t_backgroundMainMenu);

	//Load the buttons
	m_Buttons[Settings].Load(g_pTextures->t_buttonMainMenu, Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_settings]);
	m_Buttons[Upgrades].Load(g_pTextures->t_buttonMainMenu, Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_upgrades]);
	m_Buttons[Achievements].Load(g_pTextures->t_buttonMainMenu, Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_achievements]);
	m_Buttons[Return].Load(g_pTextures->t_buttonMainMenu, Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_return]);

	auto posNumber = 1;
	//Set the scale and text for the buttons
	for (auto &b : m_Buttons)
	{
		b.SetButtontextFont(g_pFonts->f_valken);
		b.SetPos(_engine->GetWindowSize().x / 2 - b.GetRect().width / 2, posNumber *(_engine->GetWindowSize().y / 10));
		posNumber += 2;
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
	if (m_Buttons[Return].Update(*m_pGameEngine) == true)
		m_pGameEngine->PopState();

	m_Buttons[Settings].Update(*m_pGameEngine);
	m_Buttons[Upgrades].Update(*m_pGameEngine);
	m_Buttons[Achievements].Update(*m_pGameEngine);
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
	m_Buttons[Return].Render(*m_pGameEngine);
}
