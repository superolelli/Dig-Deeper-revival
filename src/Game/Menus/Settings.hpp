#ifndef SETTINGS_HPP
#define SETTINGS_HPP


#include "Framework.hpp"
#include "Button.hpp"
#include "Structures.hpp"


class CSettings
{
public:

	CSettings();
	void Init();
	void Run();
	void Quit();

private:

	CSprite *m_pBackground;                        //the background

	int m_ButtonEventtype;                           //the event, important for the buttons
	bool is_running;                                 //is it still running?

	bool m_showLanguages;

	SSettings m_Settings;

	CButton* m_pBeamNumbersButton;
	CButton *m_pInventoryNumbersButton;
	CButton *m_pFastLightButton;
	CButton *m_pShowLanguagesButton;
	CButton *m_pLanguageButtons[NUMBER_OF_LANGUAGES];
	CButton *m_pReturnButton;                          //the return button

	void RenderButtons();

};



#endif