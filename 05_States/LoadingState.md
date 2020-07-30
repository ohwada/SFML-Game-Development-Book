05_States - SFML-Game-Development-Book
===============

#### Chapter 5. Diverting the Game Flow – State Stack 
add LoadingState

#### MenuState
draw text "Play" and "Exit"
when press Enter Key at "Play",  transition to LoadingState
when press Enter Key at "exit",  exit app

#### LoadingState
display Progress Bar
after 10 seconds, transition to GameState

#### Progress Bar 
We have sf::Text to display our Loading Resources string, two sf::RectangleShape objects for the progress bar background and fill, and a ParallelTask object. 

#### ParallelTask 
we have been able to see that a ParallelTask object runs in the background and allows querying some information about the task's progress. 
To remain as simple as possible explaining the concept of a task executed in a parallel thread, we decided to implement the sample class as a dummy operation that does not do any actual loading, but rather just waits ten seconds for a timer to expire and finalize the task. 


### build code
g++ Source2/*.cpp  -o loading -std=c++11 `pkg-config --cflags --libs sfml-all`  -I./Include  <br/>

### run code
Usage: ./loading <br/>

### Reference <br/>
- https://www.sfml-dev.org/
- https://github.com/SFML/SFML-Game-Development-Book/

