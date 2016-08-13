#include "Gameengine.hpp"
#include "Gamestate.hpp"


void CGameEngine::Init()
{
}



void CGameEngine::Quit()
{
}



void CGameEngine::Run()
{
	double lag = 0.0;

	//the game loop
	while (true)
	{
		//update the timer and calculate the lag
		g_pTimer->Update();
		lag += static_cast<double>(g_pTimer->GetElapsedTime().asMicroseconds()) / 1000.0;

		//process events
		m_pStates.back()->HandleEvents();

		//updates
		while (lag >= MS_PER_UPDATE)
		{
			m_pStates.back()->Update();
			lag -= MS_PER_UPDATE;
		}

		//renders
		m_pStates.back()->Render(lag / (double)MS_PER_UPDATE);
	}
}




void CGameEngine::ChangeState(CGameState * _state)
{
	//delete every state on the stack
	for (CGameState *state : m_pStates)
	{
		if (state != nullptr)
		{
			delete(state);
			state = nullptr;
		}
	}

	m_pStates.clear();

	//add the new state
	PushState(_state);
}



void CGameEngine::PushState(CGameState * _state)
{
	m_pStates.push_back(_state);
}



void CGameEngine::PopState()
{
	m_pStates.pop_back();
}
