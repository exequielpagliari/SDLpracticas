#include <SDLGameObject.h>
#include <InputHandler.h>



class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* pParams, bool arriba = true);
	virtual void draw();
	virtual void update();
	virtual void clean();
	bool arriba = true;
private:
	void handleInput();
};