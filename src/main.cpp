#include"Game\Examplestate.hpp"


int main()
{
	CGameEngine engine;

	engine.Init("Test");
	engine.PushState(new CGame());
	engine.Run();

	engine.Quit();

	return 0;
}