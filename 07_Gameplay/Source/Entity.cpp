// Entity
// As a quick reminder, the SceneNode base class was inherited by the Entity class. 
// Entities are the central part of this chapter. 
// Its all about the interaction between entities of different kinds. 
// Before starting to implement all those interactions, it is reasonable to think about crucial properties our entities need to have.

// Hitpoints 
// Since, we are preparing our airplanes for the battlefield, we need to provide them with new specific attributes. 
// To our class definition of Entity, we add a new member variable that memorizes the current hitpoints. 
// Hitpoints (HP) are a measure for the hull integrity of an entity; the entity is destroyed as soon as the hitpoints reach or fall below zero. 
// In addition to the member variable, we provide member functions that allow the modification of the hitpoints. 
// We do not provide direct write access, 
// however, provide functions to reduce or increase hit points
// repair() :  increased  the hitpoints (the plane is repaired).
//damage()  : decrease the hitpoints (the plane is damaged
// destroy() : instantly destroys the entity


// https://github.com/SFML/SFML-Game-Development-Book/blob/master/07_Gameplay/Source/Entity.cpp

#include <Book/Entity.hpp>

#include <cassert>


Entity::Entity(int hitpoints)
: mVelocity()
, mHitpoints(hitpoints)
{
}

void Entity::setVelocity(sf::Vector2f velocity)
{
	mVelocity = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}

sf::Vector2f Entity::getVelocity() const
{
	return mVelocity;
}

void Entity::accelerate(sf::Vector2f velocity)
{
	mVelocity += velocity;
}

void Entity::accelerate(float vx, float vy)
{
	mVelocity.x += vx;
	mVelocity.y += vy;
}

int Entity::getHitpoints() const
{
	return mHitpoints;
}

void Entity::repair(int points)
{
	assert(points > 0);

	mHitpoints += points;
}

void Entity::damage(int points)
{
	assert(points > 0);

	mHitpoints -= points;
}

void Entity::destroy()
{
	mHitpoints = 0;
}

bool Entity::isDestroyed() const
{
	return mHitpoints <= 0;
}

void Entity::updateCurrent(sf::Time dt, CommandQueue&)
{	
	move(mVelocity * dt.asSeconds());
}
