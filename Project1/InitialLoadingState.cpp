#include <sstream>
#include "InitialLoadingState.h"
#include "MainMenuState.h"
#include "DEFINITIONS.h"
#include <iostream>
#include "PixelCollision.h"


	InitialLoadingState::InitialLoadingState(GameDataRef data) : _data{ data }
	{

	}

	void InitialLoadingState::init()
	{
		_data->access.loadTexture("Initial Loading State Background",
			LOADING_SCENE_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->access.GetTexture("Initial Loading State Background"));
	}

	void InitialLoadingState::handleInput()
	{
		sf::Event event;
		while (_data->window.pollEvent(event)) //пока есть события, обрабатывать их
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
		}
	}

	void InitialLoadingState::update(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			_data->machine.addState(StateRef(new MainMenuState(_data)), true);
		}
	}

	void InitialLoadingState::draw(float dt)
	{
		_data->window.clear();
		_data->window.draw(_background);
		_data->window.display();
	}
