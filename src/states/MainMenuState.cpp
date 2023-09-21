#include "states/MainMenuState.h"

MainMenuState::MainMenuState(std::shared_ptr<GameTools> tools)
	:m_gameTools(tools), m_currentOption{ 0 }, m_choose{ false }, character{Characters::Skeleton}
{
	initilaize();
}

void MainMenuState::processManeger()
{
	if (auto event = sf::Event{}; m_gameTools->m_window.getWindow().pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_gameTools->m_window.getWindow().close();
			break;

		case sf::Event::KeyPressed:
			handleKey(event.key.code);
		}
		

	}
}

void MainMenuState::update()
{
	if (m_choose)
		;// m_gameTools->m_gameStates.addState(std::make_unique<PlayState>(), true);
}

void MainMenuState::Draw()
{
	m_gameTools->m_window.getWindow().clear();
	drawMenu();
	m_gameTools->m_window.getWindow().display();
}

void MainMenuState::drawMenu()
{
	//draw options
	for (const auto op : m_menuOptions)
		m_gameTools->m_window.getWindow().draw(op);

	//draw developer
	m_gameTools->m_window.getWindow().draw(m_developerName);
	character.draw(m_gameTools->m_window.getWindow());
}

void MainMenuState::handleKey(sf::Keyboard::Key& key)
{
	switch (key)
	{
	case sf::Keyboard::Up:
		arrowPressed(-1);
		break;
	case sf::Keyboard::Down:
		arrowPressed(1);
		break;
	case sf::Keyboard::Enter: 
		m_choose = true; 
		break;
	default:;
	}
}

void MainMenuState::arrowPressed(const int& direction)
{
	m_menuOptions[m_currentOption].setOutlineThickness(0);
	m_menuOptions[m_currentOption].setFillColor(sf::Color::White);
	m_currentOption += (NUM_OF_OPTIONS + direction);
	m_currentOption %= NUM_OF_OPTIONS;
	m_menuOptions[m_currentOption].setFillColor(sf::Color::Yellow);
	m_menuOptions[m_currentOption].setOutlineColor(sf::Color::Magenta);
	m_menuOptions[m_currentOption].setOutlineThickness(2);
}

void MainMenuState::initilaize()
{
	m_developerName = GameResources::getInstance().createText("Michael Zargari", sf::Color::White, 3, 25, { 700.f, 750.f });

	//developer name position
	m_menuOptions[0] = GameResources::getInstance().createText("Play", sf::Color::Yellow, 2, 30, { 700.f, 100.f });
	m_menuOptions[1] = GameResources::getInstance().createText("Help", sf::Color::White, 2, 30, { 700.f, 200.f });
	m_menuOptions[2] = GameResources::getInstance().createText("Settings", sf::Color::White, 2, 30, { 700.f, 300.f });
	m_menuOptions[3] = GameResources::getInstance().createText("Exit", sf::Color::White, 2, 30, { 700.f, 400.f });

}

