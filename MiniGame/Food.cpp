#include "Food.h"
#include "InputHandler.h"
#include"PlayState.h"
Food::Food(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	if (m_textureID == "Bomb")
	{
		m_velocity.setX(rand()%2+1);
		m_velocity.setY(rand()%2+1);
	}
	else if (m_textureID == "SuperBomb")
	{
		m_velocity.setX(rand() % 2 + 2);
		m_velocity.setY(rand() % 2 + 2);
	}
}
void Food::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Food::update()
{
	srand(SDL_GetTicks());
	if (m_textureID == "Bomb"|| m_textureID == "SuperBomb")
	{
		if (m_position.getX() <= 0 || m_position.getX() >= 640-m_width)
		{
			m_velocity.setX(m_velocity.getX()*-1);
		}
		if (m_position.getY() <= 0 || m_position.getY() >= 480-m_height)
		{
			m_velocity.setY(m_velocity.getY()*-1);
		}
	}
	if (IsCollision == true)
	{
	m_position.setX(rand() % 600 + 20);
	m_position.setY(rand() % 430 + 20);
	}

	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));
	SDLGameObject::update();
}

void Food::clean()
{
}




