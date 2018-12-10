#include"PlayState.h"
#include<iostream>
#include"GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include"GameOverState.h"
#include"InputHandler.h"
#include"PauseState.h"
#include"Body.h"
#include"SDLGameObject.h"
#include"Food.h"
const std::string PlayState::s_playID = "PLAY";
PlayState* PlayState::s_pInstance = 0;
void PlayState::update()
{	
	
	for (int i = 1; i < m_gameObjects.size(); i++)
	{
	if (checkCollision(
		dynamic_cast<SDLGameObject*>(m_gameObjects[i]),
		dynamic_cast<SDLGameObject*>(m_gameObjects[i-1])))
		{
		((Body*)m_gameObjects[i])->IsCollision = true;
		}
	else
		{
		((Body*)m_gameObjects[i])->IsCollision = false;
		}
	}

	
	for (int j = 0; j < food.size(); j++)
	{
		if (checkCollision(
			dynamic_cast<SDLGameObject*>(m_gameObjects[0]),
			dynamic_cast<SDLGameObject*>(food[j])))
		{
			((Food*)food[j])->IsCollision = true;
			if (((Food*)food[j])->m_textureID == "Food")
			{
				eat += 1;
			}
			else if (((Food*)food[j])->m_textureID == "Birus")
			{
				minuseat += 1;
			}
			
		}
		else
		{
			((Food*)food[j])->IsCollision = false;
		}
	}
	
	for (int i = 0; i < m_gameObjects.size() - 1; i++)
	{
		for (int j = i - 2; j > 0; j--)
		{
			if (checkCollision(
				dynamic_cast<SDLGameObject*>(m_gameObjects[i]),
				dynamic_cast<SDLGameObject*>(m_gameObjects[j])))
			{
				TheGame::Instance()->getStateMachine()->changeState(
					GameOverState::Instance());
				return;
			}
		}
		for (int z = i + 2; z < m_gameObjects.size() - 1; z++)
		{
			if (checkCollision(
				dynamic_cast<SDLGameObject*>(m_gameObjects[i]),
				dynamic_cast<SDLGameObject*>(m_gameObjects[z])))
			{
				TheGame::Instance()->getStateMachine()->changeState(
					GameOverState::Instance());
				return;
			}
		}
		for (int i = 1; i < m_gameObjects.size(); i++)
		{
			if (i == m_gameObjects.size() - 1)
			{
				((SDLGameObject*)m_gameObjects[i])->m_textureID = "Tail";
				if (eat >= 5)
				{

					m_gameObjects.push_back(new Body(new LoaderParams(((SDLGameObject*)m_gameObjects[i])->getPosition().getX(),
						((SDLGameObject*)m_gameObjects[i])->getPosition().getY(), 24, 24, "Tail")));
					eat = 0;
				}
				if (minuseat >= 5)
				{
					std::vector<GameObject*>::iterator iter = m_gameObjects.begin();
					std::vector<GameObject*>::iterator iterEnd = m_gameObjects.end();

					for (; iter != iterEnd; iter++)
					{
						if (*iter == m_gameObjects[i])
						{
							m_gameObjects.erase(iter);

							break;
						}
					}
					minuseat = 0;
				}
				
			}
			else
			{
				((SDLGameObject*)m_gameObjects[i])->m_textureID = "Body";
			}
		}

	}

	

	for (int i = 0; i < m_gameObjects.size(); i++) {
	
		if (((SDLGameObject*)m_gameObjects[i])->m_textureID == "Body"|| ((SDLGameObject*)m_gameObjects[i])->m_textureID == "Tail")
		{
			((Body*)m_gameObjects[i])->target = (SDLGameObject*)m_gameObjects[i-1];
		}
		m_gameObjects[i]->update();
	
	}
	for (int i = 0; i < food.size(); i++) {

		food[i]->update();
	}

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		for (int j = 0; j < food.size(); j++)
		{
			if (((Food*)food[j])->m_textureID == "Bomb"|| ((Food*)food[j])->m_textureID == "SuperBomb")
			{
				if (checkCollision(
					dynamic_cast<SDLGameObject*>(m_gameObjects[i]),
					dynamic_cast<SDLGameObject*>(food[j])))
				{
					TheGame::Instance()->getStateMachine()->changeState(
						GameOverState::Instance());
					return;
				}
			}

		}
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->changeState(
			PauseState::Instance());
		return;
	}
	if (1 == m_gameObjects.size())
	{
		TheGame::Instance()->getStateMachine()->changeState(
			GameOverState::Instance());
		return;
	}
}


void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
		
	}
	for (int i = 0; i < food.size(); i++) {

		food[i]->draw();
	}
}
bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/Head.png",
		"Head", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Body.png",
		"Body", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Tail.png",
		"Tail", TheGame::Instance()->getRenderer())) {
		return false;
	}
	

	if (!TheTextureManager::Instance()->load("assets/Food.png",
		"Food", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Birus.png",
		"Birus", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Bomb.png",
		"Bomb", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/SuperBomb.png",
		"SuperBomb", TheGame::Instance()->getRenderer())) {
		return false;
	}


	GameObject* player = new Player(
		new LoaderParams(400, 100, 24, 24, "Head"));
	GameObject* body = new Body(
		new LoaderParams(300, 100, 24, 24, "Body"));
	GameObject* body2 = new Body(
		new LoaderParams(200, 100, 24, 24, "Body"));
	GameObject* body3 = new Body(
		new LoaderParams(100, 100, 24, 24, "Tail"));
	
	m_gameObjects.push_back(player);
	m_gameObjects.push_back(body);
	m_gameObjects.push_back(body2);
	m_gameObjects.push_back(body3);
	
	
	for (int i = 0; i < 280; i++)
	{
		food.push_back(new Food(
			new LoaderParams(rand() % 600 + 20, rand() % 430 + 20, 16, 16, "Birus")));
	}

	for (int i=0; i < 300; i++)
	{
		food.push_back(new Food(
			new LoaderParams(rand() % 600 + 20, rand() % 430 + 20, 16, 16, "Food")));
	}

	food.push_back(new Food(new LoaderParams(30, 430, 32, 32, "Bomb")));
	food.push_back(new Food(new LoaderParams(450, 430, 32, 32, "SuperBomb")));
	food.push_back(new Food(new LoaderParams(200, 430, 32, 32, "Bomb")));
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();

	}
	for (int i = 0; i < food.size(); i++) {

		food[i]->clean();
	}
	m_gameObjects.clear();
	food.clear();

	TheTextureManager::Instance()->clearFromTextureMap("Head");
	TheTextureManager::Instance()->clearFromTextureMap("Body");
	TheTextureManager::Instance()->clearFromTextureMap("Tail");
	std::cout << "exiting PlayState\n";
	return true;
}
bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	//Calculate the sides of rect B
	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}


