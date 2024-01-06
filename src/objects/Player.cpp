#include "objects/Player.h"

Player::Player()
	:MovingObjects{ Characters::Warrior, blueWarriorData() }, m_direction{ 0,0 }, currAction{ Action::Idle }, currDir{1}
{
}

bool Player::checkForEvent()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (currDir == 1)//if the current direction is right - change back to left
		{
			changeDirection({ -1,1 });
			currDir = -1;
		}
		setUpForAction({ -1, 0 }, Action::Move, 0.15f);

		return true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (currDir == -1)//if the current direction is left - change back to right
		{
			changeDirection({ 1,1 });
			currDir = 1;
		}
			
		setUpForAction({ 1, 0 }, Action::Move, 0.15f);

		return true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		setUpForAction({ 0, 0 }, Action::Jump, 0.15f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		setUpForAction({ 0, 0 }, Action::Crouch, 0.15f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		setUpForAction({ 0, 0 }, Action::Attack, 0.15f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		setUpForAction({ 0, 0 }, Action::SpellCast, 0.15f);
	else
		setUpForAction({ 0, 0 }, Action::Idle, 0.2f);

	return false;
}

void Player::setUpForAction(const sf::Vector2f& direction, const Action& action, const float& speed)
{
	m_direction = direction;
	if (action != currAction)
	{
		setAction(action, speed);
		setSprite();
		currAction = action;
	}
	
}

void Player::update()
{
	updatePhysic(checkForEvent());
	move();
	updateAnimation();
}

void Player::move()
{
	//newPos.x responsible on the direction so we multiply by the velocity.x value
	//newPos.y responsible on the gravity so we add the value velocity.y
	changeDueGravity = m_direction.y + getVelocity().y;
	auto newPos = sf::Vector2f(m_direction.x * getVelocity().x, m_direction.y + getVelocity().y);
	newPos += getCurrentPosition();
	changePosition(newPos);
	setVelocity(0,0);
}

void Player::checkForCollision(sf::FloatRect other)
{
	if (getGlobalBonds().intersects(other))
		collisionWithTile();
}

void Player::collisionWithTile()
{
	sf::Vector2f newPos;
	newPos = getCurrentPosition();
	newPos.y -= changeDueGravity;
	changePosition(newPos);
}


