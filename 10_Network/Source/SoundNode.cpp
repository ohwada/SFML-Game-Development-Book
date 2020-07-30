// https://github.com/SFML/SFML-Game-Development-Book/blob/master/10_Network/Source/SoundNode.cpp

#include <Book/SoundNode.hpp>
#include <Book/SoundPlayer.hpp>


SoundNode::SoundNode(SoundPlayer& player)
: SceneNode()
, mSounds(player)
{
}

void SoundNode::playSound(SoundEffect::ID sound, sf::Vector2f position)
{
	mSounds.play(sound, position);
}

unsigned int SoundNode::getCategory() const
{
	return Category::SoundEffect;
}
