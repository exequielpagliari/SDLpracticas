#include <SDLGameObject.h>

class AnimatedGraphic: public SDLGameObject
{
public:
	AnimatedGraphic(const LoaderParams * pParams, int animSpeed, int frames);
	virtual void draw();
	virtual void update();
	virtual void clean();

	bool derecha = true;
private:
	int m_numFrames;
	int	m_animSpeed;
};