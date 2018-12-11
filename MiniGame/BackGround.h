#pragma once

#include "SDLGameObject.h"


class BackGround : public SDLGameObject
{
private:

public:
	BackGround(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void collision(GameObject* obj);


};
