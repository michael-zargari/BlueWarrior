#pragma once

#include "State.h"
#include "Game.h"
#include "objects/Player.h"
#include "objects/StaticObject.h"

class PlayState :public State
{
public:
	PlayState(std::shared_ptr<GameTools> gameTools);
	~PlayState() = default;
	
	//state methods
	void processManeger() override;
	void update() override;
	void Draw() override;

protected:
	void initilaize() override;
private:
	std::shared_ptr<GameTools> m_gameTools;
	Player m_warrior;
	StaticObject tile;
};
