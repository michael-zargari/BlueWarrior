#pragma once

#include "objects/Object.h"

class StaticObject : public Object
{
public:
	StaticObject();
	~StaticObject() = default;
	void draw(sf::RenderWindow&)override;
	sf::FloatRect getGlobalBonds() const;
private:
	sf::RectangleShape tile;
};

/*probably we need to get a type and according to it we will create the wanted object*/