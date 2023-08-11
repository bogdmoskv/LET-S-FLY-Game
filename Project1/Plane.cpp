#include "Plane.h"
#include "PixelCollision.h"

	Plane::Plane(GameDataRef data) : _data{ data }
	{
		CreateTextureAndBitmask(_planeTexture, PLANE_FRAME1_FILEPATH);
		_planeSprite.setTexture(_planeTexture);
		_planeSprite.setPosition((_data->window.getSize().x / 4) - (_planeSprite.getGlobalBounds().width / 2), (_data->window.getSize().y / 4) - (_planeSprite.getGlobalBounds().height / 2));
		_planeState = PLANE_STATE_STILL;
		_rotation = 0;
	}

	void Plane::draw()
	{
		_data->window.draw(_planeSprite);
	}

	void Plane::update(float dt)
	{
		if (PLANE_STATE_FALLING == _planeState)
		{
			_planeSprite.move(0, GRAVITY * dt);

			_rotation += ROTATION_SPEED * dt;

			if (_rotation > 3.0f)
			{
				_rotation = 3.0f;
			}

			_planeSprite.setRotation(_rotation);
		}
		else if (PLANE_STATE_FLYING == _planeState)
		{
			_planeSprite.move(0, -FLYING_SPEED * dt);

			_rotation += (-ROTATION_SPEED) * dt;

			if (_rotation < -10.0f)
			{
				_rotation = -10.0f;
			}

			_planeSprite.setRotation(_rotation);
		}

		if (_movementClock.getElapsedTime().asSeconds() > FLYING_DURATION)
		{
			_movementClock.restart();
			_planeState = PLANE_STATE_FALLING;
		}
	}


	void Plane::tap()
	{
		_movementClock.restart();
		_planeState = PLANE_STATE_FLYING;
	}

	sf::Sprite &Plane::GetSprite()
	{
		return _planeSprite;
	}
