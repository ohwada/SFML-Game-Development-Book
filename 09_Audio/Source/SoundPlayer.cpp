// SoundPlayer
// Sound effects
// We have many gameplay events that can be represented by sounds: Fired machineguns, launched missiles, explosions, collection of pickups, 
// We implement a class for the sound effects, one similar to the MusicPlayer class
// The class contains a resource holder for the sound buffers and a list of currentlyactive sound effects. Since more than one sound effect may be active at the sametime, we need a container.

// In the constructor, we load all of the sound effects. We do this by calling theSoundBufferHolder::load() function, in a similar fashion to the textures andfonts we loaded in earlier chapters. 
// The first argument we pass is a SoundEf-fect::ID enumerator, the second is the filename:


// How do we play a sound? 
// First, we have to look up the correct sound buffer bycalling SoundBufferHolder::get(). 
// We add a new sf::Sound instance that uses this sound buffer to the list of sounds. 
// Then, we obtain a reference to thesound and call sf::Sound::play() to play the sound


// https://github.com/SFML/SFML-Game-Development-Book/blob/master/09_Audio/Source/SoundPlayer.cpp

#include <Book/SoundPlayer.hpp>

#include <SFML/Audio/Listener.hpp>

#include <cmath>


namespace
{
	// Sound coordinate system, point of view of a player in front of the screen:
	// X = left; Y = up; Z = back (out of the screen)
	const float ListenerZ = 300.f;
	const float Attenuation = 8.f;
	const float MinDistance2D = 200.f;
	const float MinDistance3D = std::sqrt(MinDistance2D*MinDistance2D + ListenerZ*ListenerZ);
}

SoundPlayer::SoundPlayer()
: mSoundBuffers()
, mSounds()
{
	mSoundBuffers.load(SoundEffect::AlliedGunfire,	"Media/Sound/AlliedGunfire.wav");
	mSoundBuffers.load(SoundEffect::EnemyGunfire,	"Media/Sound/EnemyGunfire.wav");
	mSoundBuffers.load(SoundEffect::Explosion1,		"Media/Sound/Explosion1.wav");
	mSoundBuffers.load(SoundEffect::Explosion2,		"Media/Sound/Explosion2.wav");
	mSoundBuffers.load(SoundEffect::LaunchMissile,	"Media/Sound/LaunchMissile.wav");
	mSoundBuffers.load(SoundEffect::CollectPickup,	"Media/Sound/CollectPickup.wav");
	mSoundBuffers.load(SoundEffect::Button,			"Media/Sound/Button.wav");

	// Listener points towards the screen (default in SFML)
	sf::Listener::setDirection(0.f, 0.f, -1.f);
}

void SoundPlayer::play(SoundEffect::ID effect)
{
	play(effect, getListenerPosition());
}

void SoundPlayer::play(SoundEffect::ID effect, sf::Vector2f position)
{
	mSounds.push_back(sf::Sound());
	sf::Sound& sound = mSounds.back();

	sound.setBuffer(mSoundBuffers.get(effect));
	sound.setPosition(position.x, -position.y, 0.f);
	sound.setAttenuation(Attenuation);
	sound.setMinDistance(MinDistance3D);

	sound.play();
}

void SoundPlayer::removeStoppedSounds()
{
	mSounds.remove_if([] (const sf::Sound& s)
	{
		return s.getStatus() == sf::Sound::Stopped;
	});
}

void SoundPlayer::setListenerPosition(sf::Vector2f position)
{
	sf::Listener::setPosition(position.x, -position.y, ListenerZ);
}

sf::Vector2f SoundPlayer::getListenerPosition() const
{
	sf::Vector3f position = sf::Listener::getPosition();
	return sf::Vector2f(position.x, -position.y);
}
