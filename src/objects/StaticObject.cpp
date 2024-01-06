#include "objects/StaticObject.h"

StaticObject::StaticObject()
{
	tile.setSize({ 700, 50 });
	tile.setFillColor(sf::Color::White);
	tile.setOrigin({ 350,25 });
	tile.setPosition({ 700, 700 });
}

void StaticObject::draw(sf::RenderWindow& window)
{
	window.draw(tile);
}

sf::FloatRect StaticObject::getGlobalBonds() const
{
	return tile.getGlobalBounds();
}
