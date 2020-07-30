// EmitterNode
// Because particles should be emitted in the places where the missiles are located,it stands to reason that emitters should be attached to missiles. 
// Once more, ourscene graph comes in very handy: we can create a new scene node Emitter-Node for emitters and attach it to the Projectile node of the missile.
// EmitterNode is rather simple

// The pointer mParticleSystem points to the ParticleNode into which theEmitterNode emits particles. Initially, it is nullptr. 
// In the update function, weemit particles if the particle system has already been initialized. 
// Otherwise, weneed to find the system corresponding to the emitter. "Corresponding" means bothuse the same particle type, for example, Particle::Smoke. 
// We send a com-mand through the scene graph to find the right particle system. It sets the membervariable mParticleSystem to the found ParticleNode:

// emitParticles
// After the emitter has been linked to a particle system, the method to emit particlesbecomes interesting. 
// We set an emission rate and try to achieve it as closely aspossible. Since this is not usually equal to our logic frame rate, the amount of emit-ted particles per frame differs. 
// To cope with that problem, we again use accumu-lators.
 // We emit particles as long as the emission interval still fits into the current frame. 
// The remaining time is stored in mAccumulatedTime and is carried over to the next frame


// https://github.com/SFML/SFML-Game-Development-Book/blob/master/08_Graphics/Source/EmitterNode.cpp

#include <Book/EmitterNode.hpp>
#include <Book/ParticleNode.hpp>
#include <Book/CommandQueue.hpp>
#include <Book/Command.hpp>


EmitterNode::EmitterNode(Particle::Type type)
: SceneNode()
, mAccumulatedTime(sf::Time::Zero)
, mType(type)
, mParticleSystem(nullptr)
{
}

void EmitterNode::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	if (mParticleSystem)
	{
		emitParticles(dt);
	}
	else
	{
		// Find particle node with the same type as emitter node
		auto finder = [this] (ParticleNode& container, sf::Time)
		{
			if (container.getParticleType() == mType)
				mParticleSystem = &container;
		};

		Command command;
		command.category = Category::ParticleSystem;
		command.action = derivedAction<ParticleNode>(finder);

		commands.push(command);
	}
}

void EmitterNode::emitParticles(sf::Time dt)
{
	const float emissionRate = 30.f;
	const sf::Time interval = sf::seconds(1.f) / emissionRate;

	mAccumulatedTime += dt;

	while (mAccumulatedTime > interval)
	{
		mAccumulatedTime -= interval;
		mParticleSystem->addParticle(getWorldPosition());
	}
}
