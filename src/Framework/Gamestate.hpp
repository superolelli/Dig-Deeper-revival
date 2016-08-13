#pragma once


#include "Gameengine.hpp"

class CGameState
{
public:
	virtual void Init(CGameEngine *_gameEngine) = 0;
	virtual void Cleanup() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents() = 0;
	virtual void Update() = 0;
	virtual void Render(double _normalizedTimestep) = 0;

protected: 
	CGameState() { }

private:  
	CGameEngine *m_pGameEngine;   //a pointer to the game engine
};
