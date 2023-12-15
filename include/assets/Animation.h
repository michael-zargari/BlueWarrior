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
	Animation(const Characters&, const AnimationData&);
	~Animation() = default;

	void update(sf::Time&);
	void setSprite();
	void setAction(/*Action,*/ float speed);
	void draw(sf::RenderWindow&);

private:
	Characters m_type;
	Action m_currentAction;

	AnimationData m_characterData;
	std::vector<sf::RectangleShape> m_Animation;

	sf::Time m_animationTime;
	sf::Time m_elapsed;
	int m_index;
};
