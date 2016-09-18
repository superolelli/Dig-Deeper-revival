#include "Gameengine.hpp"
#include "Gamestate.hpp"

void CGameEngine::Init(std::string const &_name)
{
	m_Window.Init(_name);

	m_running = true;
}



void CGameEngine::Quit()
{
	ClearStates();
	m_Window.Quit();
}



void CGameEngine::Run()
{
	double lag = 0.0;

	//the game loop
	while (m_running)
	{
		//update the timer and calculate the lag
		g_pTimer->Update();
		lag += static_cast<double>(g_pTimer->GetElapsedTime().asMicroseconds()) / 1000.0;

		//updates
		while (lag >= MS_PER_UPDATE)
		{
			//process events
			m_pStates.back()->HandleEvents();

			m_pStates.back()->Update();
			lag -= MS_PER_UPDATE;
		}

		//renders
 		m_pStates.back()->Render(lag / (double)MS_PER_UPDATE);
	}
}




void CGameEngine::ChangeState(CGameState * _state)
{
	//Clear all states
	ClearStates();

	//add the new state
	PushState(_state);
}




void CGameEngine::ClearStates()
{
	//delete every state on the stack
	for (auto state : m_pStates)
	{
		state->Cleanup();
		SAFE_DELETE(state);
	}

	m_pStates.clear();
}




void CGameEngine::PushState(CGameState * _state)
{
	_state->Init(this);
	m_pStates.push_back(_state);
}




void CGameEngine::PopState()
{
	m_pStates.back()->Cleanup();
	m_pStates.pop_back();
}
