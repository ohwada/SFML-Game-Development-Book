// https://github.com/SFML/SFML-Game-Development-Book/blob/master/07_Gameplay/Source/CommandQueue.cpp

#include <Book/CommandQueue.hpp>
#include <Book/SceneNode.hpp>


void CommandQueue::push(const Command& command)
{
	mQueue.push(command);
}

Command CommandQueue::pop()
{
	Command command = mQueue.front();
	mQueue.pop();
	return command;
}

bool CommandQueue::isEmpty() const
{
	return mQueue.empty();
}
