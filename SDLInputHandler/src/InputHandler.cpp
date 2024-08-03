#include "InputHandler.h"
#include <Game.h>



InputHandler* InputHandler::s_pInstance = nullptr;



void InputHandler::initialiseJoysticks()
{
	if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
	{
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	}
	if (SDL_NumJoysticks() > 0)
	{
		for (int i = 0; i < SDL_NumJoysticks(); i++)
		{
			SDL_Joystick* joy = SDL_JoystickOpen(i);
			if (SDL_JoystickOpen(i) != 0)
			{
				m_joysticks.push_back(joy);
				m_joystickValues.push_back(std::make_pair(new
					Vector2D(0, 0), new Vector2D(0, 0))); // add our pair
				std::vector<bool> tempButtons;
				for (int j = 0; j < SDL_JoystickNumButtons(joy); j++)
				{
					tempButtons.push_back(false);
				}
				m_buttonStates.push_back(tempButtons);
			}
			else
			{
				std::cout << SDL_GetError();
			}
		}
		SDL_JoystickEventState(SDL_ENABLE);
		m_bJoysticksInitialised = true;
		std::cout << "Initialised " << m_joysticks.size() << "joystick(s)";

	}
	else
	{
		m_bJoysticksInitialised = false;
	}
}

void InputHandler::clean()
{
	
	if (m_bJoysticksInitialised)
	{
		for (int i = 0; i < SDL_NumJoysticks(); i++)
		{
			SDL_JoystickClose(m_joysticks[i]);
		}
	}
	
}


InputHandler* InputHandler::Instance()
{
	
		if (s_pInstance == nullptr)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	
}



void InputHandler::update()
{
	m_keystate = SDL_GetKeyboardState(0);
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{


		switch (event.type)
		{
		case  SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_JOYAXISMOTION:
			onJoystickAxisMove(event);
			break;
		case SDL_JOYBUTTONDOWN:
			onJoystickButtonDown(event);
			break;
		case SDL_JOYBUTTONUP:
			onJoystickButtonUp(event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			onMouseButtomDown(event);
			break;
		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp(event);
			break;
		case SDL_MOUSEMOTION:
			onMouseMove(event);
			break;
		case SDL_KEYUP:
			onKeyUp();
			break;
		case SDL_KEYDOWN:
			onKeyDown();
			break;
		default:
			break;
		}


	}
}


InputHandler::~InputHandler()
{
	// delete anything we created dynamically
	delete m_mousePosition;

	// clear our arrays
	m_joystickValues.clear();
	m_joysticks.clear();
	m_buttonStates.clear();
	m_mouseButtonStates.clear();
}


int InputHandler::xvalue(int joy, int stick)
{
	if (m_joystickValues.size() > 0)
	{
		if (stick == 1)
		{
			return (int)m_joystickValues[joy].first->getX();
		}
		else if (stick == 2)
		{
			return (int)m_joystickValues[joy].second->getX();
		}
	}
	return 0;
}
int InputHandler::yvalue(int joy, int stick)
{
	if (m_joystickValues.size() > 0)
	{
		if (stick == 1)
		{
			return (int)m_joystickValues[joy].first->getY();
		}
		else if (stick == 2)
		{
			return (int)m_joystickValues[joy].second->getY();
		}
	}
	return 0;
}

bool InputHandler::isKeyDown(SDL_Scancode key) const
{
	if (m_keystate != 0)
	{
		if (m_keystate[key] == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	return false;
}

void InputHandler::onKeyDown()
{
	m_keystate = SDL_GetKeyboardState(0);
}

void InputHandler::onKeyUp()
{
	m_keystate = SDL_GetKeyboardState(0);
}

void InputHandler::onMouseMove(SDL_Event& event)
{
	m_mousePosition->setX((float)event.motion.x);
	m_mousePosition->setY((float)event.motion.y);
}

void InputHandler::onMouseButtomDown(SDL_Event& event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[LEFT] = false;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = false;
	}
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] = false;
	}
}

void InputHandler::onMouseButtonUp(SDL_Event& event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[LEFT] = true;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = true;
	}
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] = true;
	}
}

void InputHandler::onJoystickAxisMove(SDL_Event& event)
{
	int whichOne = event.jaxis.which;
	// left stick move left or right
	if (event.jaxis.axis == 0)
	{
		if (event.jaxis.value > m_joystickDeadZone)
		{
			m_joystickValues[whichOne].first->setX(1);
		}
		else if (event.jaxis.value < -m_joystickDeadZone)
		{
			m_joystickValues[whichOne].first->setX(-1);
		}
		else
		{
			m_joystickValues[whichOne].first->setX(0);
		}
	}
	// left stick move up or down
	if (event.jaxis.axis == 1)
	{
		if (event.jaxis.value > m_joystickDeadZone)
		{
			m_joystickValues[whichOne].first->setY(1);
		}
		else if (event.jaxis.value < -m_joystickDeadZone)
		{
			m_joystickValues[whichOne].first->setY(-1);
		}
		else
		{
			m_joystickValues[whichOne].first->setY(0);
		}
	}
	// right stick move left or right
	if (event.jaxis.axis == 3)
	{
		if (event.jaxis.value > m_joystickDeadZone)
		{
			m_joystickValues[whichOne].second->setX(1);
		}
		else if (event.jaxis.value < -m_joystickDeadZone)
		{
			m_joystickValues[whichOne].second->setX(-1);
		}
		else
		{
			m_joystickValues[whichOne].second->setX(0);
		}
	}
	// right stick move up or down
	if (event.jaxis.axis == 4)
	{
		if (event.jaxis.value > m_joystickDeadZone)
		{
			m_joystickValues[whichOne].second->setY(1);
		}
		else if (event.jaxis.value < -m_joystickDeadZone)
		{
			m_joystickValues[whichOne].second->setY(-1);
		}
		else
		{
			m_joystickValues[whichOne].second->setY(0);
		}
	}
}

void InputHandler::onJoystickButtonDown(SDL_Event& event)
{
	int whichOne = event.jaxis.which;
	m_buttonStates[whichOne][event.jbutton.button] = true;

}

void InputHandler::onJoystickButtonUp(SDL_Event& event)
{
	int whichOne = event.jaxis.which;
	m_buttonStates[whichOne][event.jbutton.button] = false;
}


