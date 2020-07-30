10_Network - SFML-Game-Development-Book
===============

### Chapter 10. Company Atop the Clouds- Co-op Multiplayer
This is where we will handle a topic with growing importance in the modern times networking. 
The following is what this chapter has to teach essentially:

- Network sockets
- Client-server architecture
- Creating a protocol for communication
- Applying the concepts to our game
- Short introduction on latency problems
- Tips and tricks on cheating prevention


#### MultiplayerGameState
// this is very similar to GameState
// you see, the three typical state-related methods to draw, update, and handleEvent
//To avoid creating one state for each of those options, we created a custom constructor for MultiplayerGameState, which takes aparameter clearly stating whether this state will be hosting or just joining. 


#### GameServer
put the server in a separate thread. 
This is very usefulin many ways. 
For once, server processing can be intensive and could hurt the frame rate on the client. 
On the other hand, if the server is running on a parallel thread, aside from improving its performance, it also allows it to perform blocking calls whenever necessary, and the game keeps running smoothly. 

#### NetworkNode
This class lets objects in the scene directly send events over the network:
This class holds a queue of game actions that are going to be transmitted. 

#### Menu State
draw buttons as below <br/>
- Play
- Host
- Join
- Setting
- Exit

<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/10_Network/screenshot/screenshot_game.png" width="300" />

#### Host Mode
players aircraft fly on the jungle <br/>
<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/10_Network/screenshot/screenshot_host.png" width="300" />

#### Join Mode
two aircrafts (host and joined ) fly on the jungle <br/>
<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/10_Network/screenshot/screenshot_join.png" width="300" />

#### control aircraft
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
- https://github.com/SFML/SFML-Game-Development-Book/

