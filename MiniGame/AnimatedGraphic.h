#pragma once
#include"SDLGameObject.h"
class AnimatedGraphic:public SDLGameObject
{
public:
		AnimatedGraphic(const LoaderParams* pParams,int aimSpeed);
		virtual void draw();
		virtual void update();
		virtual void clean() {};
		int m_animSpeed;
		int m_numFrames=2;
};