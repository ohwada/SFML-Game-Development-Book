03_World  - SFML-Game-Development-Book
===============

### Chapter 3. Forge of the Gods -Shaping Our World 
This chapter attempts to bring knowledge around a few key topics: 
- Entity systems in concept and practice 
- The viewable area of our world and scrolling 
- Tree-based scene graphs, rendering and updating of many entities 
- Composition of all elements to shape the world

#### Entities 
An entity denotes a game element in the world. In our game, possible entities are friendly and enemy airplanes, bullets, missiles, or pickups that increase the player's strength. Entities interact with each other: enemy airplanes can fire missiles, the player's airplane may evade them, and the missiles may explode if they hit the player's plane, dealing damage to it. 

#### Aircraft 
Using the example of the aircraft, we need to define a concrete entity class. We derive it from Entity. Since we have different airplanes in our game, it would be nice to have a data type that can store them. An enumeration comes in handy;
we call it Type and make it a member of the Aircraft class.   

#### Scene graphs 
In order to manage transform hierarchies in a user-friendly way, we develop a scene graph—a tree data structure consisting of multiple nodes, called scene nodes. Each scene node can store an object that is drawn on the screen, most often this is an entity. 
Each node may have an arbitrary amount of child nodes, which adapt to the transform of their parent node when rendering. Children only store the position, rotation, and scale relative to their parent. 
A scene graph contains a root scene node, which exists only once in a world. 
It resides above all other scene nodes in the hierarchy, thus it has no parent node.                   

#### Scene nodes 
We represent the nodes in the scene graph with a class called SceneNode. 


#### Scene layers 
In the game, we often have different scene nodes that must be rendered in a certain order. Nodes with objects that are located "above" others (closer to the sky) must be drawn after them. For example, we might first draw a desert background, then an oasis and some buildings, above which we draw the planes, and eventually some health bars located in front of them. This is rather cumbersome to handle when we insert node by node to the scene graph, because we have to ensure the order manually. 
Luckily, we can easily automate the ordering, even using the scene graph's current capabilities. We call a group of scene nodes that are rendered together a layer. 


#### SpriteNode
 In order to display our background sprite through the scene graph, 
we created a new SceneNode type, the SpriteNode, which acts as a simple sf::Sprite that can be plugged into our tree structure. Conveniently, this is all we need to make our landscape. 

#### Screen Display
three aircrafts fly over the desert  <br/>
<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/03_World/screenshot/screenshot_world.png" width="300" /><br/>


### build code
g++ Source/*.cpp  -std=c++11 `pkg-config --cflags --libs sfml-all`  -I./Include  <br/>

### run code
Usage: ./a.out <br/>

### Reference <br/>
- https://www.sfml-dev.org/
- http://nedrilad.com/Tutorial/topic-32/SFML-Game-Development-84.html

