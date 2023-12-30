#include "objects/MovingObjects.h"

MovingObjects::MovingObjects(const Characters& type, const AnimationData& data, int hp)
	:m_elapsed{}, m_hp {hp}
{
	initAnimationSettings(type, data);
	initPhysic(10, 5);
}

sf::Vector2f MovingObjects::getCurrentPosition()
{
	return m_character.back().getPosition();
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
	m_animationClock.restart();
}

sf::Time MovingObjects::getElapsedTime()
{
	return movementClock.restart();
}

void MovingObjects::setVelocity(float x, float y)
/*this function change back the velocity after the movement update*/
{
	m_velocity.x = x;
	m_velocity.y = y;
}

void MovingObjects::updatePhysic(bool movment)
{
	auto deltaTime = getElapsedTime().asMilliseconds();

	if(movment)
		m_velocity.x += deltaTime * 0.15f;
	m_velocity.y += deltaTime * 0.15f * 0.9;
}

float MovingObjects::norm(const sf::Vector2f& velocity)
{
	return (velocity.x * velocity.x + velocity.y * velocity.y);
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

void MovingObjects::changeDirection(const sf::Vector2f& scale)
{
	for (auto& i : m_character)
		i.setScale(scale.x, scale.y);
}

void MovingObjects::initAnimationSettings(const Characters& type, const AnimationData& data)
{
	m_animationTime = sf::seconds(0.2);
	m_currentAction = Action::Idle; 
	m_index = 0;
	m_animationData = data;
	m_character = getAnimation(type);
	setSprite();
}

void MovingObjects::initPhysic(int gravity, int weight)
{
	m_velocity = { 0,0 };
	m_gravity = gravity;
	Jumping = false;
	movementClock.restart();
}
