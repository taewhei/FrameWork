#include "Player.h"
#include "InputHandler.h"
Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Player::update()
{
	
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));
	SDLGameObject::update();
}

void Player::clean()
{
}
void Player::handleInput()
{
	Vector2D* target = TheInputHandler::Instance()->getMousePosition();
	m_velocity = *target - m_position;
	m_velocity /= 10;
	angle = lookAt(*target);
}
double Player:: lookAt(Vector2D target)
{
	Vector2D directrion = m_position - target;
	angle = (atan2(directrion.getY(), directrion.getX()) - M_PI/2.F) * 180.f / M_PI;
	return angle;
}