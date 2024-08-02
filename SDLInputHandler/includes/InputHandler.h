#include "SDL.h"
#include <vector>
#include <iostream>
#pragma once

class InputHandler
{
public:
	static InputHandler* Instance();
	
	void update();
	void clean();
	~InputHandler();
	void initialiseJoysticks();
	bool joysticksInitialised() {
		return m_bJoysticksInitialised;
	}
private:
	InputHandler() {};

	static InputHandler* s_pInstance;
	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksInitialised;
};
typedef InputHandler TheInputHandler;