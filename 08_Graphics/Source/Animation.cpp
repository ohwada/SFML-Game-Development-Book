//Animation
// Animated sprites
// So far our aircraft have just disappeared when you shot them down. Thats not satisfying. 
// When you destroy something like an aircraft, you expect a huge explosion, dont you?
// An animation consists of several frames, and we represent these frames as separate rectangles inside one larger texture, similar towhat we now do with entities. 
// Do not confuse animation frames with the game loopframes—the former represents just a state of an animation, which usually lasts formany game loop iterations


// the sprite sheet
// How does it work? 
// As timeelapses, we move the texture rect from one frame to the other, until the animationis finished.
// We do not define the animation class as a scene node but only as a drawableand a transformable object. 
// It can then be used by whatever scene node we want,which gives a little more flexibility when and where we can use it


// https://github.com/SFML/SFML-Game-Development-Book/blob/master/08_Graphics/Source/Animation.cpp

#include <Book/Animation.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>


Animation::Animation()
: mSprite()
, mFrameSize()
, mNumFrames(0)
, mCurrentFrame(0)
, mDuration(sf::Time::Zero)
, mElapsedTime(sf::Time::Zero)
, mRepeat(false)
{
}

Animation::Animation(const sf::Texture& texture)
: mSprite(texture)
, mFrameSize()
, mNumFrames(0)
, mCurrentFrame(0)
, mDuration(sf::Time::Zero)
, mElapsedTime(sf::Time::Zero)
, mRepeat(false)
{
}

void Animation::setTexture(const sf::Texture& texture)
{
	mSprite.setTexture(texture);
}

const sf::Texture* Animation::getTexture() const
{
	return mSprite.getTexture();
}

void Animation::setFrameSize(sf::Vector2i frameSize)
{
	mFrameSize = frameSize;
}

sf::Vector2i Animation::getFrameSize() const
{
	return mFrameSize;
}

void Animation::setNumFrames(std::size_t numFrames)
{
	mNumFrames = numFrames;
}

std::size_t Animation::getNumFrames() const
{
	return mNumFrames;
}

void Animation::setDuration(sf::Time duration)
{
	mDuration = duration;
}

sf::Time Animation::getDuration() const
{
	return mDuration;
}

void Animation::setRepeating(bool flag)
{
	mRepeat = flag;
}

bool Animation::isRepeating() const
{
	return mRepeat;
}

void Animation::restart()
{
	mCurrentFrame = 0;
}

bool Animation::isFinished() const
{
	return mCurrentFrame >= mNumFrames;
}

sf::FloatRect Animation::getLocalBounds() const
{
	return sf::FloatRect(getOrigin(), static_cast<sf::Vector2f>(getFrameSize()));
}

sf::FloatRect Animation::getGlobalBounds() const
{
	return getTransform().transformRect(getLocalBounds());
}

void Animation::update(sf::Time dt)
{
	sf::Time timePerFrame = mDuration / static_cast<float>(mNumFrames);
	mElapsedTime += dt;

	sf::Vector2i textureBounds(mSprite.getTexture()->getSize());
	sf::IntRect textureRect = mSprite.getTextureRect();

	if (mCurrentFrame == 0)
		textureRect = sf::IntRect(0, 0, mFrameSize.x, mFrameSize.y);
	
	// While we have a frame to process
	while (mElapsedTime >= timePerFrame && (mCurrentFrame <= mNumFrames || mRepeat))
	{
		// Move the texture rect left
		textureRect.left += textureRect.width;

		// If we reach the end of the texture
		if (textureRect.left + textureRect.width > textureBounds.x)
		{
			// Move it down one line
			textureRect.left = 0;
			textureRect.top += textureRect.height;
		}

		// And progress to next frame
		mElapsedTime -= timePerFrame;
		if (mRepeat)
		{
			mCurrentFrame = (mCurrentFrame + 1) % mNumFrames;

			if (mCurrentFrame == 0)
				textureRect = sf::IntRect(0, 0, mFrameSize.x, mFrameSize.y);
		}
		else
		{
			mCurrentFrame++;
		}
	}

	mSprite.setTextureRect(textureRect);
}

void Animation::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(mSprite, states);
}
