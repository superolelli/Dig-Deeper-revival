#include "Settings.hpp"




CSettings::CSettings()
{
	m_pBackground = NULL;
	m_pReturnButton = NULL;
}




//Load the button textures
void CSettings::Init()
{
	is_running = true;
	m_showLanguages = false;

	m_pBackground = new CSprite;
	m_pBackground->Load(&g_pTextures->t_menuBackground);

	m_pBeamNumbersButton = new CButton;
	m_pInventoryNumbersButton = new CButton;
	m_pFastLightButton = new CButton;
	m_pShowLanguagesButton = new CButton;

	char* var = getenv("APPDATA");
	boost::filesystem::path Path;
	Path = var;
	Path.append("/Dig Deeper/Settings_02.stt");

	if (boost::filesystem::exists(Path))
	{
		ifstream inputFile(Path.string(), ios::binary);
		binary_iarchive settingsArchive(inputFile);
		settingsArchive >> m_Settings;
		inputFile.close();
	}
	else
	{
		m_Settings.m_beam_numbers = false;
		m_Settings.m_inventory_numbers = false;
		m_Settings.m_fast_light = false;
		m_Settings.m_language = GERMAN;
		m_Settings.m_showTime = true;
		m_Settings.m_showMap = true;
	}


	m_pBeamNumbersButton->Load(&g_pTextures->t_optionsButton_blank, g_pFramework->GetRenderWindow()->getSize().x / 2 - 100, g_pFramework->GetRenderWindow()->getSize().y / 6, CButton::BUTTONTYPE_MOTION_UP);
	m_pBeamNumbersButton->SetButtontext(&g_pTextures->f_coolsville, 13, Color::Black);
	
	m_pInventoryNumbersButton->Load(&g_pTextures->t_optionsButton_blank, g_pFramework->GetRenderWindow()->getSize().x / 2 - 100, 3 * (g_pFramework->GetRenderWindow()->getSize().y / 6), CButton::BUTTONTYPE_MOTION_UP);
	m_pInventoryNumbersButton->SetButtontext(&g_pTextures->f_coolsville, 13, Color::Black);

	m_pFastLightButton->Load(&g_pTextures->t_optionsButton_blank, g_pFramework->GetRenderWindow()->getSize().x / 2 - 100, 2 * (g_pFramework->GetRenderWindow()->getSize().y / 6), CButton::BUTTONTYPE_MOTION_UP);
	m_pFastLightButton->SetButtontext(&g_pTextures->f_coolsville, 13, Color::Black);

	m_pShowLanguagesButton->Load(&g_pTextures->t_languagesButton, g_pFramework->GetRenderWindow()->getSize().x / 2 - 100, 4 * (g_pFramework->GetRenderWindow()->getSize().y / 6), CButton::BUTTONTYPE_MOTION_UP, g_pStringContainer->m_Strings[STRING_LANGUAGE]);
	m_pShowLanguagesButton->SetButtontext(&g_pTextures->f_coolsville, 13, Color::Black);



	if (m_Settings.m_beam_numbers)
		m_pBeamNumbersButton->SetButtonstring(g_pStringContainer->m_Strings[STRING_BEAMNUMBERS_ON]);
	else
		m_pBeamNumbersButton->SetButtonstring(g_pStringContainer->m_Strings[STRING_BEAMNUMBERS_OFF]);

	if (m_Settings.m_inventory_numbers)
		m_pInventoryNumbersButton->SetButtonstring(g_pStringContainer->m_Strings[STRING_INVENTORYNUMBERS_ON]);
	else
		m_pInventoryNumbersButton->SetButtonstring(g_pStringContainer->m_Strings[STRING_INVENTORYNUMBERS_OFF]);

	if (m_Settings.m_fast_light)
		m_pFastLightButton->SetButtonstring(g_pStringContainer->m_Strings[STRING_FAST_LIGHTRENDERING]);
	else
		m_pFastLightButton->SetButtonstring(g_pStringContainer->m_Strings[STRING_BEAUTIFUL_LIGHTRENDERING]);


	int y = 0;
	for (int i = 0; i < NUMBER_OF_LANGUAGES; i++)
	{
		m_pLanguageButtons[i] = new CButton;
		m_pLanguageButtons[i]->Load(&g_pTextures->t_languageButton_blank, g_pFramework->GetRenderWindow()->getSize().x / 2 + 100, m_pShowLanguagesButton->GetRect().top + y, CButton::BUTTONTYPE_MOTION_UP, g_pStringContainer->m_Strings[STRING_ENGLISH +i]);
		m_pLanguageButtons[i]->SetButtontext(&g_pTextures->f_coolsville, 13, Color::Black);

		y += 30;
	}


	m_pReturnButton = new CButton;
	m_pReturnButton->Load(&g_pTextures->t_menuBlankButton, g_pFramework->GetRenderWindow()->getSize().x / 2 - 100, g_pFramework->GetRenderWindow()->getSize().y - 80, CButton::BUTTONTYPE_MOTION_UP, g_pStringContainer->m_Strings[STRING_RETURN]);
	m_pReturnButton->SetButtontext(&g_pTextures->f_plantc, 27, Color::Black, Text::Bold);
}





void CSettings::Quit()
{
	SAFE_DELETE(m_pBackground);
	SAFE_DELETE(m_pBeamNumbersButton);
	SAFE_DELETE(m_pInventoryNumbersButton);
	SAFE_DELETE(m_pFastLightButton);
	SAFE_DELETE(m_pReturnButton);
	SAFE_DELETE(m_pShowLanguagesButton);
	
	for (int i = 0; i < NUMBER_OF_LANGUAGES; i++)
		SAFE_DELETE(m_pLanguageButtons[i]);
}





void CSettings::Run()
{

	//the loop
	while (is_running == true)
	{
		//Update and clear the Window
		g_pFramework->Update();
		g_pFramework->Clear();

		//get the events
		g_pFramework->ProcessEvents();
		m_ButtonEventtype = 0;

		//If an event happened, important for the buttons, save it (Left mouse up)
		if (g_pFramework->keyStates.leftMouseUp)
			m_ButtonEventtype = MOUSE_LEFT_UP;

		//Render the background
		m_pBackground->Render(g_pFramework->GetRenderWindow());

		//Render the buttons
		RenderButtons();


		g_pFramework->Flip();
	}


	//	ofstream Output("Data/Settings.stt");
	char* var = getenv("APPDATA");
	string Path = var;
	Path.append("/Dig Deeper/Settings_02.stt");

	/*ofstream Output(Path);
	Output.write((char *)&m_Settings, sizeof(m_Settings));
	Output.close();*/

	ofstream outputFile(Path, ios::binary);
	outputFile.clear();
	binary_oarchive settingsArchive(outputFile);
	settingsArchive << m_Settings;
	outputFile.close();

}





void CSettings::RenderButtons()
{

	if (m_pBeamNumbersButton->Render(m_ButtonEventtype))
	{
		if (m_Settings.m_beam_numbers)
		{
			//m_pBeamNumbersButton->Load(&g_pTextures->t_optionsButton_beam_off, g_pFramework->GetRenderWindow()->getSize().x / 2 - 100, g_pFramework->GetRenderWindow()->getSize().y / 6, CButton::BUTTONTYPE_MOTION_UP);
			m_pBeamNumbersButton->SetButtonstring(g_pStringContainer->m_Strings[STRING_BEAMNUMBERS_OFF]);
			m_Settings.m_beam_numbers = false;
		}
		else
		{
			//m_pBeamNumbersButton->Load(&g_pTextures->t_optionsButton_beam_on, g_pFramework->GetRenderWindow()->getSize().x / 2 - 100, g_pFramework->GetRenderWindow()->getSize().y / 6, CButton::BUTTONTYPE_MOTION_UP);
			m_pBeamNumbersButton->SetButtonstring(g_pStringContainer->m_Strings[STRING_BEAMNUMBERS_ON]);
			m_Settings.m_beam_numbers = true;
		}
	}




	if (m_pInventoryNumbersButton->Render(m_ButtonEventtype))
	{
		if (m_Settings.m_inventory_numbers)
		{	
			//m_pInventoryNumbersButton->Load(&g_pTextures->t_optionsButton_inventory_off, g_pFramework->GetRenderWindow()->getSize().x / 2 - 100, 3 * (g_pFramework->GetRenderWindow()->getSize().y / 6), CButton::BUTTONTYPE_MOTION_UP);
			m_pInventoryNumbersButton->SetButtonstring(g_pStringContainer->m_Strings[STRING_INVENTORYNUMBERS_OFF]);
			m_Settings.m_inventory_numbers = false;
		}
		else
		{
			//m_pInventoryNumbersButton->Load(&g_pTextures->t_optionsButton_inventory_on, g_pFramework->GetRenderWindow()->getSize().x / 2 - 100, 3 * (g_pFramework->GetRenderWindow()->getSize().y / 6), CButton::BUTTONTYPE_MOTION_UP);
			m_pInventoryNumbersButton->SetButtonstring(g_pStringContainer->m_Strings[STRING_INVENTORYNUMBERS_ON]);
			m_Settings.m_inventory_numbers = true;
		}
	}


	if (m_pFastLightButton->Render(m_ButtonEventtype))
	{
		if (m_Settings.m_fast_light)
		{
			//m_pFastLightButton->Load(&g_pTextures->t_optionsButton_fastLight_off, g_pFramework->GetRenderWindow()->getSize().x / 2 - 100, 2 * (g_pFramework->GetRenderWindow()->getSize().y / 6), CButton::BUTTONTYPE_MOTION_UP);
			m_pFastLightButton->SetButtonstring(g_pStringContainer->m_Strings[STRING_BEAUTIFUL_LIGHTRENDERING]);
			m_Settings.m_fast_light = false;
		}
		else
		{
			//m_pFastLightButton->Load(&g_pTextures->t_optionsButton_fastLight_on, g_pFramework->GetRenderWindow()->getSize().x / 2 - 100, 2 * (g_pFramework->GetRenderWindow()->getSize().y / 6), CButton::BUTTONTYPE_MOTION_UP);
			m_pFastLightButton->SetButtonstring(g_pStringContainer->m_Strings[STRING_FAST_LIGHTRENDERING]);
			m_Settings.m_fast_light = true;
		}
	}


	//check if the language was changed
	if (m_showLanguages)
	{
		for (int i = 0; i < NUMBER_OF_LANGUAGES; i++)
		{
			if (m_pLanguageButtons[i]->Render(Mouse::isButtonPressed(Mouse::Left)))
			{
				m_Settings.m_language = i;
				g_pStringContainer->LoadStrings(i);

				Quit();
				Init();
			}
		}
	}


	//check the language button
	if (m_pShowLanguagesButton->Render(m_ButtonEventtype))
		m_showLanguages = true;
	else if (Mouse::isButtonPressed(Mouse::Left))
		m_showLanguages = false;


	if (m_pReturnButton->Render(m_ButtonEventtype) == true)
		is_running = false;
}