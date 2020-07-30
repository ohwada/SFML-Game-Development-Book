06_Menus - SFML-Game-Development-Book
===============

#### Chapter 6. Waiting and Maintenance Area – Menus 
Most games have menus and it's something the player expects when opening up a new game.

#### MenuState
The constructor initializes the buttons and packs them into the Container. 
As you can see, the lambda expression we give to the Button is the place where we actually describe the action we want the button to do. 
The rest of the functions are changed to use the GUI container to render and handle events.

display Buttons "Play", "Settings", "Exit" <br/>
<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/06_Menus/screenshot/screenshot_menu.png" width="300" />

####SettingsState
We implement a new state; the SettingsState which you access through a button on the menu. 
What is the purpose for the SettingsState in our example? 
Currently we have the key bindings inside there. 
Everything we need has already been implemented with the GUI, so we only have to define the actual state.

We have put all the binding buttons and the associated labels in a static array, and associate to them the action they bind for. This means we don't have to duplicate a lot of callbacks, which you may have notice are missing. Instead, we have marked the button as one that toggles. 
We also have an updateLabels() function call. It's a helper function to make sure the labels are writing out the correct name for the key.


display Buttons  "Move Left", "Move Right", "Move Up", "Move Down", "Back" <br/>
<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/06_Menus/screenshot/screenshot_setting.png" width="300" />

#### GameState
aircraft fly over desert <br/>
<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/06_Menus/screenshot/screenshot_game.png" width="300" />

control aircraft <br/>
- press Left key, move left
- press Right key, move right
- press Up key, move up
- press down key, move down


### build code
g++ Source/*.cpp  -std=c++11 `pkg-config --cflags --libs sfml-all`  -I./Include  <br/>

### run code
Usage: ./a.out <br/>

### Reference <br/>
- https://www.sfml-dev.org/
- http://nedrilad.com/Tutorial/topic-32/SFML-Game-Development-196.html

