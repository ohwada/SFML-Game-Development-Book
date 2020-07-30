// Command queues 
// Now that the interface to distribute a command inside the scene graph is ready, we need a way to transport commands to the world and the scene graph. For this purpose, we write a new class CommandQueue. 
// This class is a very thin wrapper around a queue of commands. A queue is a FIFO (first in, first out) data structure

// original : https://github.com/SFML/SFML-Game-Development-Book/blob/master/04_Input/Source/CommandQueue.cpp

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
