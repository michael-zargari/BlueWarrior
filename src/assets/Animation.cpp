#include "Animation.h"
#include "GameResources.h"

Animation::Animation(const Characters& type)
	:m_animationTime{ sf::seconds(0.1) }, m_elapsed{}, m_type{ type }, m_currentAction{Action::Run_Right}
{
	initilaize();
}

void Animation::update(sf::Time& delta)
{
	int index = 0;
	m_elapsed += delta;
	if (m_elapsed >= m_animationTime)
	{
		m_elapsed -= m_animationTime;
		++index;
		index %= m_characterData.m_data.find(m_currentAction)->second.size();
		setSprite(index);
	}
}

void Animation::setSprite(int index)
{
	m_Animation[static_cast<int>(Action::Run_Right)].setTextureRect(m_characterData.m_data.find(m_currentAction)->second[index]);
}

void Animation::getAnimationData()
{
	switch (m_type)
	{
	case Characters::Skeleton: m_characterData = skeletoWarriorData(); break;
	//case Characters::Skeleton: m_characterData = skeletoWarriorData(); break;
	//case Characters::Skeleton: m_characterData = skeletoWarriorData(); break;
	//case Characters::Skeleton: m_characterData = skeletoWarriorData(); break;
	}
}

void Animation::draw(sf::RenderWindow& window)
{
	window.draw(m_Animation[static_cast<int>(m_currentAction)]);
}

void Animation::initilaize()
{
	getAnimationData();

	m_Animation.emplace_back().setTexture(GameResources::getInstance().getSkeletonWarriorTexture(Action::Run_Right));
	m_Animation.emplace_back().setTexture(GameResources::getInstance().getSkeletonWarriorTexture(Action::Attack1));
	m_Animation[static_cast<int>(Action::Run_Right)].setPosition({ 600,400 });
	m_Animation[static_cast<int>(Action::Attack1)].setPosition({ 600,400 });
}
