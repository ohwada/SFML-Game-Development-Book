// this is super class for State
// State is as an independent screen in the gaming software, 
// that is an object that encapsulates the logic and graphics of a determined group of functionality and information.

// https://github.com/SFML/SFML-Game-Development-Book/blob/master/05_States/Source/State.cpp

#include <Book/State.hpp>
#include <Book/StateStack.hpp>


State::Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, Player& player)
: window(&window)
, textures(&textures)
, fonts(&fonts)
, player(&player)
{
}

State::State(StateStack& stack, Context context)
: mStack(&stack)
, mContext(context)
{
}

State::~State()
{
}

void State::requestStackPush(States::ID stateID)
{
	mStack->pushState(stateID);
}

void State::requestStackPop()
{
	mStack->popState();
}

void State::requestStateClear()
{
	mStack->clearStates();
}

State::Context State::getContext() const
{
	return mContext;
}
