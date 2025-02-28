#include "SDL.h"
#include <vector>
#include <iostream>
#include <Vector2D.h>


#ifndef __InputHandler__
#define __InputHandler__

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

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
	bool joysticksInitialised()  {
		return m_bJoysticksInitialised;
	}
	bool getButtonState(int joy, int buttonNumber)
	{
		return m_buttonStates[joy][buttonNumber];
	}

	bool getMouseButtonState(int buttonNumber)
	{
		return m_mouseButtonStates[buttonNumber];
	}

	Vector2D* getMousePosition()
	{
		return m_mousePosition;
	}

	void reset();

	// keyboard events
	bool isKeyDown(SDL_Scancode key) const;
private:
	InputHandler() : 
		m_bJoysticksInitialised(false), m_mousePosition(new Vector2D(0, 0)), m_keystate(0) {
		for (int i = 0; i < 3; i++)
		{
			m_mouseButtonStates.push_back(false);
		}
	};
	Vector2D* m_mousePosition;
	static InputHandler* s_pInstance;
	std::vector<SDL_Joystick*> m_joysticks;
	std::vector<std::vector<bool>> m_buttonStates;
	std::vector<bool> m_mouseButtonStates;
	bool m_bJoysticksInitialised{};
	const Uint8* m_keystate;

	//private functions to handle differents events types

	// handle keyboards event
	void onKeyDown();
	void onKeyUp();

	// handle mouse event
	void onMouseMove(SDL_Event& event);
	void onMouseButtomDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);
	
	// handle joystick events
	void onJoystickAxisMove(SDL_Event& event);
	void onJoystickButtonDown(SDL_Event& event);
	void onJoystickButtonUp(SDL_Event& event);



}; 
typedef InputHandler TheInputHandler;

#endif // ARCHIVO_SINGLETON