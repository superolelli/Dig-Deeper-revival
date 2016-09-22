#pragma once


#include "../Framework/Gamestate.hpp"
#include "../Framework/Graphics/Sprite.hpp"
#include "../Framework/Gui/Button.hpp"
#include "../Framework/Gui/Beam.hpp"

#include "Ressources\TextureManager.hpp"
#include "Ressources\FontManager.hpp"
#include "Ressources\SoundManager.hpp"
#include "Ressources\StringManager.hpp"


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
	enum Buttons{Play, Options, Highscore, Quit};

	CSprite m_Background;
	CButton m_Buttons[4];

	void RenderButtons();

};