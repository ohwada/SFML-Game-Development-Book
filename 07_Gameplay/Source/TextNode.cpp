// TextNode
// We would like to add some text on the display, for example, to show the hitpoints or ammunition of different entities. 
// Since this text information is supposed to be shown next to the entity, it stands to reason to attach it to the corresponding scene node. 
// We therefore, create a TextNode class which inherits SceneNode

// https://github.com/SFML/SFML-Game-Development-Book/blob/master/07_Gameplay/Source/TextNode.cpp

#include <Book/TextNode.hpp>
#include <Book/Utility.hpp>

#include <SFML/Graphics/RenderTarget.hpp>

    
TextNode::TextNode(const FontHolder& fonts, const std::string& text)
{
	mText.setFont(fonts.get(Fonts::Main));
	mText.setCharacterSize(20);
	setString(text);
}

void TextNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mText, states);
}

void TextNode::setString(const std::string& text)
{
	mText.setString(text);
	centerOrigin(mText);
}