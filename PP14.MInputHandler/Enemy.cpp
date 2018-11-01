#include "Enemy.h"
#include"InputHandler.h"


Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update()
{
	//m_position.setX(m_position.getX() + 1);
	//m_position.setY(m_position.getY() + 1);
	//
	//m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();
}

void Enemy::clean()
{
}
void Enemy::handleInput()
{
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(1);
	}
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;
}
