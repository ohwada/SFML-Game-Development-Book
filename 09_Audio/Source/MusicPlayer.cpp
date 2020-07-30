// MusicPlayer
// Music themes
// First, we want to play background music depending on the state we are currently in.
// Well then create a class that has an interface dedicated to music playing: MusicPlayer

// The method names should be self-explanatory. 
//  mMusic() : We have a single sf::Music instance that represents the currently-played music. 
// mFilenames() : The mFilenames variablemaps music IDs to filenames and is initialized in the constructor. 
// mVolume() :  The volume takesa value between 0 and 100; we'll initialize it to full volume. 
// As SFML does notsupport the MP3 format, we'll use OGG for our files. 


// Loading and playing
// SFML uses the sf::Music class to deal with music themes. 
// this class behaves differently from other resource classes. 
// Since music themes areusually long and may require a lot of memory, they are not loaded at once intoRAM. 
// Instead, sf::Music streams them from the source media, usually the hard disk. 
// This means that only a short chunk is kept in memory at one time, with new ones loaded as the theme progresses. 
// As a result, the source media must be avail-able for as long as the music is played. 
// For files, this means that you should notunplug an external storage device with the music on it. 


// you can see some new statements. 
// In the MusicPlayer::play() method, the path of the desired music is lookedup in the map. 
// The theme is loaded and possible loading errors are checked. 
// The streaming nature is also the reason why the method of sf::Music to open atheme from the hard disk is named openFromFile() and not loadFromFile()



//  The setVolume() method sets the musics volume to a value in the range [0, 100], with 0 being mute and 100being the maximum volume. 
// The setLoop() method specifies whether the themeis played again as soon as its end is reached; background themes are usuallylooped. 
// The play() method eventually starts the music. 
// Since music and soundeffects use their own threads in SFML, you dont have to update them continuously.
// However, you have to keep the sf::Music object alive as long as the music isbeing played.


// https://github.com/SFML/SFML-Game-Development-Book/blob/master/09_Audio/Source/MusicPlayer.cpp

#include <Book/MusicPlayer.hpp>


MusicPlayer::MusicPlayer()
: mMusic()
, mFilenames()
, mVolume(100.f)
{
	mFilenames[Music::MenuTheme]    = "Media/Music/MenuTheme.ogg";
	mFilenames[Music::MissionTheme] = "Media/Music/MissionTheme.ogg";
}

void MusicPlayer::play(Music::ID theme)
{
	std::string filename = mFilenames[theme];

	if (!mMusic.openFromFile(filename))
		throw std::runtime_error("Music " + filename + " could not be loaded.");

	mMusic.setVolume(mVolume);
	mMusic.setLoop(true);
	mMusic.play();
}

void MusicPlayer::stop()
{
	mMusic.stop();
}

void MusicPlayer::setVolume(float volume)
{
	mVolume = volume;
}

void MusicPlayer::setPaused(bool paused)
{
	if (paused)
		mMusic.pause();
	else
		mMusic.play();
}
