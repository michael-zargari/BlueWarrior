#include "states/PlayState.h"

PlayState::PlayState(std::shared_ptr<GameTools> gameTools)
	:m_gameTools{gameTools}
{
	initilaize();
}

void PlayState::processManeger()
{
	if (auto event = sf::Event{}; m_gameTools->m_window.getWindow().pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_gameTools->m_window.getWindow().close();
			break;

			case sf::Event::KeyPressed:
				if(event.KeyPressed == sf::Keyboard::Escape)
					m_gameTools->m_window.getWindow().close();
				break;

		}


	}
}

void PlayState::update()
{
	m_warrior.update();
}

void PlayState::Draw()
{
	m_gameTools->m_window.getWindow().clear();
	m_warrior.draw(this->m_gameTools->m_window.getWindow());
	m_gameTools->m_window.getWindow().display();
	
}

void PlayState::initilaize()
{
	m_warrior.changePosition({ 700, 400 });
}
