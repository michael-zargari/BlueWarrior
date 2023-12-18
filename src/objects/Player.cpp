#include "objects/Player.h"

Player::Player()
	:MovingObjects { Characters::Warrior, blueWarriorData() }
{
}

void Player::update()
{
	updateAnimation();
}

void Player::move()
{
	;
}

void Player::attack()
{
	;
}
