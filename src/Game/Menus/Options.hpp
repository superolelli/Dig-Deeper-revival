#pragma once

#include "../../Framework/Gamestate.hpp"
#include "../../Framework/Graphics/Sprite.hpp"
#include "../../Framework/Gui/Button.hpp"

#include "../../Game/Ressources/Resources.hpp"



class COptions : public CGameState
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

	enum Buttons { Settings, Upgrades, Achievements, Return };

	CSprite m_Background;
	CButton m_Buttons[4];

	void RenderButtons();

};
