#include "NewGame.hpp"




void NewGameMenu::Init(CGameEngine *_engine)
{
	m_pGameEngine = _engine;


	//Loads the background
	background.Load(g_pTextures->t_backgroundNewGame);
	
	LoadClassDescriptions();
	LoadWorldSizePanel();
	LoadButtons();

	gameNameInputField.Init(g_pFonts->f_ltromatic, 40, _engine->GetWindowSize().x / 2, _engine->GetWindowSize().y / 9, sf::Color(230, 220, 0));
	gameNameInputField.SetString(g_pStringContainer->m_Strings[String_new_world]);


	currentClass = 0;
	currentWorldSize = 0;

	startGame = false;
}


void NewGameMenu::LoadWorldSizePanel()
{
	worldSizePanel.Load(g_pTextures->t_newGameWorldSize);
	auto textID = worldSizePanel.AddText(g_pStringContainer->m_Strings[String_small_world]);
	worldSizePanel.SetTextCharacterSize(textID, 27);
	worldSizePanel.SetTextFont(textID, g_pFonts->f_plantc);
	worldSizePanel.SetTextStyle(textID, sf::Text::Style::Bold);
	worldSizePanel.SetPos((float)m_pGameEngine->GetWindowSize().x / 1.5f, (float)m_pGameEngine->GetWindowSize().y / 2.0f);
	worldSizePanel.SetTextPosCentered(textID);
}



void NewGameMenu::LoadClassDescriptions()
{
	classDescriptions[Miner].Load(g_pTextures->t_newGameMiner);
	classDescriptions[Builder].Load(g_pTextures->t_newGameBuilder);
	classDescriptions[Warrior].Load(g_pTextures->t_newGameWarrior);
	classDescriptions[Mage].Load(g_pTextures->t_newGameMage);

	auto titleID = classDescriptions[Miner].AddText(g_pStringContainer->m_Strings[String_miner]);

	classDescriptions[Builder].AddText(g_pStringContainer->m_Strings[String_builder]);
	classDescriptions[Warrior].AddText(g_pStringContainer->m_Strings[String_warrior]);
	classDescriptions[Mage].AddText(g_pStringContainer->m_Strings[String_mage]);

	auto descriptionID = classDescriptions[Miner].AddText(g_pStringContainer->m_Strings[String_miner_info]);

	classDescriptions[Builder].AddText(g_pStringContainer->m_Strings[String_builder_info]);
	classDescriptions[Warrior].AddText(g_pStringContainer->m_Strings[String_warrior_info]);
	classDescriptions[Mage].AddText(g_pStringContainer->m_Strings[String_mage_info]);
	

	for (auto &c : classDescriptions)
	{
		c.SetPos(m_pGameEngine->GetWindowSize().x / 5, m_pGameEngine->GetWindowSize().y / 4);

		c.SetTextCharacterSize(titleID, 30);
		c.SetTextFont(titleID, g_pFonts->f_plantc);
		c.SetTextColor(titleID, sf::Color(0, 100, 0));
		c.SetTextStyle(titleID, sf::Text::Style(sf::Text::Style::Bold | sf::Text::Style::Underlined));
		c.SetTextPos(titleID, 0, 0);
		c.SetTextPosXCentered(titleID);

		c.SetTextCharacterSize(descriptionID, 25);
		c.SetTextFont(descriptionID, g_pFonts->f_plantc);
		c.SetTextPos(descriptionID, 15, 250);
	}
}


void NewGameMenu::LoadButtons()
{
	buttons[StartGame].Load(g_pTextures->t_buttonMainMenu, Buttontypes::Motion_Up, g_pStringContainer->m_Strings[String_start_game]);
	buttons[StartGame].SetButtontextFont(g_pFonts->f_valken);
	buttons[StartGame].SetButtontextCharactersize(27);
	
	buttons[Return].Load(g_pTextures->t_buttonMainMenu, Buttontypes::Motion_Up, g_pStringContainer->m_Strings[String_return]);
	buttons[Return].SetButtontextFont(g_pFonts->f_valken);
	buttons[Return].SetButtontextCharactersize(27);

	buttons[ClassLeft].Load(g_pTextures->t_buttonLeft, Buttontypes::Up);
	buttons[ClassRight].Load(g_pTextures->t_buttonRight, Buttontypes::Up);
	buttons[WorldLeft].Load(g_pTextures->t_buttonLeft, Buttontypes::Up);
	buttons[WorldRight].Load(g_pTextures->t_buttonRight, Buttontypes::Up);

	
	auto distanceLeftButton = 120;
	auto distanceRightButton = 10;
	auto distanceButtonsTop = 37;

	buttons[StartGame].SetPos(m_pGameEngine->GetWindowSize().x - m_pGameEngine->GetWindowSize().x / 6 - buttons[StartGame].GetRect().width, m_pGameEngine->GetWindowSize().y - m_pGameEngine->GetWindowSize().y / 6 - buttons[StartGame].GetRect().height);
	buttons[Return].SetPos(m_pGameEngine->GetWindowSize().x / 6, m_pGameEngine->GetWindowSize().y - m_pGameEngine->GetWindowSize().y / 6 - buttons[Return].GetRect().height);
	buttons[ClassLeft].SetPos(classDescriptions[Miner].GetRect().left - distanceLeftButton, classDescriptions[Miner].GetRect().top + classDescriptions[Miner].GetRect().height / 2 - distanceButtonsTop);
	buttons[ClassRight].SetPos(classDescriptions[Miner].GetRect().left + classDescriptions[Miner].GetRect().width + distanceRightButton, classDescriptions[Miner].GetRect().top + classDescriptions[Miner].GetRect().height / 2 - distanceButtonsTop);
	buttons[WorldLeft].SetPos(worldSizePanel.GetRect().left - distanceLeftButton, worldSizePanel.GetRect().top + worldSizePanel.GetRect().height / 2 - distanceButtonsTop);
	buttons[WorldRight].SetPos(worldSizePanel.GetRect().left + worldSizePanel.GetRect().width + distanceRightButton, worldSizePanel.GetRect().top + worldSizePanel.GetRect().height / 2 - distanceButtonsTop);
}


void NewGameMenu::Cleanup()
{
	m_pGameEngine = nullptr;
}



void NewGameMenu::Pause()
{
}



void NewGameMenu::Resume()
{
}




void NewGameMenu::HandleEvents()
{
	m_pGameEngine->ProcessEvents();
}



void NewGameMenu::Update()
{
	if (buttons[ClassLeft].Update(*m_pGameEngine))
	{
		currentClass--;
		if (currentClass < 0)
			currentClass = 3;
	}

	if (buttons[ClassRight].Update(*m_pGameEngine))
	{
		currentClass++;
		if (currentClass > 3)
			currentClass = 0;
	}

	if (buttons[WorldLeft].Update(*m_pGameEngine))
	{
		currentWorldSize--;
		if (currentWorldSize < 0)
			currentWorldSize = 2;

		worldSizePanel.ChangeString(0, g_pStringContainer->m_Strings[String_small_world + currentWorldSize]);
	}

	if (buttons[WorldRight].Update(*m_pGameEngine))
	{
		currentWorldSize++;
		if (currentWorldSize > 2)
			currentWorldSize = 0;

		worldSizePanel.ChangeString(0, g_pStringContainer->m_Strings[String_small_world + currentWorldSize]);
	}


	if (buttons[StartGame].Update(*m_pGameEngine))
	{
		startGame = true;
	}


	if (buttons[Return].Update(*m_pGameEngine))
	{
		m_pGameEngine->PopState();
	}
}

void NewGameMenu::Render(double _normalizedTimestep)
{
	m_pGameEngine->ClearWindow(sf::Color::Black);

	gameNameInputField.HandleInput(*m_pGameEngine);

	//Renders everything
	background.Render(m_pGameEngine->GetWindow());

	gameNameInputField.Render(m_pGameEngine->GetWindow());

	classDescriptions[currentClass].Render(m_pGameEngine->GetWindow());
	worldSizePanel.Render(m_pGameEngine->GetWindow());

	RenderButtons();

	m_pGameEngine->FlipWindow();

	if(startGame)
		m_pGameEngine->ChangeState(new Game());
}


//renders all buttons
void NewGameMenu::RenderButtons()
{
	buttons[ClassLeft].Render(*m_pGameEngine);
	buttons[ClassRight].Render(*m_pGameEngine);
	buttons[WorldLeft].Render(*m_pGameEngine);
	buttons[WorldRight].Render(*m_pGameEngine);
	buttons[StartGame].Render(*m_pGameEngine);
	buttons[Return].Render(*m_pGameEngine);
}




