#include "objects/MovingObjects.h"

MovingObjects::MovingObjects(const Characters& type, const AnimationData& data, int hp)
	:m_animationTime{ sf::seconds(0.2) }, m_elapsed{}/*, m_type{ type }*/, m_currentAction{ Action::Idle }, m_index{ 0 }
	, m_animationData{ data }, m_character{ getAnimation(type) }
{
	setSprite();
}

void MovingObjects::updateAnimation()
{
	m_elapsed += m_animationClock.restart();

	if (m_elapsed >= m_animationTime)
	{
		m_elapsed -= m_animationTime;
		++m_index;
		m_index %= m_animationData.m_data.find(m_currentAction)->second.size();
		setSprite();
	}
}

void MovingObjects::setSprite()
{
	m_character[static_cast<int>(m_currentAction)].setTextureRect(m_animationData.m_data.find(m_currentAction)->second[m_index]);
}

void MovingObjects::setAction(const Action& newAction, const float& speed)
{
	m_currentAction = newAction;
	m_animationTime = sf::seconds(speed);
	m_index = 0;
}

void MovingObjects::draw(sf::RenderWindow& window)
{
	window.draw(m_character[static_cast<int>(m_currentAction)]);
}

void MovingObjects::changePosition(const sf::Vector2f& newPos)
{
	for (auto& i : m_character)
		i.setPosition(newPos);
}
