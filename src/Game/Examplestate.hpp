#pragma once


#include "../Framework/Gamestate.hpp"




class CGame : public CGameState
{

public:

	 void Init(CGameEngine *_engine) override;
	 void Cleanup() override;

	 void Pause() override;
	 void Resume() override;

	 void HandleEvents() override;
	 void Update() override;
	 void Render(double _normalizedTimestep) override;
};