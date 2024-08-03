#include <Background.h>

// Background class
Background::Background(const LoaderParams* pParams) :
	SDLGameObject(pParams)
{
}
void Background::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Background::update()
{
	


	SDLGameObject::update();
}
void Background::clean()
{

}





