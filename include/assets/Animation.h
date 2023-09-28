#pragma once

#include <sfml/Graphics.hpp>
#include <vector>
#include <unordered_map>

#include "assets/Macro.h"
#include "AnimationData.h"

//template <typename CHARACTERACTION>
class Animation
{
public:
	Animation(const Characters&);
	~Animation() = default;

	void update(sf::Time&);
	void setSprite();
	void getAnimationData();
	void draw(sf::RenderWindow&);

private:
	Characters m_type;
	//WarriorAction m_currentAction;
	//FlyingEyeAction m_currentAction;
	//GoblinAction m_currentAction;
	//MushroomAction m_currentAction;
	SkeletonAction m_currentAction;

	AnimationData<SkeletonAction> m_characterData;
	std::vector<sf::RectangleShape> m_Animation;

	sf::Time m_animationTime;
	sf::Time m_elapsed;
	int m_index;
	void initilaize();
};
