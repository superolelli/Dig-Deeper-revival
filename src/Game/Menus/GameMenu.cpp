#include "GameMenu.hpp"



void CGameMenu::Init(CGameEngine *_engine)
{
	m_pGameEngine = _engine;


	//Loads the background
	m_Background.Load(g_pTextures->t_backgroundMainMenu);

	//Load the buttons
	m_Buttons[NewGame].Load(g_pTextures->t_buttonMainMenu, Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_new_game]);
	m_Buttons[LoadGame].Load(g_pTextures->t_buttonMainMenu, Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_load_game]);
	m_Buttons[Return].Load(g_pTextures->t_buttonMainMenu, Buttontypes::Motion_Down, g_pStringContainer->m_Strings[String_return]);

	m_Buttons[NewGame].SetPos(_engine->GetWindowSize().x / 2 - 100, _engine->GetWindowSize().y / 10);
	m_Buttons[LoadGame].SetPos(_engine->GetWindowSize().x / 2 - 100, 3*(_engine->GetWindowSize().y / 10));
	m_Buttons[Return].SetPos(_engine->GetWindowSize().x / 2 - 100, 7*(_engine->GetWindowSize().y / 10));

	//Set the scale and text for the buttons
	for (auto &b : m_Buttons)
	{
		b.SetButtontextFont(g_pFonts->f_valken);
		b.SetButtontextCharactersize(32);
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
	if (m_Buttons[NewGame].Update(*m_pGameEngine))
	{
		m_pGameEngine->PushState(new NewGameMenu());
	}

	m_Buttons[LoadGame].Update(*m_pGameEngine);

	if (m_Buttons[Return].Update(*m_pGameEngine))
		m_pGameEngine->PopState();
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
	m_Buttons[Return].Render(*m_pGameEngine);
}
