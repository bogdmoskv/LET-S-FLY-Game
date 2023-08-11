#include <sstream>
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include "GameState.h"

#include <iostream>


	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{

	}

	void MainMenuState::init()
	{
		this->_data->access.loadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->access.loadTexture("Game Title", GAME_TITLE_FILEPATH);
		this->_data->access.loadTexture("Play Button", PLAY_BUTTON_FILEPATH);

		_background.setTexture(this->_data->access.GetTexture("Main Menu Background"));
		_title.setTexture(this->_data->access.GetTexture("Game Title"));
		_playButton.setTexture(this->_data->access.GetTexture("Play Button"));

		_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height / 2);
		_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2));
	}

	void MainMenuState::handleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.isSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.addState(StateRef(new GameState(_data)), true);
			}
		}
	}

	void MainMenuState::update(float dt)
	{

	}

	void MainMenuState::draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_playButton);

		this->_data->window.display();
	}
