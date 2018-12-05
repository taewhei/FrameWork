#include "Body.h"
#include "InputHandler.h"
#include"PlayState.h"
Body::Body(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}
void Body::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Body::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));
	SDLGameObject::update();
}

void Body::clean()
{
}
void Body::handleInput()
{
	Vector2D vector = target->m_position;
	if (IsCollision == false)
	{
	m_velocity = vector - m_position;
	m_velocity /= 10;
	}
	else
	{
		m_velocity.setX(0);
		m_velocity.setY(0);
	}
	angle = lookAt(target->m_position);
}
double Body::lookAt(Vector2D target)
{
	Vector2D directrion = m_position - target;
	angle = (atan2(directrion.getY(), directrion.getX()) - M_PI / 2.F) * 180.f / M_PI;
	return angle;
}





