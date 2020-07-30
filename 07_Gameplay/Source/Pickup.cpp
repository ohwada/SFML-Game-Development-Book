// Pickup
// Picking up some goodies 
// You want to give the player the feeling that he is progressing in the game. 
// Usual for this game genre are power-ups that the enemies drop when they are killed. 
// the player touches it, applies an effect to the player and disappears. 
// Not much work with our current framework.

// https://github.com/SFML/SFML-Game-Development-Book/blob/master/07_Gameplay/Source/Pickup.cpp

#include <Book/Pickup.hpp>
#include <Book/DataTables.hpp>
#include <Book/Category.hpp>
#include <Book/CommandQueue.hpp>
#include <Book/Utility.hpp>
#include <Book/ResourceHolder.hpp>

#include <SFML/Graphics/RenderTarget.hpp>


namespace
{
	const std::vector<PickupData> Table = initializePickupData();
}

Pickup::Pickup(Type type, const TextureHolder& textures)
: Entity(1)
, mType(type)
, mSprite(textures.get(Table[type].texture))
{
	centerOrigin(mSprite);
}

unsigned int Pickup::getCategory() const
{
	return Category::Pickup;
}

sf::FloatRect Pickup::getBoundingRect() const
{
	return getWorldTransform().transformRect(mSprite.getGlobalBounds());
}

void Pickup::apply(Aircraft& player) const
{
	Table[mType].action(player);
}

void Pickup::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

