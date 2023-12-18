#pragma once

#include "objects/MovingObjects.h"

class Player : public MovingObjects
{
public:
	Player();
	~Player() = default;

	void update() override;
	void move() override;
	void attack() override;

private:

};

