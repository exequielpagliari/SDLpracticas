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
	if (Enemy::GetX() < 1)
		Enemy::derecha = true;
	else if (Enemy::GetX() > 600)
		Enemy::derecha = false;
	if (Enemy::derecha)
		m_x += 1;
	else
		m_x -= 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
}
void Enemy::clean()
{
}

int Enemy::GetY()
{
	return Enemy::m_y;
}

int Enemy::GetX()
{
	return Enemy::m_x;
}
