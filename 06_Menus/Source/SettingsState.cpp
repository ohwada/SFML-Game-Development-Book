// SettingsState
// We implement a new state; the SettingsState which you access through a button on the menu. 
// What is the purpose for the SettingsState in our example? 
// Currently we have the key bindings inside there. 
// Everything we need has already been implemented with the GUI, so we only have to define the actual state.


// We have put all the binding buttons and the associated labels in a static array, and associate to them the action they bind for. 
// This means we don't have to duplicate a lot of callbacks, which you may have notice are missing. Instead, we have marked the button as one that toggles. 
// We also have an updateLabels() function call. 
// Its a helper function to make sure the labels are writing out the correct name for the key.


// If a button is pressed, then it will be activated, and since its a button that toggles, it will stay active until we tell it to deactivate. 
// So we loop through the array of buttons and check if anyone of them is active. 
// If they are, then we are currently binding a key. 
// When we get a key released event, then we change that binding on the player to the new key with the specified action before we deactivate the button again. 
// After the loop, we update the labels, such that they have the correct name for everything. If no button is active, then we are not currently trying to bind a key, and should pass the event to the GUI container instead.

// display Buttons  "Move Left", "Move Right", "Move Up", "Move Down", "Back"


// https://github.com/SFML/SFML-Game-Development-Book/blob/master/06_Menus/Source/SettingsState.cpp

#include <Book/SettingsState.hpp>
#include <Book/Utility.hpp>
#include <Book/ResourceHolder.hpp>

#include <SFML/Graphics/RenderWindow.hpp>


SettingsState::SettingsState(StateStack& stack, Context context)
: State(stack, context)
, mGUIContainer()
{
	mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));
	
	// Build key binding buttons and labels
	addButtonLabel(Player::MoveLeft,  150.f, "Move Left", context);
	addButtonLabel(Player::MoveRight, 200.f, "Move Right", context);
	addButtonLabel(Player::MoveUp,    250.f, "Move Up", context);
	addButtonLabel(Player::MoveDown,  300.f, "Move Down", context);

	updateLabels();

	auto backButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	backButton->setPosition(80.f, 375.f);
	backButton->setText("Back");
	backButton->setCallback(std::bind(&SettingsState::requestStackPop, this));

	mGUIContainer.pack(backButton);
}

void SettingsState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.draw(mBackgroundSprite);
	window.draw(mGUIContainer);
}

bool SettingsState::update(sf::Time)
{
	return true;
}

bool SettingsState::handleEvent(const sf::Event& event)
{
	bool isKeyBinding = false;
	
	// Iterate through all key binding buttons to see if they are being pressed, waiting for the user to enter a key
	for (std::size_t action = 0; action < Player::ActionCount; ++action)
	{
		if (mBindingButtons[action]->isActive())
		{
			isKeyBinding = true;
			if (event.type == sf::Event::KeyReleased)
			{
				getContext().player->assignKey(static_cast<Player::Action>(action), event.key.code);
				mBindingButtons[action]->deactivate();
			}
			break;
		}
	}

	// If pressed button changed key bindings, update labels; otherwise consider other buttons in container
	if (isKeyBinding)
		updateLabels();
	else
		mGUIContainer.handleEvent(event);

	return false;
}

void SettingsState::updateLabels()
{
	Player& player = *getContext().player;

	for (std::size_t i = 0; i < Player::ActionCount; ++i)
	{
		sf::Keyboard::Key key = player.getAssignedKey(static_cast<Player::Action>(i));
		mBindingLabels[i]->setText(toString(key));
	}
}

void SettingsState::addButtonLabel(Player::Action action, float y, const std::string& text, Context context)
{
	mBindingButtons[action] = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	mBindingButtons[action]->setPosition(80.f, y);
	mBindingButtons[action]->setText(text);
	mBindingButtons[action]->setToggle(true);

	mBindingLabels[action] = std::make_shared<GUI::Label>("", *context.fonts);
	mBindingLabels[action]->setPosition(300.f, y + 15.f);

	mGUIContainer.pack(mBindingButtons[action]);
	mGUIContainer.pack(mBindingLabels[action]);
}
