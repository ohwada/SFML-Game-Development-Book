// Commands
// commands denote messages that are sent to various game objects. 
// A command is able sent to various game objects. 
// A command is able to alter the object and to issue orders such as moving an entity, firing a weapon, and triggering an explosion.   

// original : https://github.com/SFML/SFML-Game-Development-Book/blob/master/04_Input/Source/Command.cpp

#include <Book/Command.hpp>


Command::Command()
: action()
, category(Category::None)
{
}
