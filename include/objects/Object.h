#pragma once
#include <SFML/Graphics.hpp>

class Object
{
public:
	Object() = default;
	virtual ~Object() = default;

	
	virtual void draw(sf::RenderWindow&) = 0;

private:

};
