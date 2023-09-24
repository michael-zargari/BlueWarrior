#include "Animation.h"
#include "GameResources.h"


Animation::Animation(const Characters& type)
	:m_animationTime{ sf::seconds(0.2) }, m_elapsed{}, m_type{ type }, m_currentAction{ Action::Attack1 }, m_index{0}
{
	initilaize();
}

void Animation::update(sf::Time& delta)
{
	m_elapsed += delta;
	std::cout << m_elapsed.asSeconds() << "\n" ;
	if (m_elapsed >= m_animationTime)
	{
		std::cout << "hj\n";
		m_elapsed -= m_animationTime;
		++m_index;
		m_index %= m_characterData.m_data.find(m_currentAction)->second.size();
		setSprite();
	}
}

void Animation::setSprite()
{
	std::cout << m_index << "\n";
	m_Animation[static_cast<int>(m_currentAction)].setTextureRect(m_characterData.m_data.find(m_currentAction)->second[m_index]);
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

	setSprite();
}
