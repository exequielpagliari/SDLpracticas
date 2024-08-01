#include <Game.h>
#include <iostream>





bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	// attempt to initialize SDL
		if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
		{
			std::cout << "SDL init success\n";
			// init the window
			m_pWindow = SDL_CreateWindow(title, xpos, ypos,
			width, height, flags);
			if(m_pWindow != 0) // window init success
			{
				std::cout << "window creation success\n";
				m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if(m_pRenderer != 0) // renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer,
				0,0,0,0);
			}
			else
			{
			std::cout << "renderer init fail\n";
			return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}
	std::cout << "init success\n";
	m_bRunning = true; // everything inited successfully,start the main loop


	
	if (!TextureManager::Instance()->load("assets/Base Character - Free/idle.png", "idle", m_pRenderer))
	{
		return false;
	}
	TextureManager::Instance()->load("assets/Free Pixel Art Forest/Background.png",
		"background", m_pRenderer);

	GameObject* m_player;
	GameObject* m_enemy1;
	GameObject* m_enemy2;
	GameObject* m_enemy3;
	m_player = new Player();
	m_enemy1 = new Enemy();
	m_enemy2 = new Enemy();
	m_enemy3 = new Enemy();
	m_player->load(100, 100, 128, 82, "idle");
	m_enemy1->load(300, 300, 80, 80, "idle");
	m_enemy2->load(150, 200, 80, 80, "idle");
	m_enemy3->load(400, 400, 80, 80, "idle");
	m_gameObjects.push_back(m_player);
	m_gameObjects.push_back(m_enemy1);
	m_gameObjects.push_back(m_enemy2);
	m_gameObjects.push_back(m_enemy3);


	

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color



	// loop through our objects and draw them
	for (std::vector<GameObject*>::size_type i = 0; i !=
		m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw(m_pRenderer);
	}
	


	SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::handleEvents()
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
			m_bRunning = false;
			break;
			default:
			break;
		}
	}
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::update()
{
	// loop through and update our objects
	for (std::vector<GameObject*>::size_type i = 0; i !=
		m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}


}

Game::Game()
{

}

Game::~Game()
{

}
