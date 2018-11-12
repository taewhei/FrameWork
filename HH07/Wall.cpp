#pragma once
#include"SDLGameObject.h"

class Wall : public SDLGameObject
{
private:


public:
	Wall(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};

