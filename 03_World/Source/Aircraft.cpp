
// Aircraft 
// Using the example of the aircraft, we need to define a concrete entity class. 
// We derive it from Entity. Since we have different airplanes in our game, it would be nice to have a data type that can store them. An enumeration comes in handy;
// we call it Type and make it a member of the Aircraft class. Therefore, we can now refer to it as Aircraft::Type, which is quite expressive when we see it in the code. 

// original : https://github.com/SFML/SFML-Game-Development-Book/blob/master/03_World/Source/Aircraft.cpp

#include <Book/Aircraft.hpp>
#include <Book/ResourceHolder.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>


Textures::ID toTextureID(Aircraft::Type type)
{
	switch (type)
	{
		case Aircraft::Eagle:
			return Textures::Eagle;

		case Aircraft::Raptor:
			return Textures::Raptor;
	}
	return Textures::Eagle;
}

Aircraft::Aircraft(Type type, const TextureHolder& textures)
: mType(type)
, mSprite(textures.get(toTextureID(type)))
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}
