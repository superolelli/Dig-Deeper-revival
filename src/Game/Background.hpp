#pragma once

#include "../Framework/Graphics/Sprite.hpp"
#include "Resources\TextureManager.hpp"

class Background
{
public:

	void Init();
	void Update(int viewX, int viewY);
	void Render(int viewX, int viewY, sf::RenderTarget &target);

private:


	const int SKY_HEIGHT = 500;
	
	int nextX1, nextY1, 
		nextX2, nextY2, 
		nextX3, nextY3, 
		nextX4, nextY4;

	sf::IntRect offset1, offset2, offset3, offset4;

	CSprite undergroundSprite;
	CSprite skySprite;

};