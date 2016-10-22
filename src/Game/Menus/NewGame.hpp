#pragma once


#include "../../Framework/Gamestate.hpp"
#include "../../Framework/Graphics/Sprite.hpp"
#include "../../Framework/Graphics/SpriteWithText.hpp"

#include "../../Framework/Gui/StringInput.hpp"
#include "../../Framework/Gui/Button.hpp"

#include "../../Game/Resources/Resources.hpp"


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

	void LoadWorldSizePanel();
	void LoadButtons();
	void LoadClassDescriptions();

	void RenderButtons();

};



//
//class CNewGame
//{
//public:
//
//	CNewGame();
//	void Init();
//	int Run();
//	SNewWorldAttributes Quit();
//
//private:
//
//	CSprite *m_pBackground;                           //the background
//	CButton *m_pClassLeft;
//	CButton *m_pClassRight;
//	CButton *m_pWorldLeft;
//	CButton *m_pWorldRight;
//	CButton *m_pStartGameButton;                       //the button for a new game
//	CButton *m_pReturnButton;
//
//	CSpriteWithText *m_pClass[4];
//	Text m_ClassTitle[4];
//	CSpriteWithText m_pWorldSize;
//
//	CStringInput m_GameName;                              //the name of the game
//
//	int m_class;                                           //currently chosen class
//	int m_worldSize;                                         //currently chosen world size
//
//	int m_returnNumber;                                //the number, which is returned
//	int m_ButtonEventtype;                           //the event, important for the buttons
//	bool is_running;                                 //is it still running?
//
//	void RenderButtons();
//
//};


