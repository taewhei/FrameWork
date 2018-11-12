#pragma once
#include"SDLGameObject.h"

class Bullet : public SDLGameObject
{
private:


public:
	Bullet(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

};

