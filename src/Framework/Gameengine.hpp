#pragma once


#include <vector>
#include "Time.hpp"
#include "Window.hpp"

class CGameState;

#define MS_PER_UPDATE 16



class CGameEngine
{
public:
	void Init(std::string _name);
	void Run();
	void Quit();

	//changes the current state and deletes the whole stack
	void ChangeState(CGameState* _state);

	//pushes a new state to the stack
	void PushState(CGameState* _state);

	//pops the last state of the stack
	void PopState();

	//stops the engine
	void StopEngine() { m_running = false; }




	//Returns the render window
	sf::RenderWindow &GetWindow() { return *m_Window.GetRenderWindow(); }

	//clears the window
	void ClearWindow(sf::Color const &_color) { m_Window.Clear(_color); }

	//Flips the window
	void FlipWindow() { m_Window.Flip(); }

	//processes the events
	void ProcessEvents() { m_Window.ProcessEvents(); }

	//getters for the key- and buttonstates
	Keystates const &GetKeystates(KeyID _id) const { return m_Window.GetKeystates(_id); }
	Keystates const &GetButtonstates(ButtonID _id) const { return m_Window.GetButtonstates(_id); }
	inline int const GetMouseWheelMovement() const { return m_Window.GetMouseWheelMovement(); }
	inline sf::Vector2i const &GetMousePos() { return m_Window.GetMousePos(); }


private:
	// the stack of states
	std::vector<CGameState*> m_pStates;

	//the window
	CWindow m_Window;

	bool m_running;

	//clears all states
	void ClearStates();
};