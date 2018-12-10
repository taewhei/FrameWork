#include "Game.h"
#include "TextureManager.h"
#include <iostream>
#include <SDL_image.h>
#include "InputHandler.h"
#include"MenuState.h"
#include"PlayState.h"
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

		SDL_SetRenderDrawColor(m_pRenderer, 255, 200, 200, 255);
		m_pGameStateMachine = new GameStateMachine();
		m_pGameStateMachine->changeState(MenuState::Instance());

	}
	else {
		return false; // sdl could not initialize
	}
	return true;

}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	m_pGameStateMachine->render();
	SDL_RenderPresent(m_pRenderer);


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
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(PlayState::Instance());
	}
}

void Game::update()
{
	m_pGameStateMachine->update();
}

Game::Game()
{

}
void Game::quit()
{
	m_bRunning = false;
}