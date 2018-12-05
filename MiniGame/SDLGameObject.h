#pragma once
#include"GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	~SDLGameObject() {}
	virtual void draw();
	virtual void update();
	virtual void clean();
	Vector2D& getPosition() { return m_position; }
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
	friend class PlayState;
	friend class Body;
protected:
	double angle = 0;
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

	std::string m_textureID;
};
