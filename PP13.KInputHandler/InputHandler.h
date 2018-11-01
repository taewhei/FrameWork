#pragma once
#include "SDL.h"

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
	~InputHandler() {}
private:
	const Uint8* m_keystates;
	InputHandler();
	
	static InputHandler* s_pInstance;
};
typedef InputHandler TheInputHandler;
