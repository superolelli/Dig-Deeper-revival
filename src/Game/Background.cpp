#include "Background.hpp"



void Background::Init()
{
	undergroundSprite.Load(g_pTextures->t_backgroundUnderground);
	skySprite.Load(g_pTextures->t_backgroundSky);
}



void Background::Update(int viewX, int viewY)
{
	if (viewY < SKY_HEIGHT)
	{
		nextX1 = viewX - (viewX % skySprite.GetRect().width);
		nextY1 = viewY - (viewY % skySprite.GetRect().height);

		nextX2 = nextX1 + skySprite.GetRect().width;
		nextY2 = nextY1;

		nextX3 = nextX1;
		nextY3 = nextY1 + skySprite.GetRect().height;
	}
	else
	{
		nextX1 = viewX - (viewX % undergroundSprite.GetRect().width);
		nextY1 = viewY - (viewY % undergroundSprite.GetRect().height);

		nextX2 = nextX1 + undergroundSprite.GetRect().width;
		nextY2 = nextY1;

		nextX3 = nextX1;
		nextY3 = nextY1 + undergroundSprite.GetRect().height;
	}



	nextX4 = nextX2;
	nextY4 = nextY3;
}



void Background::Render(int viewX, int viewY, sf::RenderTarget &target)
{
	if (viewY < SKY_HEIGHT)
	{
		skySprite.SetPos(nextX1, nextY1);
		skySprite.Render(target);

		skySprite.SetPos(nextX2, nextY2);
		skySprite.Render(target);
	}
	else
	{
		undergroundSprite.SetPos(nextX1, nextY1);
		undergroundSprite.Render(target);

		undergroundSprite.SetPos(nextX2, nextY2);
		undergroundSprite.Render(target);
	}

	undergroundSprite.SetPos(nextX3, nextY3);
	undergroundSprite.Render(target);

	undergroundSprite.SetPos(nextX4, nextY4);
	undergroundSprite.Render(target);
}
