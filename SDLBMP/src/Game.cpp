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
				255,255,255,255);
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

    SDL_Surface* pTempSurface = SDL_LoadBMP("assets/bmp_24.bmp"); 
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface); 
	SDL_FreeSurface(pTempSurface);
	SDL_QueryTexture(m_pTexture, NULL, NULL,
	  &m_sourceRectangle.w, &m_sourceRectangle.h);
	  m_destinationRectangle.x = m_sourceRectangle.x = 0; 
	  m_destinationRectangle.y = m_sourceRectangle.y = 0; 
	  m_destinationRectangle.w = m_sourceRectangle.w;
	  m_destinationRectangle.h = m_sourceRectangle.h;


	SDL_Surface* pTempSurfaceAnim =
		  SDL_LoadBMP("assets/animacion.bmp");
	m_pTextureAnimacion = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurfaceAnim);
	SDL_FreeSurface(pTempSurfaceAnim);
	SDL_QueryTexture(m_pTextureAnimacion, NULL, NULL,
		&m_sourceRectangleanimacion.w, &m_sourceRectangleanimacion.h);
	m_sourceRectangleanimacion.x = 0;
	m_sourceRectangleanimacion.y = 0;
	m_destinationRectangleanimacion.w = m_sourceRectangleanimacion.w = 80;
	m_destinationRectangleanimacion.h = m_sourceRectangleanimacion.h = 80;
	m_destinationRectangleanimacion.x = 320;
	m_destinationRectangleanimacion.y = 160;
	

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle,  &m_destinationRectangle);
	if (int(((SDL_GetTicks() / 1000) % 2)))
	{
		SDL_RenderCopy(m_pRenderer, m_pTextureAnimacion, &m_sourceRectangleanimacion, &m_destinationRectangleanimacion);
	}
	else
	{
		SDL_RenderCopyEx(m_pRenderer, m_pTextureAnimacion,
			&m_sourceRectangleanimacion, &m_destinationRectangleanimacion,
			0, 0, SDL_FLIP_HORIZONTAL); // pass in the horizontal flip
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
	m_sourceRectangleanimacion.x = 80 * int(((SDL_GetTicks() / 100) % 4));
	m_destinationRectangle.x = 80 * int(((SDL_GetTicks() / 32) % 20));

}

Game::Game()
{

}

Game::~Game()
{

}
