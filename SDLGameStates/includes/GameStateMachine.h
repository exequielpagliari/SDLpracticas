#include "GameState.h"
#include <vector>
#pragma once
class GameStateMachine
{
public:
	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();
	std::vector<GameState*>& getGameStates() { return m_gameStates;}
	void update();
	void render();
private:
	std::vector<GameState*> m_gameStates;
};