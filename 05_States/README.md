05_States - SFML-Game-Development-Book
===============

#### Chapter 5. Diverting the Game Flow – State Stack 

That is what is going to be covered in this chapter, the ability to make the game richer by adding different states and screens to it. The main bits of knowledge to acquire throughout the chapter are as follows:
 
- The state and the stack 
- Navigating between states 
- Moving our game into a state 
- The title screen as the entry point of the game 
- Our old friend, the main menu 
- Implementing an overlay pause screen 
- A simple example of a concurrent loading state

#### State
State is as an independent screen in the gaming software, 
that is an object that encapsulates the logic and graphics of a determined group of functionality and information.

this game app has the following states
- TitleState
- MenuState
- GameState
- PauseState

state transition <br/>
<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/05_States/screenshot/diagram_state_transition.png" width="300" />

#### The state stack 
put the state on the stack, control state transitions

#### Adding states to StateStack; 
All states in the game have a unique identifier declared in an enum States, located in the StateIdentifiers.hpp file. 
For example, ID States::Game refers to the GameState class.

#### Input: 
Every polled event is fed to the state stack. Then, internally, the stack will deliver that event to the active states:

#### Draw 
Drawing is straightforward; the StateStack class will order every active state to render itself. The first state to be drawn is the lowest and oldest on the stack, and only then come the others, in order. 

#### Application class 
Since we have now more states than the game itself, we create a new class Application that controls input, logic updates, and rendering. 
Having a ready StateStack implementation waiting to be used, it is time to promote it into the Application class. 
We will plug our new state architecture into our Application class and then start using it! 


#### TitleState
display TitleState <br/>
bilnk text "Press any key to start"  <br/>
when press any key, display MenuState <br/>
<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/05_States/screenshot/screenshot_title.png" width="300" />

#### MenuState
draw text "Play" and "Exit" <br/>
when press UP key or Down Key, switch highlight red  "Play" or "Exit" <br/>
when press Enter Key at "Play",  display GameState <br/>
when press Enter Key at "Exit",  exit app <br/>
<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/05_States/screenshot/screenshot_menu.png" width="300" />

#### GameState
draw World that aircraft fly over desert <br/>
when press ESC Key, display PauseState <br/>
<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/05_States/screenshot/screenshot_game.png" width="300" />

control aircraft <br/>
- press Left Key, move left
 - press Right Key, move right
- press Up Key, move up
- press Down Key, move down

#### PauseState
draw text "Game Paused" when press ESC Key, display GameState <br/>
when press BS(delete) Key, display MenuState <br/>
<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/05_States/screenshot/screenshot_pause.png" width="300" />


#### build code
g++ Source/*.cpp  -std=c++11 `pkg-config --cflags --libs sfml-all`  -I./Include  <br/>

#### run code
Usage: ./a.out <br/>

#### with LoadingState
state transition  <br/>
<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/05_States/screenshot/diagram_state_transition_loading.png" width="300" />

build code <br/>
g++ Source2/*.cpp  -std=c++11 `pkg-config --cflags --libs sfml-all`  -I./Include  <br/>

run code <br/>
Usage: ./a.out <br/>

### Reference <br/>
- https://www.sfml-dev.org/
- http://nedrilad.com/Tutorial/topic-32/SFML-Game-Development-165.html

