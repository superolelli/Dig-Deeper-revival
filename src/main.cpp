#include"Game\MainMenu.hpp"


int main()
{
	//Load the resources
	g_pTextures->LoadTextures();
	g_pFonts->LoadFonts();
	g_pSounds->LoadSounds();

	//start the engine
	CGameEngine engine;

	engine.Init("Dig Deeper");
	engine.PushState(new CMainMenu());
	engine.Run();

	engine.Quit();

	return 0;
}