#pragma once
#include "GameState.h"
#include "Platform.h"
#include <stack>

class GameState;

class GameStateManager
{
private:
	std::stack<GameState *> states;
	Platform *platform;
public:
	GameStateManager();
	~GameStateManager();
	void GameLoop();
	void SetState(GameState *state);
	void RealaseState();
};

