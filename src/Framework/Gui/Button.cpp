#include "Button.hpp"



CButton::CButton()
{

}


CButton::~CButton()
{
}



//Loads the texture, sets the position and type of the button
void CButton::Load(sf::Texture const &_texture, int _x, int _y, Buttontypes _type)
{
	//(int)(type/2) is 2 for up/down and 3 for motion_up/motion_down buttons
	m_ButtonSprite.Load(_texture, 2 + (int)(_type / 2), _texture.getSize().x / (2 + (int)(_type / 2)), _texture.getSize().y);

	//set the button's position and type
	m_ButtonSprite.SetPos(_x, _y);
	m_Buttontype = _type;
}



//sets the button's position
void CButton::SetPos(int _x, int _y)
{
	m_ButtonSprite.SetPos(_x, _y);
}




bool CButton::Render(CGameEngine &_engine)
{
	 //if the mouse is at the button
	if(m_ButtonSprite.GetRect().contains(_engine.GetMousePos()))
	{
		//If the left mouse button was released
		if(_engine.GetButtonstates(ButtonID::Left) == Released)
		{
			//render the right button frame
			switch(m_Buttontype)
			{
			case Buttontypes::Up:
				m_ButtonSprite.Render(_engine.GetWindow(), 1.0f);
				return true;
				break;

			case Buttontypes::Down:
				m_ButtonSprite.Render(_engine.GetWindow(), 0.0f);
				return false;
				break;

			case Buttontypes::Motion_Up:
				m_ButtonSprite.Render(_engine.GetWindow(), 2.0f);
				return true;
				break;

			case Buttontypes::Motion_Down:
				m_ButtonSprite.Render(_engine.GetWindow(), 1.0f);
				return false;
				break;
			}
		}
		//if the left mouse button was pressed or is held
		else if(_engine.GetButtonstates(ButtonID::Left) == Pressed)
		{
			//Render the right button frame
			switch(m_Buttontype)
			{
			case Buttontypes::Up:
				m_ButtonSprite.Render(_engine.GetWindow(), 1.0f);
				return false;
				break;

			case Buttontypes::Down:
				m_ButtonSprite.Render(_engine.GetWindow(), 1.0f);
				return true;
				break;

			case Buttontypes::Motion_Up:
				m_ButtonSprite.Render(_engine.GetWindow(), 2.0f);
				return false;
				break;

			case Buttontypes::Motion_Down:
				m_ButtonSprite.Render(_engine.GetWindow(), 2.0f);
				return true;
				break;
			}
		}
		else 
		{
			if(m_Buttontype == Buttontypes::Up || m_Buttontype == Buttontypes::Down)
			{
				m_ButtonSprite.Render(_engine.GetWindow(), 0.0f);
			}
			else
				m_ButtonSprite.Render(_engine.GetWindow(), 1.0f);

			return false;
		}
	}


	m_ButtonSprite.Render(_engine.GetWindow(), 0.0f);
	return false;
}




