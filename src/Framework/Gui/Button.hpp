#pragma once


#include "../Gameengine.hpp"
#include "../Graphics/Sprite.hpp"

enum Buttontypes{Up, Down, Motion_Up, Motion_Down};

class CButton
{
public:

	CButton();
    ~CButton();

	//Loads the button, defines the type and sets the position
	void Load(sf::Texture const &_texture, int _x, int _y, Buttontypes _type);

	//Sets the button's position
	void SetPos(int _x, int _y);

	//renders the button, returns true if button was pressed
	bool Render(CGameEngine &_engine);

	//Returns the rect
	sf::IntRect const &GetRect() const {return m_ButtonSprite.GetRect();}

private:

	CSprite m_ButtonSprite;                       //the buttonsprite
	Buttontypes m_Buttontype;                       //the buttontype

};

