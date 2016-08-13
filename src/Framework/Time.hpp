#pragma once


#include "../Framework/Patterns/singleton.hpp"
#include "SFML\System.hpp"



#define g_pTimer CTime::Get()

class CTime : public TSingleton<CTime>
{
public:

	//starts the clock
	CTime();

	//Updates the clock
	void Update();

	//gives the time since the start of the game
	sf::Time GetCurrentTime(){ return m_current; }

	//gives the time since the last frame
	sf::Time GetElapsedTime(){return m_elapsed;}


private:

	sf::Clock m_clock;
	sf::Time m_current;
	sf::Time m_elapsed;
};



