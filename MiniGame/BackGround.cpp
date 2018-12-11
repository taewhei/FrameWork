#include"BackGround.h"

BackGround::BackGround(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	
	

}
void BackGround::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void BackGround::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));
	SDLGameObject::update();
}

void BackGround::clean()
{
	
}
void BackGround::collision(GameObject* obj)
{

}