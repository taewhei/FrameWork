#include "GameState.h"
#include"SDLGameObject.h"

class PlayState : public GameState
{
public:
	PlayState() {};
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }
	static PlayState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new PlayState();
			return s_pInstance;
		}
		return s_pInstance;
	}
	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
		std::vector<GameObject*> m_gameObjects;
		std::vector<GameObject*> food;
		int eat;
		int minuseat;
		int score;
private:
	static const std::string s_playID;
	static PlayState* s_pInstance;


}; typedef PlayState PlayState;
