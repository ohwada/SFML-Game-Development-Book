// https://github.com/SFML/SFML-Game-Development-Book/blob/master/10_Network/Source/Main.cpp

#include <Book/Application.hpp>

#include <stdexcept>
#include <iostream>


int main()
{
	try
	{
		Application app;
		app.run();
	}
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}
}
