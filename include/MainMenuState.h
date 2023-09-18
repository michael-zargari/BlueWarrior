#pragma once

#include "State.h"
#include "Game.h"

class MainMenuState : public State
{
public:
	MainMenuState(std::shared_ptr<GameTools> tools);
	~MainMenuState() = default;

	void processManeger() override;
	void update() override;
	void Draw() override;
	//virtual void Resume() = 0;
	void drawMenu();
protected:
	void initilaize()override;

private:
	std::shared_ptr<GameTools> m_gameTools;
	sf::Text m_developerName;
	std::array<sf::Text, 4> m_menuOptions;
};