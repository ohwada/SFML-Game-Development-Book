// Particle
// We define a class for particles that stores the position, color, and the time untilthe particle disappears. 
// The Particle::Type data type is used to differ between smoke and propellant effects.

// https://github.com/SFML/SFML-Game-Development-Book/blob/master/08_Graphics/Include/Book/Particle.hpp

#ifndef BOOK_PARTICLE_HPP
#define BOOK_PARTICLE_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Color.hpp>


struct Particle 
{
	enum Type
	{
		Propellant,
		Smoke,
		ParticleCount
	};

	sf::Vector2f	position;
	sf::Color		color;
	sf::Time		lifetime;
};

#endif // BOOK_PARTICLE_HPP
