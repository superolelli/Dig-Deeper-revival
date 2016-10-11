#include "NewGame.hpp"




void CNewGame::Init(CGameEngine *_engine)
{
	m_pGameEngine = _engine;


	//Loads the background
	m_Background.Load(g_pTextures->t_backgroundNewGame);
	m_Background.SetScale(m_pGameEngine->m_ScaleFactor, m_pGameEngine->m_ScaleFactor);

	//Load the buttons
	m_Buttons[StartGame].Load(g_pTextures->t_buttonMainMenu, 0, 0, Buttontypes::Motion_Up, g_pStringContainer->m_Strings[String_start_game]);
	m_Buttons[StartGame].SetButtontext(g_pFonts->f_valken, 27, sf::Color::Black);
	m_Buttons[StartGame].SetScale(m_pGameEngine->m_ScaleFactor, m_pGameEngine->m_ScaleFactor);
	m_Buttons[StartGame].SetPos(_engine->GetWindowSize().x  - _engine->GetWindowSize().x / 6 - m_Buttons[StartGame].GetRect().width, _engine->GetWindowSize().y - _engine->GetWindowSize().y / 6 - m_Buttons[StartGame].GetRect().height);

	m_Buttons[Return].Load(g_pTextures->t_buttonMainMenu, 0, 0, Buttontypes::Motion_Up, g_pStringContainer->m_Strings[String_return]);
	m_Buttons[Return].SetButtontext(g_pFonts->f_valken, 27, sf::Color::Black);
	m_Buttons[Return].SetScale(m_pGameEngine->m_ScaleFactor, m_pGameEngine->m_ScaleFactor);
	m_Buttons[Return].SetPos(_engine->GetWindowSize().x / 6, _engine->GetWindowSize().y - _engine->GetWindowSize().y / 6 - m_Buttons[Return].GetRect().height);

	//Load the class descriptions
	m_ClassDescription[Miner].Load(g_pTextures->t_newGameMiner);
	m_ClassDescription[Miner].AddText(g_pStringContainer->m_Strings[String_miner], g_pFonts->f_plantc, 25, 0, 0, sf::Color(0, 100, 0), sf::Text::Style(sf::Text::Style::Bold | sf::Text::Style::Underlined));
	
	m_ClassDescription[Builder].Load(g_pTextures->t_newGameBuilder);
	
	m_ClassDescription[Warrior].Load(g_pTextures->t_newGameWarrior);
	
	m_ClassDescription[Mage].Load(g_pTextures->t_newGameMage);

	for (auto &c : m_ClassDescription)
	{
		c.Scale(m_pGameEngine->m_ScaleFactor, m_pGameEngine->m_ScaleFactor);
		c.SetPos(_engine->GetWindowSize().x / 5, _engine->GetWindowSize().y / 4);
	}
	


	m_pClass[0] = new CSpriteWithText;
	m_pClass[0]->Load(&g_pTextures->t_newGameMiner, g_pStringContainer->m_Strings[STRING_MINER_INFO]);

	m_pClass[1] = new CSpriteWithText;
	m_pClass[1]->Load(&g_pTextures->t_newGameBuilder, g_pStringContainer->m_Strings[STRING_BUILDER_INFO]);

	m_pClass[2] = new CSpriteWithText;
	m_pClass[2]->Load(&g_pTextures->t_newGameWarrior, g_pStringContainer->m_Strings[STRING_WARRIOR_INFO]);

	m_pClass[3] = new CSpriteWithText;
	m_pClass[3]->Load(&g_pTextures->t_newGameMage, g_pStringContainer->m_Strings[STRING_MAGE_INFO]);

	for (int i = 0; i < 4; i++)
	{
		m_pClass[i]->SetText(g_pTextures->f_plantc, 25, Color(0, 100, 0));
		m_pClass[i]->SetPos((float)g_pFramework->GetRenderWindow()->getSize().x / 5, (float)g_pFramework->GetRenderWindow()->getSize().y / 4);
		m_pClass[i]->SetTextPos(0, 250);

		m_ClassTitle[i].setCharacterSize(30);
		m_ClassTitle[i].setFont(g_pTextures->f_plantc);
		m_ClassTitle[i].setStyle(Text::Bold | Text::Underlined);
		m_ClassTitle[i].setColor(Color::Black);
		m_ClassTitle[i].setString(g_pStringContainer->m_Strings[STRING_MINER + (i * 2)]);
		m_ClassTitle[i].setPosition((int)(m_pClass[i]->GetRect().left + m_pClass[i]->GetRect().width / 2 - m_ClassTitle[i].getGlobalBounds().width / 2), (int)(m_pClass[i]->GetRect().top + 10));
	}

	m_pWorldSize.Load(&g_pTextures->t_newGameWorldSizeBlank, g_pStringContainer->m_Strings[STRING_SMALL_WORLD]);
	m_pWorldSize.SetPos((float)g_pFramework->GetRenderWindow()->getSize().x / 1.5, (float)g_pFramework->GetRenderWindow()->getSize().y / 2);
	m_pWorldSize.SetText(g_pTextures->f_plantc, 27, Color::Black, Text::Bold);

	m_pClassLeft = new CButton;
	m_pClassLeft->Load(&g_pTextures->t_newGameButtonLeft, m_pClass[0]->GetRect().left - 120, m_pClass[0]->GetRect().top + m_pClass[0]->GetRect().height / 2 - 37, 1);

	m_pClassRight = new CButton;
	m_pClassRight->Load(&g_pTextures->t_newGameButtonRight, m_pClass[0]->GetRect().left + m_pClass[0]->GetRect().width + 10, m_pClass[0]->GetRect().top + m_pClass[0]->GetRect().height / 2 - 37, 1);

	m_pWorldLeft = new CButton;
	m_pWorldLeft->Load(&g_pTextures->t_newGameButtonLeft, m_pWorldSize.GetRect().left - 120, m_pWorldSize.GetRect().top + m_pWorldSize.GetRect().height / 2 - 37, 1);

	m_pWorldRight = new CButton;
	m_pWorldRight->Load(&g_pTextures->t_newGameButtonRight, m_pWorldSize.GetRect().left + m_pWorldSize.GetRect().width + 10, m_pWorldSize.GetRect().top + m_pWorldSize.GetRect().height / 2 - 37, 1);

	m_GameName.Init(g_pTextures->f_ltromatic, 30, g_pFramework->GetRenderWindow()->getSize().x / 2, g_pFramework->GetRenderWindow()->getSize().y / 8, Color(230, 220, 0));
	m_GameName.SetString(g_pStringContainer->m_Strings[STRING_NEW_WORLD]);

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


void CNewGame::Init()
{
	m_pBackground = new CSprite;
	m_pBackground->Load(&g_pTextures->t_newGameBackground);

	m_pStartGameButton = new CButton;
	m_pStartGameButton->Load(&g_pTextures->t_menuBlankButton, g_pFramework->GetRenderWindow()->getSize().x / 2 + 200, g_pFramework->GetRenderWindow()->getSize().y - 200, 3, g_pStringContainer->m_Strings[STRING_START_GAME]);
	m_pStartGameButton->SetButtontext(&g_pTextures->f_plantc, 27, Color::Black, Text::Bold);

	m_pReturnButton = new CButton;
	m_pReturnButton->Load(&g_pTextures->t_menuBlankButton, g_pFramework->GetRenderWindow()->getSize().x / 2 - 350, g_pFramework->GetRenderWindow()->getSize().y - 200, 3, g_pStringContainer->m_Strings[STRING_RETURN]);
	m_pReturnButton->SetButtontext(&g_pTextures->f_plantc, 27, Color::Black, Text::Bold);

	m_pClass[0] = new CSpriteWithText;
	m_pClass[0]->Load(&g_pTextures->t_newGameMiner, g_pStringContainer->m_Strings[STRING_MINER_INFO]);
	
	m_pClass[1] = new CSpriteWithText;
	m_pClass[1]->Load(&g_pTextures->t_newGameBuilder, g_pStringContainer->m_Strings[STRING_BUILDER_INFO]);

	m_pClass[2] = new CSpriteWithText;
	m_pClass[2]->Load(&g_pTextures->t_newGameWarrior, g_pStringContainer->m_Strings[STRING_WARRIOR_INFO]);
	
	m_pClass[3] = new CSpriteWithText;
	m_pClass[3]->Load(&g_pTextures->t_newGameMage, g_pStringContainer->m_Strings[STRING_MAGE_INFO]);

	for (int i = 0; i < 4; i++)
	{
		m_pClass[i]->SetText(g_pTextures->f_plantc, 25, Color(0, 100, 0));
		m_pClass[i]->SetPos((float)g_pFramework->GetRenderWindow()->getSize().x / 5, (float)g_pFramework->GetRenderWindow()->getSize().y / 4);
		m_pClass[i]->SetTextPos(0, 250);

		m_ClassTitle[i].setCharacterSize(30);
		m_ClassTitle[i].setFont(g_pTextures->f_plantc);
		m_ClassTitle[i].setStyle(Text::Bold | Text::Underlined);
		m_ClassTitle[i].setColor(Color::Black);
		m_ClassTitle[i].setString(g_pStringContainer->m_Strings[STRING_MINER + (i*2)]);
		m_ClassTitle[i].setPosition((int)(m_pClass[i]->GetRect().left + m_pClass[i]->GetRect().width / 2 - m_ClassTitle[i].getGlobalBounds().width / 2), (int)(m_pClass[i]->GetRect().top + 10));
	}

	m_pWorldSize.Load(&g_pTextures->t_newGameWorldSizeBlank, g_pStringContainer->m_Strings[STRING_SMALL_WORLD]);
	m_pWorldSize.SetPos((float)g_pFramework->GetRenderWindow()->getSize().x / 1.5, (float)g_pFramework->GetRenderWindow()->getSize().y / 2);
	m_pWorldSize.SetText(g_pTextures->f_plantc, 27, Color::Black, Text::Bold);

	m_pClassLeft = new CButton;
	m_pClassLeft->Load(&g_pTextures->t_newGameButtonLeft, m_pClass[0]->GetRect().left - 120, m_pClass[0]->GetRect().top + m_pClass[0]->GetRect().height/2 - 37, 1);

	m_pClassRight = new CButton;
	m_pClassRight->Load(&g_pTextures->t_newGameButtonRight, m_pClass[0]->GetRect().left + m_pClass[0]->GetRect().width + 10, m_pClass[0]->GetRect().top + m_pClass[0]->GetRect().height/2 - 37, 1);

	m_pWorldLeft = new CButton;
	m_pWorldLeft->Load(&g_pTextures->t_newGameButtonLeft, m_pWorldSize.GetRect().left - 120, m_pWorldSize.GetRect().top + m_pWorldSize.GetRect().height/2 - 37, 1);

	m_pWorldRight = new CButton;
	m_pWorldRight->Load(&g_pTextures->t_newGameButtonRight, m_pWorldSize.GetRect().left + m_pWorldSize.GetRect().width + 10, m_pWorldSize.GetRect().top + m_pWorldSize.GetRect().height/2 - 37, 1);

	m_GameName.Init(g_pTextures->f_ltromatic, 30, g_pFramework->GetRenderWindow()->getSize().x/2, g_pFramework->GetRenderWindow()->getSize().y/8, Color(230, 220, 0));
	m_GameName.SetString(g_pStringContainer->m_Strings[STRING_NEW_WORLD]);

	m_class = 0;
	m_worldSize = 0;

	is_running = true;
	m_returnNumber = 0;
}




SNewWorldAttributes CNewGame::Quit()
{
	SNewWorldAttributes attributes;
	attributes.GameName = m_GameName.GetString();
	attributes.PlayerClass = m_class +1;
	attributes.WorldSize = m_worldSize +1;


	SAFE_DELETE(m_pBackground);
	SAFE_DELETE(m_pClassLeft);
	SAFE_DELETE(m_pClassRight);
	SAFE_DELETE(m_pWorldLeft);
	SAFE_DELETE(m_pWorldRight);
	SAFE_DELETE(m_pStartGameButton);
	SAFE_DELETE(m_pReturnButton);

	
	BOOST_FOREACH(CSpriteWithText* c, m_pClass)
	{
		SAFE_DELETE(c);
	}

	return attributes;
}




int CNewGame::Run()
{
	//the loop
	while(is_running == true)
	{
		//Update and clear the Window
		g_pFramework->Update();
		g_pFramework->Clear();

		//get the events
		g_pFramework->ProcessEvents();
		m_ButtonEventtype = 0;

		//If an event happened, important for the buttons, save it (Left mouse up)
		if(g_pFramework->keyStates.leftMouseUp)
				m_ButtonEventtype = MOUSE_LEFT_UP;
		else if (g_pFramework->keyStates.f3)
		{
			m_class = TEST - 1;

			is_running = false;
			return 2;
		}

		
		m_GameName.HandleInput();

		//Render the background
		m_pBackground->Render(g_pFramework->GetRenderWindow());

		m_GameName.Show(g_pFramework->GetRenderWindow());

		m_pClass[m_class]->Render(g_pFramework->GetRenderWindow());
		g_pFramework->GetRenderWindow()->draw(m_ClassTitle[m_class]);

		m_pWorldSize.Render(g_pFramework->GetRenderWindow());


		//Render the buttons
		RenderButtons();
       

		g_pFramework->Flip();
	}

	return m_returnNumber;
}




void CNewGame::RenderButtons()
{
	if(m_pClassLeft->Render(m_ButtonEventtype) == true)
	{
		m_class --;
		if(m_class < 0)
			m_class = 3;
	}

	if(m_pClassRight->Render(m_ButtonEventtype) == true)
	{
		m_class++;
		if(m_class > 3)
			m_class = 0;
	}

	if(m_pWorldLeft->Render(m_ButtonEventtype) == true)
	{
		m_worldSize--;
		if(m_worldSize < 0)
			m_worldSize = 2;

		m_pWorldSize.SetString(g_pStringContainer->m_Strings[STRING_SMALL_WORLD + m_worldSize]);
	}

	if(m_pWorldRight->Render(m_ButtonEventtype) == true)
	{
		m_worldSize++;
		if(m_worldSize > 2)
			m_worldSize = 0;

		m_pWorldSize.SetString(g_pStringContainer->m_Strings[STRING_SMALL_WORLD + m_worldSize]);
	}

	if(m_pStartGameButton->Render(m_ButtonEventtype) == true)
	{
		m_returnNumber = 2;
		is_running = false;
	}

	if(m_pReturnButton->Render(m_ButtonEventtype) == true)
	{
		m_returnNumber = 4;
		is_running = false;
	}
}