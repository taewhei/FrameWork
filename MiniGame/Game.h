#pragma once
#include<vector>
#include "SDL.h"
#include"GameObject.h"
#include"Player.h"
#include"Enemy.h"
#include"GameStateMachine.h"

class Game
{
public:
	//Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();

	static Game* Instance();
	GameStateMachine* m_pGameStateMachine;

	void handleEvents();
	void clean();
	void update();
	bool running() { return m_bRunning; }
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	void quit();
	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	int m_CurrentFrame;
	//GameObject m_go;
	//Player m_player;
	Game();
	// create the s_pInstance member variable
	static Game* s_pInstance;
	
	std::vector<GameObject*> m_gameObjects;
	//GameObject* m_go;
	//GameObject* m_player;
	//GameObject* m_enemy;

};typedef Game TheGame;// create the typedef
