01_Intro - SFML-Game-Development-Book
===============

### Chapter 1. Making a Game Tick
This chapter introduces the SFML library and shows you its capabilities by creating a small application. 

#### A minimal example 
create a shoot-em-up game. 
The player controls an aircraft viewed from the top, and has to find its way through a level full of enemies.

#### Screen Display
draw aircraft image on black bachgroud <br/>
<image src="https://github.com/ohwada?after=Y3Vyc29yOnYyOpK0MjAxNC0wOS0xOFQxNzo0Mjo0M1rOAW0iNQ%3D%3D&tab=repositories" width="300" /><br/>

#### control aircraft
- press W key, move up
- press S key, move down
- press A key, move left
- press D key, move right


### build code
g++ Source/*.cpp  -std=c++11 `pkg-config --cflags --libs sfml-all`  -I./Include  <br/>

### run code
Usage: ./a.out <br/>

### Reference <br/>
- https://www.sfml-dev.org/
- http://nedrilad.com/Tutorial/topic-32/SFML-Game-Development-29.html

