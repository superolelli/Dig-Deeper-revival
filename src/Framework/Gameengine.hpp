#pragma once


#include <vector>
#include "Time.hpp"

class CGameState;

#define MS_PER_UPDATE 16



class CGameEngine
{
public:
	void Init();
	void Run();
	void Quit();

	//changes the current state and deletes the whole stack
	void ChangeState(CGameState* _state);

	//pushes a new state to the stack
	void PushState(CGameState* _state);

	//pops the last state of the stack
	void PopState();


private:
	// the stack of states
	std::vector<CGameState*> m_pStates;
};