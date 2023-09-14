#include "MainMenuState.h"

MainMenuState::MainMenuState(std::shared_ptr<GameTools> tools)
	:m_gameTools(tools), m_developerName{GameResources::getInstance().createText("Michael Zargari", sf::Color::White, 1, 25)}
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
	m_gameTools->m_window.getWindow().draw(m_developerName);
	m_gameTools->m_window.getWindow().display();

}

void MainMenuState::initilaize()
{
	m_developerName.setPosition(sf::Vector2f{700, 750});
}

