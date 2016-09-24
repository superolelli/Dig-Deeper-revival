#include"Game\InitialState.hpp"


int main()
{
	//start the engine
	CGameEngine engine;

	engine.Init("Dig Deeper");
	engine.PushState(new CInitialState());
	engine.Run();

	engine.Quit();

	return 0;
}