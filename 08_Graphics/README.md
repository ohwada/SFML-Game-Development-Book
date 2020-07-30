08_Graphic - SFML-Game-Development-Book
===============

### Chapter 8. Every Pixel Counts – Adding Visual Effects
A very important part of games are the graphics. 
Be it cutting-edge 3D scenes in the newest real-time strategy game or the nostalgic atmosphere of a pixel-art indie title, graphics determine to a big extent how the player feels. 
In this chapter, we are going to look behind the scenes of rendering. 
We are going to cover various techniques that are used in modern games to create graphical effects of different kinds. 

- Texture atlases and how different objects can be stored in one texture 
- Texture mapping and vertex arrays 
- Particle systems to create effects such as fire or smoke 
- Animations that show an object in motion 
- Render textures as an alternative to render windows 
- Shaders to give the whole scene a distinct

#### ParticleNode
Particle Systems
Visual effects like fire, rain and smoke are expressed as combination of randomly changing small particles.
A particle system is a component that manages the behavior of many particles to form the desired effect.
A ParticleNode class , which can be inserted into the scene and which acts as a particle system. 

#### EmitterNode
Because particles should be emitted in the places where the missiles are located,it stands to reason that emitters should be attached to missiles. 
Once more, ourscene graph comes in very handy: we can create a new scene node Emitter-Node for emitters and attach it to the Projectile node of the missile.

#### Embedding particles in the world
World::buildScene():
The particle system is attached to a layer node directly under the scene graph's root. 
Because we want particles and projectiles to appear below the airplanes, we split the existing scene layer Air into two layers LowerAir and UpperAir. 

#### Animation
So far our aircraft have just disappeared when you shot them down. Thats not satisfying. 
When you destroy something like an aircraft, you expect a huge explosion, dont you?
An animation consists of several frames, and we represent these frames as separate rectangles inside one larger texture, similar towhat we now do with entities. 
Do not confuse animation frames with the game loopframes—the former represents just a state of an animation, which usually lasts formany game loop iterations

visual effect of the explosion <br/>
 animate images in order in the sprite sheet as below<br/>
<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/08_Graphic/Media/Textures/Explosion.png" width="300" />

#### BloomEffect
Bloom is an effect which tries to mimic a defect in our eyes and cameras
When really strong light enters our eyes, it bleeds out over otherparts that are not actually lit by the light. 
This is a visual artifact that actually doesnot exist in reality.
We are achieving the bloom effect inmultiple shader passes. 
The output of a shader program can only be used as inputin the next pass, which limits the possible operations per pass. 
Our bloom shaderwill consist of multiple steps; each step is implemented in its own GLSL program


#### PostEffect
Well, the effect has to be applied to the whole screen
That is why we define a specific PostEffect class in order to make this a bit easier.

This is an abstract class with some helper functions. 
apply() is the virtual functionwe have to define our effect code in. 
The isSupported() function checks ifthe graphics card supports post effects. 

#### Screen Display
fly players aircraft and enamys aircrafts on the jungle <br/>
<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/08_Graphic/screenshot/screenshot_game.png" width="300" />

#### Visual Effects
visual effects are displayed in the title screen as below <br/>
<image src="https://raw.githubusercontent.com/ohwada/SFML-Game-Development-Book/master/08_Graphic/Media/Textures/TitleScreen.png" width="300" />

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
- http://nedrilad.com/Tutorial/topic-32/SFML-Game-Development-260.html

