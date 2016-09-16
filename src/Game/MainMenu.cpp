#include "MainMenu.hpp"






void CMainMenu::Init(CGameEngine *_engine)
{
	m_pGameEngine = _engine;

	m_texture.loadFromFile("Data/Sprites/Panels/cookingbook_menu.png");
	m_sprite.Load(m_texture);
	m_sprite.SetPos(300, 200);
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
	if (m_pGameEngine->GetKeystates(KeyID::Escape) == Keystates::Released)
		m_pGameEngine->StopEngine();
}

void CMainMenu::Render(double _normalizedTimestep)
{
	m_pGameEngine->ClearWindow(sf::Color::Black);

	m_sprite.Render(m_pGameEngine->GetWindow());

	m_pGameEngine->FlipWindow();
}
