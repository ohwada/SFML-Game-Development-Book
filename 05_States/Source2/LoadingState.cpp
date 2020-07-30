// LoadingState
// display Progress Bar
// after 10 seconds, transition to GameState

// Progress Bar 
// We have sf::Text to display our Loading Resources string, two sf::RectangleShape objects for the progress bar background and fill, and a ParallelTask object. 

// https://github.com/SFML/SFML-Game-Development-Book/blob/master/05_States/Source/LoadingState.cpp

#include <Book/LoadingState.hpp>
#include <Book/Utility.hpp>
#include <Book/ResourceHolder.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

#include <iostream>


LoadingState::LoadingState(StateStack& stack, Context context)
: State(stack, context)
{
	std::cout << "LoadingState" << std::endl;

	sf::RenderWindow& window = *getContext().window;
	sf::Font& font = context.fonts->get(Fonts::Main);
	sf::Vector2f viewSize = window.getView().getSize();

	mLoadingText.setFont(font);
	mLoadingText.setString("Loading Resources");
	centerOrigin(mLoadingText);
	mLoadingText.setPosition(viewSize.x / 2.f, viewSize.y / 2.f + 50.f);

	mProgressBarBackground.setFillColor(sf::Color::White);
	mProgressBarBackground.setSize(sf::Vector2f(viewSize.x - 20, 10));
	mProgressBarBackground.setPosition(10, mLoadingText.getPosition().y + 40);

	mProgressBar.setFillColor(sf::Color(100,100,100));
	mProgressBar.setSize(sf::Vector2f(200, 10));
	mProgressBar.setPosition(10, mLoadingText.getPosition().y + 40);

	setCompletion(0.f);

	mLoadingTask.execute();

	std::cout << "LoadingState end" << std::endl;
}

void LoadingState::draw()
{
	std::cout << "draw" << std::endl;

	sf::RenderWindow& window = *getContext().window;

	window.setView(window.getDefaultView());

	window.draw(mLoadingText);
	window.draw(mProgressBarBackground);
	window.draw(mProgressBar);

	std::cout << "draw end" << std::endl;
}

bool LoadingState::update(sf::Time)
{
	std::cout << "update" << std::endl;

	// Update the progress bar from the remote task or finish it
	if (mLoadingTask.isFinished())
	{
		requestStackPop();
		requestStackPush(States::Game);
	}
	else
	{
		setCompletion(mLoadingTask.getCompletion());
	}

	std::cout << "update end" << std::endl;
	return true;
}

bool LoadingState::handleEvent(const sf::Event& event)
{
	std::cout << "handleEvent" << std::endl;
	return true;
}

void LoadingState::setCompletion(float percent)
{
	std::cout << "setCompletion" << std::endl;
	if (percent > 1.f) // clamp
		percent = 1.f;

	mProgressBar.setSize(sf::Vector2f(mProgressBarBackground.getSize().x * percent, mProgressBar.getSize().y));
	std::cout << "setCompletion end" << std::endl;
}
