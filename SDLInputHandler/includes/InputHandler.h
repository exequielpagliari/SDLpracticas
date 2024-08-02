#include "SDL.h"
#include <vector>
#include <iostream>
#include <Vector2D.h>


#ifndef __InputHandler__
#define __InputHandler__



class InputHandler
{
public:
	static InputHandler* Instance();
	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);
	const int m_joystickDeadZone = 10000;
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

#endif // ARCHIVO_SINGLETON