#pragma once

#include <sfml/Graphics.hpp>
#include <vector>
#include <unordered_map>

#include "assets/Macro.h"
#include "AnimationData.h"

class Animation
{
public:
	Animation(const Characters&);
	~Animation() = default;

	void update(sf::Time&);
	void setSprite(int index);
	void getAnimationData();
	void draw(sf::RenderWindow&);

private:
	Characters m_type;
	Action m_currentAction;

	AnimationData m_characterData;
	std::vector<sf::Sprite> m_Animation;

	sf::Time m_animationTime;
	sf::Time m_elapsed;

	void initilaize();
};
