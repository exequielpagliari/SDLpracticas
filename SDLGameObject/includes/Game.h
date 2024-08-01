
#include <TextureManager.h>
#include <Player.h>
#include <Enemy.h>
#include <vector>



#ifndef __Game__
#define __Game__
class Game
{
	int m_currentFrame;
	std::vector<GameObject*> m_gameObjects;
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