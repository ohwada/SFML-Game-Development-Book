// NetworkNode
// We create a NetworkNode class that lets objects in the scene directly send events over the network:

// This class holds a queue of game actions that are going to be transmitted. 
// ThenotifyGameAction() method inserts a new game action into the queue, 
// whilepollGameAction() checks if an action is pending. 
// If so, it pops the action fromthe queue and stores it in the output parameter just as you know it from SFML'spollEvent() function.

// The network node itself is placed in the World class.  
// A World::pollGameAction() member function acts as a pure forwarder and canbe used in other parts of the game where we only have access to the world, butnot its scene and entities.


// https://github.com/SFML/SFML-Game-Development-Book/blob/master/10_Network/Source/NetworkNode.cpp

#include <Book/NetworkNode.hpp>
#include <Book/NetworkProtocol.hpp>


NetworkNode::NetworkNode()
: SceneNode()
, mPendingActions()
{
}

unsigned int NetworkNode::getCategory() const
{
	return Category::Network;
}

void NetworkNode::notifyGameAction(GameActions::Type type, sf::Vector2f position)
{
	mPendingActions.push(GameActions::Action(type, position));
}

bool NetworkNode::pollGameAction(GameActions::Action& out)
{
	if (mPendingActions.empty())
	{
		return false;
	}
	else
	{
		out = mPendingActions.front();
		mPendingActions.pop();
		return true;
	}
}
