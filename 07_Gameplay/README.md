07_Gameplay - SFML-Game-Development-Book
===============

#### Chapter 7. Warfare Unleashed – Implementing Gameplay
In this chapter, we are going to populate the world, and implement the core part of the game; the actual gameplay with enemies, weapons, battles, and goodies. 
We are going to cover the following topics: 

- Enemy aircraft controlled by a simple artificial intelligence 
- Projectiles such as a machine gun or missiles 
- Pickups that improve the player's equipment 
- Collision detection and response between entities in the scene graph 
- The world's update cycle and automatic removal of entities

##### Entity
As a quick reminder, the SceneNode base class was inherited by the Entity class. 
Entities are the central part of this chapter. 
Its all about the interaction between entities of different kinds. 
Before starting to implement all those interactions, it is reasonable to think about crucial properties our entities need to have.

node inheritance <br/>
<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/07_Gameplay/screenshot/diagram_scene_node_inheritance.png" width="300" />

#### Hitpoints 
Since, we are preparing our airplanes for the battlefield, we need to provide them with new specific attributes. 
To our class definition of Entity, we add a new member variable that memorizes the current hitpoints. 
Hitpoints (HP) are a measure for the hull integrity of an entity; the entity is destroyed as soon as the hitpoints reach or fall below zero. 
 In addition to the member variable, we provide member functions that allow the modification of the hitpoints. 
We do not provide direct write access, 
however, provide functions to reduce or increase hit points
- repair() :  increased  the hitpoints (the plane is repaired).
- damage()  : decrease the hitpoints (the plane is damaged
- destroy() : instantly destroys the entity

#### DataTables
In our game, there are already two different airplanes with different attributes. 
For this chapter, we introduce a third one to make the game more interesting. 
With an increasing amount of new aircraft types, attributes such as speed, hitpoints, used texture, or fire rate may vary strongly among them. 

#### DataTables.hpp
The following structure is defined
- AircraftData
- ProjectileData
- ProjectileData

#### TextNode
We would like to add some text on the display, for example, to show the hitpoints or ammunition of different entities. 
Since this text information is supposed to be shown next to the entity, it stands to reason to attach it to the corresponding scene node. 
We therefore, create a TextNode class which inherits SceneNode

#### Enemies 
Enemies are other instances of the Aircraft class. 
They appear at the top of the screen and move downwards, until they fly past the bottom of the screen. 
Most properties are the same for the player and enemies, 
so we only explain the new aircraft functionality.

#### Movement patterns 
By default, enemies fly downwards in a straight line. 
But it would be nice if different enemies moved differently, giving the feeling of a very basic artificial intelligence (AI). 
Thus, we introduce specific movement patterns. 
Such a pattern can be described as a sequence of directions to which the enemy airplane heads. 
A direction consists of an angle and a distance. 
Lets implement a zigzag movement pattern for the Raptor plane. 
First, it steers for 80 units in 45 degrees direction. 
Then, the angle changes to -45 degrees, and the plane traverses 160 units back. Last, it moves again 80 units in +45 degrees direction, until it arrives at its original x position.

coding in DataTables
data[Aircraft::Raptor].directions.push_back(Direction(+45.f, 80.f));

moving pattern <br/>
<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/07_Gameplay/screenshot/diagram_moving_pattern.png" width="300" />

#### Projectile
Finally, time to add what makes a game fun. Shooting down stuff is essential for our game. 
The code to interact with the World class is already defined, thanks to the actions in Player and to the existing Entity base class. 
All thats left is to define the projectiles themselves. 
We start with the Projectile class. 
We have normal machine gun bullets and homing missiles represented by the same class. 
This class inherits from the Entity class and is quite small, since it doesnt have anything special that differentiates it from other entities apart from collision tests, which we will talk about later.


#### Firing bullets and missiles 
So let's try and shoot some bullets in the game. 
We start with adding two new actions in the Player class: 
Fire and LaunchMissile. We define the default key bindings for these to be the Space bar and M keys.

#### Pickup
Picking up some goodies 
You want to give the player the feeling that he is progressing in the game. 
Usual for this game genre are power-ups that the enemies drop when they are killed. 
the player touches it, applies an effect to the player and disappears. 
Not much work with our current framework.

pickup types and benefits
- HealthRefill :  increase hitpoint
- MissileRefill : equip missiles
- FireSpread : shoot two bullets at once
- FireRate : faster interval which shoot new bullet



#### Collision detection and response 
Now that our world is full of entities, lets implement interactions between them. 
Most interactions occur in the form of a collision; two airplanes collide and explode, projectiles of the player's Gatling gun perforate an enemy, and a pickup is collected by the player, and so on. 

collision combination <br/>
<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/07_Gameplay/screenshot/diagram_collision_combination.png" width="300" />

#### Finding the collision pairs 
Given the SceneNode::collision() function, we can determine in each frame, which pairs of entities collide. 
We store the pointers to the entities in std::pair<SceneNode*, SceneNode*>, for which we have created the SceneNode::Pair typedef. 
All collision pairs are stored in a std::set instance. 
Basically, we need to compare every scene node with every other scene node to determine if a collision between the two occurs. 


#### Reacting to collisions 
by World::handleCollisions()
For every frame, we store all collided scene nodes in a set. 
Now we can iterate through this set of SceneNode* pairs, and dispatch on the categories of each collision partner. 


#### GameOverState
 you can accept the challenge to maneuver through a mission. 
Depending on your skill, you may reach the end of the level and become a pilot legend. 
Or you fall victim to the enemy fleet and die in a horrible plan crash.
Anyway, the player should be informed by the game about his fate. 
In most games, there are victory and defeat conditions.


#### Screen Display
players aircraft and enamys aircrafts fly on the desert  <br/>
<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/07_Gameplay/screenshot/screenshot_game.png" width="300" />

### control aircraft
- press Left Key, move left
- press Right Key, move right
- press Up Key, move up
- press Down Key, move down 
- press Space bar, fire bullet
- press m Key, lanch missile

### build code
g++ Source/*.cpp  -std=c++11 `pkg-config --cflags --libs sfml-all`  -I./Include  <br/>

### run code
Usage: ./a.out <br/>

### Reference <br/>
- https://www.sfml-dev.org/
- http://nedrilad.com/Tutorial/topic-32/SFML-Game-Development-214.html

