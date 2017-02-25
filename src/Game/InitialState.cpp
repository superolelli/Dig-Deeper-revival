#include "InitialState.hpp"



void CInitialState::Init(CGameEngine *_engine)
{
	m_pGameEngine = _engine;


	//Loads the background
	m_Background.Load(g_pTextures->t_backgroundLoadingScreen);
}


void CInitialState::Cleanup()
{
	m_pGameEngine = nullptr;
}



void CInitialState::Pause()
{
}



void CInitialState::Resume()
{
}




void CInitialState::HandleEvents()
{
	m_pGameEngine->ProcessEvents();
}




void CInitialState::Update()
{
	//Load the resources
	g_pTextures->LoadTextures();
	g_pFonts->LoadFonts();
	g_pSounds->LoadSounds();
	g_pStringContainer->LoadStrings(CStringContainer::Languages::German);

	m_pGameEngine->ChangeStateImmediately(new CMainMenu());
}



void CInitialState::Render(double _normalizedTimestep)
{
	m_pGameEngine->ClearWindow(sf::Color::Black);

	//Renders everything
	m_Background.Render(m_pGameEngine->GetWindow());

	m_pGameEngine->FlipWindow();
}

