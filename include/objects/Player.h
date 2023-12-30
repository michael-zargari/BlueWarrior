#pragma once

#include "objects/MovingObjects.h"

class Player : public MovingObjects
{
public:
	Player();
	~Player() = default;

	bool checkForEvent();
	void setUpForAction(const sf::Vector2f&, const Action&, const float&);
	void update() override;
	void move() override;
	//void jump();
	//void fall();
	//void attack() override;

private:
	sf::Vector2f m_direction;
	Action currAction;
	int currDir; // right = 1, left = -1
	float m_startingY;
	float m_currY;
	float jumpForce = 50.f;
};

