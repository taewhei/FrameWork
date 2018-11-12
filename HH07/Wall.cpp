#include "Wall.h"
#include "InputHandler.h"
#include "Game.h"

Wall::Wall(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Wall::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Wall::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));
	SDLGameObject::update();
}

void Wall::clean()
{
}
