//#include "Animation.h"
//
//void Animation::updateAnimation(MovingObjects* character)
//{
//	m_elapsed += m_animationClock.restart();
//
//	if (m_elapsed >= m_animationTime)
//	{
//		m_elapsed -= m_animationTime;
//		++m_index;
//		m_index %= m_animationData.m_data.find(m_currentAction)->second.size();
//		setSprite(character);
//	}
//}
//
//void Animation::setSprite(MovingObjects* character)
//{
//	character[static_cast<int>(m_currentAction)].setTextureRect(m_animationData.m_data.find(m_currentAction)->second[m_index]);
//}
//
//void Animation::setAction(const Action& newAction, const float& speed)
//{
//	m_currentAction = newAction;
//	m_animationTime = sf::seconds(speed);
//	m_index = 0;
//	m_animationClock.restart();
//}
//
//void Animation::initAnimation()
//{
//	m_animationTime = sf::seconds(0.2);
//	m_currentAction = Action::Idle;
//	m_index = 0;
//	m_animationData = data;
//}
