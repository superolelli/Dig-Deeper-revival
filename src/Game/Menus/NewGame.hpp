#pragma once


#include "../../Framework/Gamestate.hpp"
#include "../../Framework/Graphics/Sprite.hpp"
#include "../../Framework/Graphics/SpriteWithText.hpp"

#include "../../Framework/Gui/StringInput.hpp"
#include "../../Framework/Gui/Button.hpp"

#include "../../Game/Resources/Resources.hpp"

#include "../Game.hpp"


class NewGameMenu : public GameState
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

	enum Buttons {ClassLeft, ClassRight, WorldLeft, WorldRight, StartGame, Return};
	enum Classes {Miner, Builder, Warrior, Mage, NumClasses};

	CSprite background;

	SpriteWithText classDescriptions[NumClasses];

	SpriteWithText worldSizePanel;
	CButton buttons[6];

	CStringInput gameNameInputField;
	
	int currentClass;
	int currentWorldSize;

	bool startGame;

	void LoadWorldSizePanel();
	void LoadButtons();
	void LoadClassDescriptions();

	void RenderButtons();

};


