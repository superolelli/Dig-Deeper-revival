#include "SpriteWithText.hpp"



void CSpriteWithText::Load(sf::Texture const & _texture)
{
	m_sprite.Load(_texture);
	m_texts.clear();
}



int CSpriteWithText::AddText(std::string const &_str, sf::Font const & _font, int _characterSize, int _xPos, int _yPos, sf::Color const & _color, sf::Text::Style _style)
{
	//sets up the text
	sf::Text text;
	text.setString(_str);
	text.setFont(_font);
	text.setCharacterSize(_characterSize);
	text.setFillColor(_color);
	text.setStyle(_style);
	text.setPosition(static_cast<float>(m_sprite.GetRect().left + _xPos), static_cast<float>(m_sprite.GetRect().top + _yPos));

	//adds the text
	m_texts.push_back(text);

	//returns the index of the tex
	return m_texts.size() -1;
}


void CSpriteWithText::SetPos(int _x, int _y)
{
	//get the current position of the sprite
	auto xSprite = m_sprite.GetRect().left;
	auto ySprite = m_sprite.GetRect().top;

	//change the position of the sprite
	m_sprite.SetPos(_x, _y);

	//change the position of the texts
	for (auto t : m_texts)
		t.setPosition(_x + (t.getPosition().x - xSprite), _y + (t.getPosition().y - ySprite));
}


void CSpriteWithText::Scale(float _x, float _y)
{
	//scale the sprite
	m_sprite.SetScale(_x, _y);

	//scale the texts
	for (auto t : m_texts)
		t.setCharacterSize(static_cast<int>(t.getCharacterSize() * _x));
}


void CSpriteWithText::Render(sf::RenderTarget & _target, sf::IntRect * _clip)
{
	//renders the sprite
	m_sprite.Render(_target, _clip);

	//renders all texts
	for (auto t : m_texts)
		_target.draw(t);
}
