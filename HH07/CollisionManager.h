#pragma once
#include"SDLGameObject.h"
class CollisionManager
{
public:

	bool RecColl(GameObject* object1, GameObject* object2);
	static CollisionManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new CollisionManager();
			return s_pInstance;
		}
		return s_pInstance;
	}
private:
	static CollisionManager* s_pInstance;
};
typedef CollisionManager TheCollisionManager;
