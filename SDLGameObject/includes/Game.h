#include "SDL.h"
#include "TextureManager.h"
#include <Player.h>



#ifndef __Game__
#define __Game__
class Game
{
	int m_currentFrame;
	GameObject m_go;
	Player m_player;
public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int width,
		int height, int flags);
	void render();
	void update();
	void handleEvents();
	void clean();


	bool running() { return m_bRunning; }
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;



	bool m_bRunning;
};



#endif /* defined(__Game__) */