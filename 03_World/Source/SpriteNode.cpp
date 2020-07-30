// SpriteNode
// In order to display our background sprite through the scene graph, 
// we created a new SceneNode type, the SpriteNode, which acts as a simple sf::Sprite that can be plugged into our tree structure. 

// original : https://github.com/SFML/SFML-Game-Development-Book/blob/master/03_World/Source/SpriteNode.cpp

#include <Book/SpriteNode.hpp>

#include <SFML/Graphics/RenderTarget.hpp>


SpriteNode::SpriteNode(const sf::Texture& texture)
: mSprite(texture)
{
}	

SpriteNode::SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect)
: mSprite(texture, textureRect)
{
}

void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}