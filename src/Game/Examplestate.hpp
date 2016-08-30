#pragma once


#include "../Framework/Gamestate.hpp"
#include "../Framework/Graphics/Sprite.hpp"
#include "../Framework/Gui/Button.hpp"



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


private:
	sf::Texture m_texture;
	CButton m_button;
};