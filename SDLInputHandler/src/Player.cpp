#include <Player.h>
#include <InputHandler.h>

// Player class
Player::Player(const LoaderParams* pParams, bool arriba) :
	SDLGameObject(pParams)
{
}
void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
	if(TheInputHandler::Instance()-> joysticksInitialised() == true)
	{
		if (TheInputHandler::Instance()->getButtonState(0, 0))
		{
			m_velocity.setX(1);
		}

		if (TheInputHandler::Instance()->getButtonState(0, 1))
		{
			m_velocity.setX(-1);
		}

		if (TheInputHandler::Instance()->getButtonState(0, 2))
		{
			m_velocity.setY(1);
		}

		if (TheInputHandler::Instance()->getButtonState(0, 3))
		{
			m_velocity.setY(-1);
		}

	}
	else
	{

		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_velocity.setX(1);
		}

		if (TheInputHandler::Instance()->getMouseButtonState(RIGHT))
		{
			m_velocity.setX(1);
		}

		if (TheInputHandler::Instance()->getMouseButtonState(MIDDLE))
		{
			m_velocity.setX(1);
		}

		Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
		m_velocity = (*vec - m_position) / 100;
	}

	SDLGameObject::update();
}
void Player::clean()
{
}


void Player::handleInput()
{
	if (TheInputHandler::Instance()->joysticksInitialised())
	{
		if (TheInputHandler::Instance()->xvalue(0, 1) > 0 ||
			TheInputHandler::Instance()->xvalue(0, 1) < 0)
		{
			m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0,
				1));
		}
		if (TheInputHandler::Instance()->yvalue(0, 1) > 0 ||
			TheInputHandler::Instance()->yvalue(0, 1) < 0)
		{
			m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0,
				1));
		}
		if (TheInputHandler::Instance()->xvalue(0, 2) > 0 ||
			TheInputHandler::Instance()->xvalue(0, 2) < 0)
		{
			m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0,
				2));
		}
		if (TheInputHandler::Instance()->yvalue(0, 2) > 0 ||
			TheInputHandler::Instance()->yvalue(0, 2) < 0)
		{
			m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0,
				2));
		}
	}


}