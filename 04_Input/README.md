04_Input  - SFML-Game-Development-Book
===============

#### Chapter 4. Command and Control – Input Handling
In this chapter we aim to learn: 
- SFML events and their purpose as input 
- SFML real-time input and its difference from events 
- A command-based communication system to deliver events on our world
- How to dynamically bind keys at runtime


#### Commands
commands denote messages that are sent to various game objects. 
A command is able sent to various game objects. 
A command is able to alter the object and to issue orders such as moving an entity, firing a weapon, and triggering an explosion. 


#### Command queues 
Now that the interface to distribute a command inside the scene graph is ready, we need a way to transport commands to the world and the scene graph. For this purpose, we write a new class CommandQueue. 
This class is a very thin wrapper around a queue of commands. A queue is a FIFO (first in, first out) data structure 

  
#### Handling player input 
how the commands can be exploited to react to the SFML events and real-time input. 
Up to now, player input has been handled in the Game class. But it deserves an own class, we call it Player.

#### The Player class
The Player class contains two methods to react to the SFML events and real-time input, respectively:
- handleEvent
- handleRealtimeInput
                                                                                           
#### Keyboard events 
Now the defining feature of a PC, the keyboard. The keyboard generates events as the primary input device available to computers:
- For the event when the user presses down a key, we have the event type sf::Event::KeyPressed. 
- The event sf::Event::KeyReleased is the counterpart to KeyPressed; it is triggered when you release a key.
- Last, we have a little special event that SFML creates for your convenience. It is called sf::Event::TextEntered and is designed for receiving formatted text from the user.

#### Screen Display
draw aircraft image "Eagle" over the background image "Desert" <br/>
<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/04_Input/screenshot/screenshot_input.png" width="300" /><br/>


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
- http://nedrilad.com/Tutorial/topic-32/SFML-Game-Development-129.html

