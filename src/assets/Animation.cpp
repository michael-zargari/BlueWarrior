#include "Animation.h"
#include "GameResources.h"


Animation::Animation(const Characters& type, const AnimationData& data)
	:m_animationTime{ sf::seconds(0.2) }, m_elapsed{}, m_type{ type }, m_currentAction{ Action::TakeHit }, m_index{0}
	, m_characterData{ data }, m_Animation{ getAnimation(type) }
{
	setSprite();
}

void Animation::update(sf::Time& delta)
{
	m_elapsed += delta;
	if (m_elapsed >= m_animationTime)
	{
		m_elapsed -= m_animationTime;
		++m_index;
		m_index %= m_characterData.m_data.find(m_currentAction)->second.size();
		setSprite();
	}
}

void Animation::setSprite()
{
	m_Animation[static_cast<int>(m_currentAction)].setTextureRect(m_characterData.m_data.find(m_currentAction)->second[m_index]);
}

void Animation::setAction(/*Action newAction,*/ float speed)
{
	// m_currentAction = newAction;
	m_animationTime = sf::seconds(speed);
	m_index = 0;
}

void Animation::draw(sf::RenderWindow& window)
{
	window.draw(m_Animation[static_cast<int>(m_currentAction)]);
}

