#include <SDL_image.h>
#include <iostream>
#include <string>
#include <map>
#pragma once



class TextureManager
{
public:
	static TextureManager* Instance();
	~TextureManager();
	// draw
	void draw(std::string id, int x, int y, int width, int
		height, SDL_Renderer* pRenderer, SDL_RendererFlip flip =
		SDL_FLIP_NONE);
	// drawframe
	void drawFrame(std::string id, int x, int y, int width, int
		height, int currentRow, int currentFrame, SDL_Renderer*
		pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	

	bool load(std::string fileName, std::string id,
		SDL_Renderer* pRenderer);

	std::map<std::string, SDL_Texture*> m_textureMap;

	void TextureManager::clearFromTextureMap(std::string id)
	{
		m_textureMap.erase(id);
	}

private:
	static TextureManager* s_pInstance;
	TextureManager() {}

};
typedef TextureManager TheTextureManager;


	