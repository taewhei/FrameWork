#include "Food.h"
#include "InputHandler.h"
#include"PlayState.h"
Food::Food(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}
void Food::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Food::update()
{

if (IsCollision == true)
{
	m_position.setX(rand() %200+100);
	m_position.setY(rand() % 200 + 100);
}

	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));
	SDLGameObject::update();
}

void Food::clean()
{
}




