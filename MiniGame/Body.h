#pragma once
#include"SDLGameObject.h"


class Body : public SDLGameObject
{
private:
	void handleInput();

public:
	Body(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	double lookAt(Vector2D target);
	SDLGameObject* target;
	Vector2D getTarget();
	bool IsCollision = false;
};

