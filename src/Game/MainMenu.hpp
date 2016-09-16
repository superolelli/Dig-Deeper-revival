#pragma once


#include "../Framework/Gamestate.hpp"
#include "../Framework/Graphics/Sprite.hpp"
#include "../Framework/Gui/Button.hpp"
#include "../Framework/Gui/Beam.hpp"



class CMainMenu : public CGameState
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
	CSprite m_sprite;

};