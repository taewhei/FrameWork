#pragma once
#include "SDL.h"
#include<vector>
#include"Vector2D.h"

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	void update();
	void clean();  // 디바이스 관련 초기화된 부분을 clear 
	
	bool isKeyDown(SDL_Scancode key);
	int isKeyOneDown(SDL_Scancode key);
	~InputHandler() {}
						
	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition();
	int push = 0;
private:
	const Uint8* m_keystates;
	static InputHandler* s_pInstance;
	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;

	//SDL_Event event;

	void onKeyDown();
	void onKeyUp();
	InputHandler();
	void onMouseMove(SDL_Event event);
	void onMouseButtonDown(SDL_Event event);
	void onMouseButtonUp(SDL_Event event);
	int pushsec;
};
typedef InputHandler TheInputHandler;
