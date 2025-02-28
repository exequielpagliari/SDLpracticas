#include <Game.h>
#include <iostream>
#include <InputHandler.h>
#include <MenuState.h>
#include <PlayState.h>



Game* Game::s_pInstance = nullptr;



Game* Game::Instance() {
	if (s_pInstance == nullptr) {
		s_pInstance = new Game();
	}
	return s_pInstance;
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	TheInputHandler::Instance()->initialiseJoysticks();
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
	m_pGameStateMachine = new GameStateMachine();

	m_pGameStateMachine->changeState(new MenuState());

	
	TextureManager::Instance()->load("assets/Base Character - Free/idle.png", "idle", m_pRenderer);
	
	TextureManager::Instance()->load("assets/Free Pixel Art Forest/Background.png", "background", m_pRenderer);


	m_gameObjects.push_back(new Background(new LoaderParams(0, -200, 650, 700,
		"background")));
	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 80, 80,
		"idle")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 80, 80,
		"idle")));

	

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color
	/*
	
	// loop through our objects and draw them
	for (std::vector<GameObject*>::size_type i = 0; i !=
		m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	*/
	
	m_pGameStateMachine->render();

	SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(new PlayState());
	}
}

void Game::clean()
{
	TheInputHandler::Instance()->clean();
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::quit()
{
	m_bRunning = false;
}

void Game::update()
{

	m_pGameStateMachine->update();

	/*
	// loop through and update our objects
	for (std::vector<GameObject*>::size_type i = 0; i !=
		m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	*/

}

Game::Game() : m_pWindow(0),
m_pRenderer(0),
m_bRunning(false),
m_pGameStateMachine(0)
{}

Game::~Game()
{
	// we must clean up after ourselves to prevent memory leaks
	m_pRenderer = 0;
	m_pWindow = 0;
}
