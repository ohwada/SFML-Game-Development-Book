// SoundNode
// game sound effects
// We want to embed sound effects in our game and play them whenever appropriate. 
// Before we can do that, we need access to the sound player; we let GameState pass a SoundPlayer reference to our World class.
// Inside the world, we would like to have a dedicated scene node for sounds, so that we can use our command system to play sounds. 
// Well add a SoundNode class,which is a simple adapter to the SoundPlayer class


// The getCategory()method returns a new SoundEffect category, while playSound() forwards itsarguments to the mSounds sound player. 
// The sound node is inserted into thescene graph in World::buildScene().
// playLocalSound() method for entities, which sends a command to the sound node. 
// As all of our current sound effects are related to airplanes, we define playLocalSound() in the Aircraft class



// https://github.com/SFML/SFML-Game-Development-Book/blob/master/09_Audio/Source/SoundNode.cpp


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
