09_Audio - SFML-Game-Development-Book
===============

### Chapter 9. Cranking Up the Bass -Music and Sound 

EffectsSince the beginning of video games, sound has been a central media in games.
In this chapter, we are going to cover the technical background of embedding audiointo a game, taking the opportunity to have a closer look at SFML's Audio module.We are going to do the following:

- Play different music themes in the background• 
- Play sound effects that correspond to game events such as explosions
- Position sound effects in the 2D world to convey a feeling of spatialsound


#### MusicPlayer
First, we want to play background music depending on the state we are currently in.
Well then create a class that has an interface dedicated to music playing: MusicPlayer


The setVolume() method :  sets the musics volume to a value in the range [0, 100], with 0 being mute and 100being the maximum volume. 
The setLoop() method : specifies whether the themeis played again as soon as its end is reached; background themes are usuallylooped. 
The play() method : eventually starts the music. 


#### SoundPlayer
We have many gameplay events that can be represented by sounds: Fired machineguns, launched missiles, explosions, collection of pickups, 
We implement a class for the sound effects, one similar to the MusicPlayer class
The class contains a resource holder for the sound buffers and a list of currentlyactive sound effects. 


#### SoundNode
We want to embed sound effects in our game and play them whenever appropriate. 
Inside the world, we would like to have a dedicated scene node for sounds, so that we can use our command system to play sounds. 
Well add a SoundNode class,which is a simple adapter to the SoundPlayer class

#### Screen Display
players aircraft and enamys aircrafts fly on the jungle <br/>
<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/09_Audio/screenshot/screenshot_game.png" width="300" />

### control aircraft
- press Left Key, move left
- press Right Key, move right
- press Up Key, move up
- press Down Key, move down 

### build code
g++ Source/*.cpp  -std=c++11 `pkg-config --cflags --libs sfml-all`  -I./Include  <br/>

### run code
Usage: ./a.out <br/>

### Reference <br/>
- https://www.sfml-dev.org/
- http://nedrilad.com/Tutorial/topic-32/SFML-Game-Development-303.html

