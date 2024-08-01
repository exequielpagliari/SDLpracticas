#include <Player.h>

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
	if (m_position.getY() < 1)
		Player::arriba = true;
	else if (m_position.getY() > 300)
		Player::arriba = false;
	if (Player::arriba)
		m_velocity.setY(1);
	else
		m_velocity.setY(-1);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));

	
	SDLGameObject::update();
}
void Player::clean()
{
}


