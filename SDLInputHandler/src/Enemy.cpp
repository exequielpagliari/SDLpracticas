#include <Enemy.h>






Enemy::Enemy(const LoaderParams* pParams, bool derecha) : SDLGameObject(pParams)
{
}

void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update()
{
	if (m_position.getX() < 1)
		Enemy::derecha = true;
	else if (m_position.getX() > 600)
		Enemy::derecha = false;
	if (Enemy::derecha)
		m_acceleration.setX(0.1f);
	else
		m_acceleration.setX(-.1f);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
	if (m_velocity.getX() > -.05f || m_velocity.getX() < .05f)
		SDLGameObject::update();
	
	
}
void Enemy::clean()
{
}



