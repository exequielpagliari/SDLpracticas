#include <SDLGameObject.h>



// Enemy class
class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams, bool derecha = true);
	virtual void draw();
	virtual void update();
	virtual void clean();
	int GetY();
	int GetX();
	bool derecha = true;
};