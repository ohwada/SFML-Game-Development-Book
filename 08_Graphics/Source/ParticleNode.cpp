// ParticleNode
// Particle Systems
// Visual effects like fire, rain and smoke are expressed as combination of randomly changing small particles.
// A particle system is a component that manages the behavior of many particles toform the desired effect.
// A ParticleNode class , which can be inserted into the scene and which acts as a particle system. 

// method
// getCategory() returns Cat-egory::ParticleSystem, a separate category. 
// getParticleType() returnsthe particle type (smoke or propellant) which is stored in mType.
// A new addition is addParticle(), which looks up the data table and inserts aparticle into the system:


//In the update method, we first remove all particles of which the lifetime has expired.Since all particles have the same initial lifetime, older particles are stored at thebeginning of the container. 
// Therefore, it is enough to remove the front element ofmParticles as long as its lifetime is smaller or equal to zero (this is also thereason why we employed std::deque). 
// In the middle part of the function, we de-crease the lifetime of each particle by the current frame time. 
// Finally, every timethe particle container is modified, we enable a flag to express that the render geo-metry must be recomputed:

// The rendering part
// The mVertexArray member is declared mut-able, since it is not a part of the objects logical state. 
// This allows optimizations:we only rebuild the vertex array if something has changed, and directly beforedrawing (instead of after each update). 
// This way, if the particle system is updatedmultiple times in a row before being drawn, we do not needlessly compute the ver-tices each time.
// After checking whether we need to recompute the vertices, we set the sf::RenderStates texture to our particle texture and draw the vertex array:


// https://github.com/SFML/SFML-Game-Development-Book/blob/master/08_Graphics/Source/ParticleNode.cpp

#include <Book/ParticleNode.hpp>
#include <Book/Foreach.hpp>
#include <Book/DataTables.hpp>
#include <Book/ResourceHolder.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <algorithm>


namespace
{
	const std::vector<ParticleData> Table = initializeParticleData();
}

ParticleNode::ParticleNode(Particle::Type type, const TextureHolder& textures)
: SceneNode()
, mParticles()
, mTexture(textures.get(Textures::Particle))
, mType(type)
, mVertexArray(sf::Quads)
, mNeedsVertexUpdate(true)
{
}

void ParticleNode::addParticle(sf::Vector2f position)
{
	Particle particle;
	particle.position = position;
	particle.color = Table[mType].color;
	particle.lifetime = Table[mType].lifetime;

	mParticles.push_back(particle);
}

Particle::Type ParticleNode::getParticleType() const
{
	return mType;
}

unsigned int ParticleNode::getCategory() const
{
	return Category::ParticleSystem;	
}

void ParticleNode::updateCurrent(sf::Time dt, CommandQueue&)
{
	// Remove expired particles at beginning
	while (!mParticles.empty() && mParticles.front().lifetime <= sf::Time::Zero)
		mParticles.pop_front();

	// Decrease lifetime of existing particles
	FOREACH(Particle& particle, mParticles)
		particle.lifetime -= dt;

	mNeedsVertexUpdate = true;
}

void ParticleNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (mNeedsVertexUpdate)
	{
		computeVertices();
		mNeedsVertexUpdate = false;
	}

	// Apply particle texture
	states.texture = &mTexture;
	
	// Draw vertices
	target.draw(mVertexArray, states);
}

void ParticleNode::addVertex(float worldX, float worldY, float texCoordX, float texCoordY, const sf::Color& color) const
{
	sf::Vertex vertex;
	vertex.position = sf::Vector2f(worldX, worldY);
	vertex.texCoords = sf::Vector2f(texCoordX, texCoordY);
	vertex.color = color;

	mVertexArray.append(vertex);
}

void ParticleNode::computeVertices() const
{
	sf::Vector2f size(mTexture.getSize());
	sf::Vector2f half = size / 2.f;

	// Refill vertex array
	mVertexArray.clear();
	FOREACH(const Particle& particle, mParticles)
	{
		sf::Vector2f pos = particle.position;
		sf::Color color = particle.color;

		float ratio = particle.lifetime.asSeconds() / Table[mType].lifetime.asSeconds();
		color.a = static_cast<sf::Uint8>(255 * std::max(ratio, 0.f));

		addVertex(pos.x - half.x, pos.y - half.y, 0.f,    0.f,    color);
		addVertex(pos.x + half.x, pos.y - half.y, size.x, 0.f,    color);
		addVertex(pos.x + half.x, pos.y + half.y, size.x, size.y, color);
		addVertex(pos.x - half.x, pos.y + half.y, 0.f,    size.y, color);
	}
}
