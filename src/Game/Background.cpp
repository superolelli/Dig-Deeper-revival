#include "Background.hpp"



void Background::Init()
{
	undergroundSprite.Load(g_pTextures->t_backgroundUnderground);
	skySprite.Load(g_pTextures->t_backgroundSky);
}



void Background::Update(sf::IntRect &view)
{
	int spriteHeight, spriteWidth;

	if (view.top < SKY_HEIGHT)
	{
		spriteWidth = skySprite.GetRect().width;
		spriteHeight = skySprite.GetRect().height;
	}
	else
	{
		spriteWidth = undergroundSprite.GetRect().width;
		spriteHeight = undergroundSprite.GetRect().height;
	}


	nextX[0] = view.left - (view.left % spriteWidth);
	nextY[0] = view.top - (view.top % spriteHeight);

	nextX[1] = nextX[0] + spriteWidth;
	nextY[1] = nextY[0];

	nextX[2] = nextX[0];
	nextY[2] = nextY[0] + spriteHeight;
	
	nextX[3] = nextX[1];
	nextY[3] = nextY[2];

	offset[0].left = view.left - nextX[0];
	offset[0].width = spriteWidth - offset[0].left;
	offset[0].top = view.top - nextY[0];
	offset[0].height = spriteHeight - offset[0].top;

	offset[1].left = 0;
	offset[1].top = offset[0].top;
	offset[1].width = view.width - offset[0].width;
	offset[1].height = offset[0].height;

	offset[2].left = offset[0].left;
	offset[2].top = 0;
	offset[2].width = offset[0].width;
	offset[2].height = view.height - offset[0].height;

	offset[3].left = offset[1].left;
	offset[3].top = offset[2].top;
	offset[3].width = offset[1].width;
	offset[3].height = offset[2].height;


	nextX[0] = view.left;
	nextY[0] = view.top;
	nextY[1] = nextY[0];
	nextX[2] = nextX[0];
}



void Background::Render(int viewX, int viewY, sf::RenderTarget &target)
{
	if (viewY < SKY_HEIGHT)
	{
		RenderSkySprite(0, target);
		RenderSkySprite(1, target);
	}
	else
	{
		RenderUndergroundSprite(0, target);
		RenderUndergroundSprite(1, target);
	}


	RenderUndergroundSprite(2, target);
	RenderUndergroundSprite(3, target);

	undergroundSprite.SetTextureRectToDefault();
	skySprite.SetTextureRectToDefault();
}




void Background::RenderUndergroundSprite(int index, sf::RenderTarget &target)
{
	undergroundSprite.SetTextureRect(offset[index]);
	undergroundSprite.SetPos(nextX[index], nextY[index]);
	undergroundSprite.Render(target);
}



void Background::RenderSkySprite(int index, sf::RenderTarget &target)
{
	skySprite.SetTextureRect(offset[index]);
	skySprite.SetPos(nextX[index], nextY[index]);
	skySprite.Render(target);
}
