#pragma once

#include "Window.h"
#include "assets/StateMachine.h";

#include <array>
#include <vector>
#include <string>

struct GameTools
{
	//members
	StateMachine m_gameStates;
	Window m_window;
	//MediaPlayer m_media;
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
