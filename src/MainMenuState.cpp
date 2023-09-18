#include "MainMenuState.h"

MainMenuState::MainMenuState(std::shared_ptr<GameTools> tools)
	:m_gameTools(tools)
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
		}
	}
}

void MainMenuState::update()
{
	;
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
}

void MainMenuState::initilaize()
{
	m_developerName = GameResources::getInstance().createText("Michael Zargari", sf::Color::White, 1, 25, { 700.f, 750.f });

	//developer name position
	m_menuOptions[0] = GameResources::getInstance().createText("Play", sf::Color::White, 1, 30, { 700.f, 100.f });
	m_menuOptions[1] = GameResources::getInstance().createText("Help", sf::Color::White, 1, 30, { 700.f, 200.f });
	m_menuOptions[2] = GameResources::getInstance().createText("Settings", sf::Color::White, 1, 30, { 700.f, 300.f });
	m_menuOptions[3] = GameResources::getInstance().createText("Exit", sf::Color::White, 1, 30, { 700.f, 400.f });

}
