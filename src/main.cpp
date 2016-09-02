#include"Game\MainMenu.hpp"


int main()
{
	CGameEngine engine;

	engine.Init("Dig Deeper");
	engine.PushState(new CMainMenu());
	engine.Run();

	engine.Quit();

	return 0;
}