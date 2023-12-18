#pragma once
#include <SFML/Graphics.hpp>

class Object
{
public:
	Object() = default;
	virtual ~Object() = default;

	virtual void update() = 0;
	virtual void draw(sf::RenderWindow&) = 0;

private:

};
