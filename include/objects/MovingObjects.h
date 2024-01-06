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
	//virtual void attack() = 0;

	void changePosition(const sf::Vector2f&);
	void changeDirection(const sf::Vector2f&);

	//getters/setters
	void setHp(int toAdd) { m_hp += toAdd; };
	sf::Vector2f getCurrentPosition() const;
	sf::FloatRect getGlobalBonds() const;

	//Animation
	void updateAnimation();
	void setSprite();
	void setAction(const Action&, const float&);

	//Physic
	sf::Time getElapsedTime();
	void setVelocity(float, float);
	void updatePhysic(bool);
	float norm(const sf::Vector2f&);
	bool isJumping() { return Jumping; }
	void setJumping(bool jumping = true) { Jumping = jumping; }
	bool isFalling() { return Falling; }
	void setFalling(bool falling = true) { Falling = falling; }
	sf::Vector2f getVelocity() { return m_velocity; }

	//
private:
	int m_hp;

	std::vector<sf::RectangleShape> m_character;//vector that holds all the textures for the character
	virtual void update() = 0;
	//------------for animation----------
	Action m_currentAction;

	AnimationData m_animationData;
	
	sf::Clock m_animationClock;
	sf::Time m_animationTime;
	sf::Time m_elapsed;

	int m_index;
	//-----------------------------------------

	//-----------for Physic-----------------
	sf::Clock movementClock;

	sf::Vector2f m_velocity;//How much to move according to the elapsed time - x = direction(left or right) 
							//                                                 y = gravity, always applying on moving object
	int m_gravity;
	int m_weight;
	
	bool Jumping;
	bool Falling;
	//--------------------------------------

	void initAnimationSettings(const Characters&, const AnimationData& );
	void initPhysic(int gravity, int weight);
};
