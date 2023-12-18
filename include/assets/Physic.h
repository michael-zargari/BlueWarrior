#pragma once

#include "SFML/Graphics.hpp"

class Physic
{
public:
	Physic();
	~Physic() = default;
private:
	sf::Vector2f m_gravity;
	sf::Vector2f m_velocity;

};