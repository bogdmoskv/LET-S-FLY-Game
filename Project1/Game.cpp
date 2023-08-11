#include "Game.h"
#include "InitialLoadingState.h"
#include "DEFINITIONS.h"


	Game::Game(int width, int height, std::string title)
	{

		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar); 
		
		sf::Image icon;
		icon.loadFromFile(ICON_FILEPATH);
		_data->window.setIcon(32, 32, icon.getPixelsPtr());
		
		_data->machine.addState(StateRef(new InitialLoadingState(this->_data)));

		this->run();
	}

	void Game::run()
	{
		float newTime, frameTime, interpolation;

		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen())
		{
			this->_data->machine.processStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->_data->machine.GetActiveState()->handleInput();
				this->_data->machine.GetActiveState()->update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->_data->machine.GetActiveState()->draw(interpolation);
		}
	}
