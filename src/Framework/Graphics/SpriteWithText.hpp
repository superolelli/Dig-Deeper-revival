#pragma once


#include "Sprite.hpp"



class CSpriteWithText
{
public:

	//loads the sprite
	void Load(sf::Texture const &_texture);

	//adds text to the sprite and returns the index
	int AddText(std::string const &_str, sf::Font const &_font, int _characterSize, int _xPos, int _yPos, sf::Color const&_color, sf::Text::Style _style = sf::Text::Style::Regular);
	
	//If needed: ChangeString(int _index) or similar functions

	//sets the position of the sprite
	void SetPos(int _x, int _y);

	//scale the sprite
	void Scale(float _x, float _y);

	//renders the sprite
	void Render(sf::RenderTarget &_target, sf::IntRect *_clip = nullptr);

private:

	//the sprite
	CSprite m_sprite;

	//all the texts on the sprite
	std::vector<sf::Text> m_texts;
};