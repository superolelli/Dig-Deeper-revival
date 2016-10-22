#pragma once


#include "../../Framework/Gamestate.hpp"
#include "../../Framework/Graphics/Sprite.hpp"
#include "../../Framework/Gui/Button.hpp"
#include "../../Framework/Gui/Beam.hpp"

#include "../../Game/Resources/Resources.hpp"

#include "Options.hpp"
#include "GameMenu.hpp"


class CMainMenu : public GameState
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