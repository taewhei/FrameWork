#include "Game.h"
#include "TextureManager.h"
#include <iostream>
#include <SDL_image.h>
#include "InputHandler.h"
#include "Bullet.h"
#include "Wall.h"
#include"CollisionManager.h"
#include"SDLGameObject.h"
Game* Game::s_pInstance = 0;

Game* Game::Instance()
{
	if (s_pInstance == 0)
	{
		s_pInstance = new Game();
		return s_pInstance;
	}
	return s_pInstance;
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		m_bRunning = true;
		TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer);
		TheTextureManager::Instance()->load("Assets/Bullet.png", "Bullet",m_pRenderer);
		TheTextureManager::Instance()->load("Assets/Brick.png", "Brick1", m_pRenderer);
		TheTextureManager::Instance()->load("Assets/Brick2.png", "Brick2", m_pRenderer);
		m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
		m_gameObjects.push_back(new Wall(new LoaderParams(450, 100, 30, 30, "Brick1")));
		SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
	}
	else {
		return false; // sdl could not initialize
	}
	return true;

}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear to the draw colour
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	SDL_RenderPresent(m_pRenderer); // draw to the screen

}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	TheInputHandler::Instance()->clean();
	SDL_Quit();
}
void Game::handleEvents()
{
	TheInputHandler::Instance()->update();

	/*SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}*/

}
void Game::update()
{
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
		if (((SDLGameObject*)m_gameObjects[i])->m_textureID == "Brick1"|| ((SDLGameObject*)m_gameObjects[i])->m_textureID == "Brick2")
		{
			for (std::vector<GameObject*>::size_type j = i ; j != m_gameObjects.size(); j++)
			{
				if (((SDLGameObject*)m_gameObjects[j])->m_textureID == "Bullet")
				{
					if (TheCollisionManager::Instance()->RecColl(m_gameObjects[i], m_gameObjects[j]))
					{
						std::vector<GameObject*>::iterator iter = m_gameObjects.begin();
						std::vector<GameObject*>::iterator iterEnd = m_gameObjects.end();
						
						for (; iter != iterEnd; iter++)
						{
							if (*iter == m_gameObjects[j])
							{
								m_gameObjects.erase(iter);
								j--;
								((SDLGameObject*)m_gameObjects[i])->m_textureID = "Brick2";
								break;
							}
						}
					}
				}
			}

		}
	
	}

}

Game::Game()
{

}
void Game::quit()
{
	m_bRunning = false;
}