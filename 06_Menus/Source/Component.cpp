// https://github.com/SFML/SFML-Game-Development-Book/blob/master/06_Menus/Source/Component.cpp

#include <Book/Component.hpp>

namespace GUI
{

Component::Component()
: mIsSelected(false)
, mIsActive(false)
{
}

Component::~Component()
{
}

bool Component::isSelected() const
{
	return mIsSelected;
}

void Component::select()
{
	mIsSelected = true;
}

void Component::deselect()
{
	mIsSelected = false;
}

bool Component::isActive() const
{
	return mIsActive;
}

void Component::activate()
{
	mIsActive = true;
}

void Component::deactivate()
{
	mIsActive = false;
}

}