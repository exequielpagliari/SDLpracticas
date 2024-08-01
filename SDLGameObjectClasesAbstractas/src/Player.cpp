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
	if (Player::GetY() < 1)
		Player::arriba = true;
	else if (Player::GetY() > 300)
		Player::arriba = false;
	if (Player::arriba)
		m_y += 1;
	else
		m_y -= 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
}
void Player::clean()
{
}

int Player::GetY()
{
	return m_y;
}

int Player::GetX()
{
	return m_x;
}
