#pragma once
#include"SDLGameObject.h"


class Food : public SDLGameObject
{
private:

public:
	Food(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	bool IsCollision;
};

