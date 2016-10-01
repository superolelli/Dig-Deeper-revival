#include "Button.hpp"



CButton::CButton()
{

}


CButton::~CButton()
{
}



//Loads the texture, sets the position and type of the button
void CButton::Load(sf::Texture const &_texture, int _x, int _y, Buttontypes _type, std::string const &_str)
{
	//(int)(type/2) is 2 for up/down and 3 for motion_up/motion_down buttons
	m_ButtonSprite.Load(_texture, 2 + (int)(static_cast<int>(_type) / 2), _texture.getSize().x / (2 + (int)(static_cast<int>(_type) / 2)), _texture.getSize().y);

	//set the button's position and type
	m_ButtonSprite.SetPos(_x, _y);
	m_Buttontype = _type;

	//sets the buttonstring
	m_Buttonstring = _str;
	m_Buttontext.setString(m_Buttonstring);

	m_Buttontext.setPosition(m_ButtonSprite.GetRect().left + (m_ButtonSprite.GetRect().width - m_Buttontext.getGlobalBounds().width) / 2, m_ButtonSprite.GetRect().top + (m_ButtonSprite.GetRect().height - m_Buttontext.getGlobalBounds().height) / 2);
}



//sets the button's position
void CButton::SetPos(int _x, int _y)
{
	m_ButtonSprite.SetPos(_x, _y);
	m_Buttontext.setPosition(m_ButtonSprite.GetRect().left + (m_ButtonSprite.GetRect().width - m_Buttontext.getGlobalBounds().width) / 2, m_ButtonSprite.GetRect().top + (m_ButtonSprite.GetRect().height - m_Buttontext.getGlobalBounds().height) / 2);
}


void CButton::SetScale(float _x, float _y)
{
	m_ButtonSprite.SetScale(_x, _y);
	m_Buttontext.setCharacterSize(static_cast<int>(static_cast<float>(m_Buttontext.getCharacterSize())* _x));
}

//specifies the attributes of the buttontext
void CButton::SetButtontext(sf::Font const &_font, int _charactersize, sf::Color const &_color, sf::Text::Style _style)
{
	m_Buttontext.setFont(_font);
	m_Buttontext.setCharacterSize(_charactersize);
	m_Buttontext.setFillColor(_color);

	m_Buttontext.setStyle(_style);

	m_Buttontext.setPosition(m_ButtonSprite.GetRect().left + (m_ButtonSprite.GetRect().width - m_Buttontext.getGlobalBounds().width) / 2, m_ButtonSprite.GetRect().top + (m_ButtonSprite.GetRect().height - m_Buttontext.getGlobalBounds().height) / 2);
}


//sets the buttonstring
void CButton::SetButtonstring(std::string const &_buttonstring)
{
	m_Buttonstring = _buttonstring;
	m_Buttontext.setString(_buttonstring);

	m_Buttontext.setPosition(m_ButtonSprite.GetRect().left + (m_ButtonSprite.GetRect().width - m_Buttontext.getGlobalBounds().width) / 2, m_ButtonSprite.GetRect().top + (m_ButtonSprite.GetRect().height - m_Buttontext.getGlobalBounds().height) / 2);
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
				RenderButtontext(_engine);
				return true;
				break;

			case Buttontypes::Down:
				m_ButtonSprite.Render(_engine.GetWindow(), 0.0f);
				RenderButtontext(_engine);
				return false;
				break;

			case Buttontypes::Motion_Up:
				m_ButtonSprite.Render(_engine.GetWindow(), 2.0f);
				RenderButtontext(_engine);
				return true;
				break;

			case Buttontypes::Motion_Down:
				m_ButtonSprite.Render(_engine.GetWindow(), 1.0f);
				RenderButtontext(_engine);
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
				RenderButtontext(_engine);
				return false;
				break;

			case Buttontypes::Down:
				m_ButtonSprite.Render(_engine.GetWindow(), 1.0f);
				RenderButtontext(_engine);
				return true;
				break;

			case Buttontypes::Motion_Up:
				m_ButtonSprite.Render(_engine.GetWindow(), 2.0f);
				RenderButtontext(_engine);
				return false;
				break;

			case Buttontypes::Motion_Down:
				m_ButtonSprite.Render(_engine.GetWindow(), 2.0f);
				RenderButtontext(_engine);
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

			RenderButtontext(_engine);

			return false;
		}
	}


	m_ButtonSprite.Render(_engine.GetWindow(), 0.0f);

	//draws the text
	RenderButtontext(_engine);

	return false;
}




void CButton::RenderButtontext(CGameEngine & _engine)
{
	if (m_Buttonstring != "")
		_engine.GetWindow().draw(m_Buttontext);
}



