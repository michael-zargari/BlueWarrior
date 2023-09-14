#pragma once
#include "Window.h"

struct GameTools
{
	//members
	//StateMachine m_gameStates;
	Window m_window;
};


class Game
{
public:
	Game();
	~Game() = default;
	
	void runGame();
private:
	std::shared_ptr<GameTools> m_gameTools;
};
