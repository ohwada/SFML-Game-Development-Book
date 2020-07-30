// this is super class for State

// https://github.com/SFML/SFML-Game-Development-Book/blob/master/05_States/Source/State.cpp

#include <Book/State.hpp>
#include <Book/StateStack.hpp>

#include <iostream>


State::Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, Player& player)
: window(&window)
, textures(&textures)
, fonts(&fonts)
, player(&player)
{
std::cout << "State::Context::Context" << std::endl;
}

State::State(StateStack& stack, Context context)
: mStack(&stack)
, mContext(context)
{
std::cout << "State::State" << std::endl;
}

State::~State()
{
std::cout << "State::~State" << std::endl;
}

void State::requestStackPush(States::ID stateID)
{
std::cout << ":requestStackPush" << std::endl;
	mStack->pushState(stateID);
std::cout << ":requestStackPush end" << std::endl;
}

void State::requestStackPop()
{
std::cout << "requestStackPop" << std::endl;
	mStack->popState();
std::cout << "requestStackPop end" << std::endl;
}

void State::requestStateClear()
{
std::cout << "requestStateClear" << std::endl;
	mStack->clearStates();
std::cout << "requestStateClear end" << std::endl;

}

State::Context State::getContext() const
{
std::cout << "State::Context State::getContext" << std::endl;
	return mContext;
}
