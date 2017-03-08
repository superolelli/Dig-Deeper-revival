#pragma once

#include "../Framework/Graphics/Sprite.hpp"
#include "Resources\TextureManager.hpp"

class Background
{
public:

	void Init();
	void Update(sf::IntRect &view);
	void Render(int viewX, int viewY, sf::RenderTarget &target);

private:


	const int SKY_HEIGHT = 500;
	
	int nextX[4];
	int nextY[4];

	sf::IntRect offset[4];

	CSprite undergroundSprite;
	CSprite skySprite;

	void RenderUndergroundSprite(int index, sf::RenderTarget &target);
	void RenderSkySprite(int index, sf::RenderTarget &target);

};