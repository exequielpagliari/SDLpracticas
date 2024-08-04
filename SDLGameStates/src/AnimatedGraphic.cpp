#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams* pParams, int animSpeed, int frames) : SDLGameObject(pParams), m_animSpeed(animSpeed) , m_numFrames(frames)
{
}

void AnimatedGraphic::draw()
{
	SDLGameObject::draw(); // use the base class drawing
}

void AnimatedGraphic::update()
{
	m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) %
		m_numFrames));
}

void AnimatedGraphic::clean()
{
	SDLGameObject::clean(); // use the base class drawing
}
