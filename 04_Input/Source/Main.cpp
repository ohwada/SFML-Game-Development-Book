// https://github.com/SFML/SFML-Game-Development-Book/blob/master/04_Input/Source/Main.cpp

#include <Book/Game.hpp>

#include <stdexcept>
#include <iostream>


int main()
{
	try
	{
		Game game;
		game.run();
	}
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}
}
