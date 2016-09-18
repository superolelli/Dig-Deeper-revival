#pragma once


#include "../Gameengine.hpp"
#include "../Graphics/Sprite.hpp"

enum class Buttontypes{Up, Down, Motion_Up, Motion_Down};

class CButton
{
public:

	CButton();
    ~CButton();

	//Loads the button, defines the type and sets the position
	void Load(sf::Texture const &_texture, int _x, int _y, Buttontypes _type, std::string const &_str = "");

	//Sets the button's position
	void SetPos(int _x, int _y);

	//sets the buttontext
	void SetButtontext(sf::Font const &_font, int _charactersize, sf::Color const &_color, sf::Text::Style _style);

	//sets the buttonstring
	void SetButtonstring(std::string const &_buttonstring);

	//renders the button, returns true if button was pressed
	bool Render(CGameEngine &_engine);

	//Returns the rect
	sf::IntRect const &GetRect() const {return m_ButtonSprite.GetRect();}

private:

	CSprite m_ButtonSprite;                       //the buttonsprite
	Buttontypes m_Buttontype;                       //the buttontype

	std::string m_Buttonstring;                  //the buttonstring
	sf::Text m_Buttontext;

	void RenderButtontext(CGameEngine &_engine);
};

