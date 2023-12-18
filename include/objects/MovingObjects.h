#pragma once 

#include "objects/Object.h"
#include "Macro.h"
#include "AnimationData.h"

class MovingObjects : public Object
{
public:
	MovingObjects(const Characters&, const AnimationData&, int hp = 100);
	~MovingObjects() = default;
	
	//logic
	void draw(sf::RenderWindow&) override;

	//methhods - actions
	virtual void move() = 0;
	virtual void attack() = 0;
	void changePosition(const sf::Vector2f&);
	void setHp(int toAdd) { m_hp += toAdd; };

	//Animation
	void updateAnimation();
	void setSprite();
	void setAction(const Action&, const float&);

private:
	int m_hp;

	std::vector<sf::RectangleShape> m_character;//vector that holds all the textures for the character

	//------------for animation----------
	Action m_currentAction;

	AnimationData m_animationData;
	
	sf::Clock m_animationClock;
	sf::Time m_animationTime;
	sf::Time m_elapsed;

	int m_index;
	//-----------------------------------------
};
