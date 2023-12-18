#pragma once

#include "states/State.h"
#include "objects/Player.h"
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
	void handleKey(sf::Keyboard::Key&);
	void arrowPressed(const int&); 
protected:
	void initilaize()override;

private:
	std::shared_ptr<GameTools> m_gameTools;
	sf::Text m_developerName;
	std::array<sf::Text, 4> m_menuOptions;
	int m_currentOption;
	bool m_choose;
	Player m_optionSelector;

	
};
