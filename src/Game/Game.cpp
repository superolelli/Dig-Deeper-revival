#include "Game.hpp"



void Game::Init(CGameEngine * _engine)
{
	m_pGameEngine = _engine;

	world.Init();
	world.GenerateWorld(50, 50);

	collisionDetector.Init(&world);

	player.Init(m_pGameEngine, &collisionDetector);

	playerInteraction.Init(&world, m_pGameEngine);

	view.reset(sf::FloatRect(0, 0, (float)_engine->GetWindowSize().x, (float)_engine->GetWindowSize().y));
	SetViewForPlayer();
}


void Game::Cleanup()
{
	player.Quit();

	SetViewForGUI();

	m_pGameEngine = nullptr;
}


void Game::Pause()
{
}


void Game::Resume()
{
}


void Game::HandleEvents()
{
	m_pGameEngine->ProcessEvents();
}


void Game::Update()
{
	if(m_pGameEngine->GetKeystates(KeyID::Escape) == Keystates::Pressed)
		m_pGameEngine->ChangeState(new CMainMenu());

	sf::IntRect vRect;
	vRect.left = view.getCenter().x - view.getSize().x / 2;
	vRect.top = view.getCenter().y - view.getSize().y / 2;
	vRect.width = view.getSize().x;
	vRect.height = view.getSize().y;
		
	world.Update(vRect);

	player.Update();

	playerInteraction.Update();

	UpdateView();
}



void Game::UpdateView()
{
	sf::Vector2f playerCenter;

	playerCenter.x = (float)(player.GetExtrapolatedPos().x) + player.GetRect().width / 2;
	playerCenter.y = (float)(player.GetExtrapolatedPos().y) + player.GetRect().height / 2;

	//check for world bounds
	if (playerCenter.x < view.getSize().x / 2)
		playerCenter.x = view.getSize().x / 2;
	if (playerCenter.x > world.GetDimensions().x * 100 - view.getSize().x / 2)
		playerCenter.x = world.GetDimensions().x * 100 - view.getSize().x / 2;
	if (playerCenter.y < view.getSize().y / 2)
		playerCenter.y = view.getSize().y / 2;
	if (playerCenter.y > world.GetDimensions().y * 100 - view.getSize().y / 2)
		playerCenter.y = world.GetDimensions().y * 100 - view.getSize().y / 2;

	view.setCenter(playerCenter);
}


void Game::Render(double _normalizedTimestep)
{
	m_pGameEngine->ClearWindow(sf::Color::Black);

	SetViewForPlayer();

	ExtrapolationUpdate(_normalizedTimestep);

	world.Render(m_pGameEngine->GetWindow(), _normalizedTimestep);

	playerInteraction.Render();

	player.Render(g_pTimer->GetElapsedTime().asMilliseconds());

	m_pGameEngine->FlipWindow();
}


void Game::ExtrapolationUpdate(double normalizedTimestep)
{
	player.ExtrapolationUpdate(normalizedTimestep);
	UpdateView();
}

