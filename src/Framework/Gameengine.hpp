#pragma once


#include <vector>
#include "Time.hpp"
#include "Window.hpp"

class CGameState;

#define MS_PER_UPDATE 16



class CGameEngine
{
public:
	void Init(std::string _name);
	void Run();
	void Quit();

	//changes the current state and deletes the whole stack
	void ChangeState(CGameState* _state);

	//pushes a new state to the stack
	void PushState(CGameState* _state);

	//pops the last state of the stack
	void PopState();

	//returns the window
	CWindow *GetWindow() { return &m_Window; }

	//stops the engine
	void StopEngine() { m_running = false; }


private:
	// the stack of states
	std::vector<CGameState*> m_pStates;

	//the window
	CWindow m_Window;

	bool m_running;

	//clears all states
	void ClearStates();
};