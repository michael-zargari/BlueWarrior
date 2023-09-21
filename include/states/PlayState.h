#pragma once

#include "State.h"
#include "Game.h"

class PlayState :public State
{
public:
	PlayState(std::shared_ptr<GameTools> gameTools);
	~PlayState() = default;

private:
	std::shared_ptr<GameTools> m_gameTools;
	
};
