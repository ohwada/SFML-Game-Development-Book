// DataTables
// In our game, there are already two different airplanes with different attributes. 
// For this chapter, we introduce a third one to make the game more interesting. 
// With an increasing amount of new aircraft types, attributes such as speed, hitpoints, used texture, or fire rate may vary strongly among them. 

// The following structure is defined in DataTables.hpp
// AircraftData, ProjectileData, ProjectileData

// Enemies
// Enemies are other instances of the Aircraft class. 
// Most properties are the same for the player and enemies, so we only explain the new aircraft functionality.

// Movement patterns 
// By default, enemies fly downwards in a straight line. 
// But it would be nice if different enemies moved differently, giving the feeling of a very basic artificial intelligence (AI). 
// Thus, we introduce specific movement patterns. 
// Such a pattern can be described as a sequence of directions to which the enemy airplane heads. 
// A direction consists of an angle and a distance. 
// Lets implement a zigzag movement pattern for the Raptor plane. 
// First, it steers for 80 units in 45 degrees direction. 
// Then, the angle changes to -45 degrees, and the plane traverses 160 units back. Last, it moves again 80 units in +45 degrees direction, until it arrives at its original x position.
// coding as below
//	data[Aircraft::Raptor].directions.push_back(Direction(+45.f, 80.f));

// Pickup
// HealthRefill :  Aircraft::repair(25)
// MissileRefill : Aircraft::collectMissiles(3)
// FireSpread : Aircraft::increaseSpread()
// FireRate : Aircraft::increaseFireRate()



// https://github.com/SFML/SFML-Game-Development-Book/blob/master/07_Gameplay/Source/DataTables.cpp

#include <Book/DataTables.hpp>
#include <Book/Aircraft.hpp>
#include <Book/Projectile.hpp>
#include <Book/Pickup.hpp>


// For std::bind() placeholders _1, _2, ...
using namespace std::placeholders;

std::vector<AircraftData> initializeAircraftData()
{
	std::vector<AircraftData> data(Aircraft::TypeCount);

	data[Aircraft::Eagle].hitpoints = 100;
	data[Aircraft::Eagle].speed = 200.f;
	data[Aircraft::Eagle].fireInterval = sf::seconds(1);
	data[Aircraft::Eagle].texture = Textures::Eagle;

	data[Aircraft::Raptor].hitpoints = 20;
	data[Aircraft::Raptor].speed = 80.f;
	data[Aircraft::Raptor].texture = Textures::Raptor;
	data[Aircraft::Raptor].directions.push_back(Direction(+45.f, 80.f));
	data[Aircraft::Raptor].directions.push_back(Direction(-45.f, 160.f));
	data[Aircraft::Raptor].directions.push_back(Direction(+45.f, 80.f));
	data[Aircraft::Raptor].fireInterval = sf::Time::Zero;

	data[Aircraft::Avenger].hitpoints = 40;
	data[Aircraft::Avenger].speed = 50.f;
	data[Aircraft::Avenger].texture = Textures::Avenger;
	data[Aircraft::Avenger].directions.push_back(Direction(+45.f,  50.f));
	data[Aircraft::Avenger].directions.push_back(Direction(  0.f,  50.f));
	data[Aircraft::Avenger].directions.push_back(Direction(-45.f, 100.f));
	data[Aircraft::Avenger].directions.push_back(Direction(  0.f,  50.f));
	data[Aircraft::Avenger].directions.push_back(Direction(+45.f,  50.f));
	data[Aircraft::Avenger].fireInterval = sf::seconds(2);

	return data;
}

std::vector<ProjectileData> initializeProjectileData()
{
	std::vector<ProjectileData> data(Projectile::TypeCount);

	data[Projectile::AlliedBullet].damage = 10;
	data[Projectile::AlliedBullet].speed = 300.f;
	data[Projectile::AlliedBullet].texture = Textures::Bullet;

	data[Projectile::EnemyBullet].damage = 10;
	data[Projectile::EnemyBullet].speed = 300.f;
	data[Projectile::EnemyBullet].texture = Textures::Bullet;

	data[Projectile::Missile].damage = 200;
	data[Projectile::Missile].speed = 150.f;
	data[Projectile::Missile].texture = Textures::Missile;

	return data;
}

std::vector<PickupData> initializePickupData()
{
	std::vector<PickupData> data(Pickup::TypeCount);
	
	data[Pickup::HealthRefill].texture = Textures::HealthRefill;
	data[Pickup::HealthRefill].action = [] (Aircraft& a) { a.repair(25); };
	
	data[Pickup::MissileRefill].texture = Textures::MissileRefill;
	data[Pickup::MissileRefill].action = std::bind(&Aircraft::collectMissiles, _1, 3);
	
	data[Pickup::FireSpread].texture = Textures::FireSpread;
	data[Pickup::FireSpread].action = std::bind(&Aircraft::increaseSpread, _1);
	
	data[Pickup::FireRate].texture = Textures::FireRate;
	data[Pickup::FireRate].action = std::bind(&Aircraft::increaseFireRate, _1);

	return data;
}
