


#include"Framework\Window.hpp"
#include <iostream>


int main()
{
	CWindow window;
	window.Init();

	while (window.GetKeystates(KeyID::Escape) != Keystates::Released)
	{
		window.Clear(sf::Color::Black);
		
		window.ProcessEvents();

		if (window.GetKeystates(KeyID::B) == Keystates::Released)
			std::cout << "B released!" << std::endl;
		
		if (window.GetKeystates(KeyID::B) == Keystates::Pressed)
			std::cout << "B pressed!" << std::endl;

		if (window.GetKeystates(KeyID::B) == Keystates::Held)
			std::cout << "B held!" << std::endl;

		if (window.GetButtonstates(ButtonID::Left) == Keystates::Pressed)
			std::cout << "Left mouse pressed!" << std::endl;

		if (window.GetMouseWheelMovement() > 0)
			std::cout << "Mouse wheel moved: " << window.GetMouseWheelMovement() << std::endl;

		window.Flip();
	}

	window.Quit();
	return 0;
}