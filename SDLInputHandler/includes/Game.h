
#include <TextureManager.h>
#include <Player.h>
#include <Enemy.h>
#include <Background.h>
#include <vector>


#pragma once


#ifndef __Game__
#define __Game__
class Game
{
	
	int m_currentFrame;
	std::vector<GameObject*> m_gameObjects;
public:
	static Game* Instance();
	~Game();
	bool init(const char* title, int xpos, int ypos, int width,
		int height, int flags);
	void render();
	void update();
	void handleEvents();
	void clean();
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	void quit();




	bool running() { return m_bRunning; }
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	Game();

	
	static Game* s_pInstance;
	bool m_bRunning;
};	
// create the typedef
typedef Game TheGame;


#endif /* defined(__Game__) */