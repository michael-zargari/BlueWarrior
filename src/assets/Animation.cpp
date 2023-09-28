#include "Animation.h"
#include "GameResources.h"


Animation::Animation(const Characters& type)
	:m_animationTime{ sf::seconds(0.2) }, m_elapsed{}, m_type{ type }, m_currentAction{ SkeletonAction::Walk }, m_index{0}
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
	//auto current = m_Animation[static_cast<int>(m_currentAction)].getPosition();
	//current.x += 2.f;
	//m_Animation[static_cast<int>(m_currentAction)].setPosition(current);

	//set the sprite origin according to the current texture rectangle 
	//auto f = m_Animation[static_cast<int>(GoblinAction::Attack)].getTextureRect().getSize() / 2;
	//m_Animation[static_cast<int>(GoblinAction::Attack)].setOrigin(sf::Vector2f(f));
	//m_Animation[static_cast<int>(GoblinAction::Attack)].setScale({ 2, 2 });
}

void Animation::getAnimationData()
{
	switch (m_type)
	{
	//case Characters::Warrior: m_characterData = blueWarriorData(); break;
	//case Characters::FlyingEye: m_characterData = FlyingEyeData(); break;
	//case Characters::Goblin: m_characterData = goblinData(); break;
	//case Characters::Mushroom: m_characterData = mushroomData(); break;
	case Characters::Skeleton: m_characterData = skeletonData(); break;
	}

}

void Animation::draw(sf::RenderWindow& window)
{
	window.draw(m_Animation[static_cast<int>(m_currentAction)]);
}

void Animation::initilaize()
{
	getAnimationData();

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getWarriorTexture(WarriorAction::Idle));
	//m_Animation[static_cast<int>(WarriorAction::Idle)].setSize({ 75, 75 });
	//m_Animation[static_cast<int>(WarriorAction::Idle)].setOrigin({ 75/2, 75/2 });
	//m_Animation[static_cast<int>(WarriorAction::Idle)].setPosition({ 600,400 });

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getWarriorTexture(WarriorAction::Attack));
	//m_Animation[static_cast<int>(WarriorAction::Attack)].setSize({ 75, 75 });
	//m_Animation[static_cast<int>(WarriorAction::Attack)].setOrigin({ 75 / 2, 75 / 2 });
	//m_Animation[static_cast<int>(WarriorAction::Attack)].setPosition({ 600,400 });

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getWarriorTexture(WarriorAction::Running));
	//m_Animation[static_cast<int>(WarriorAction::Running)].setSize({ 75, 75 });
	//m_Animation[static_cast<int>(WarriorAction::Running)].setOrigin({ 75 / 2, 75 / 2 });
	//m_Animation[static_cast<int>(WarriorAction::Running)].setPosition({ 600,400 });


	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getWarriorTexture(WarriorAction::Jump));
	//m_Animation[static_cast<int>(WarriorAction::Jump)].setSize({ 75, 75 });
	//m_Animation[static_cast<int>(WarriorAction::Jump)].setOrigin({ 75 / 2, 75 / 2 });
	//m_Animation[static_cast<int>(WarriorAction::Jump)].setPosition({ 600,400 });

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getWarriorTexture(WarriorAction::Falling));
	//m_Animation[static_cast<int>(WarriorAction::Falling)].setSize({ 75, 75 });
	//m_Animation[static_cast<int>(WarriorAction::Falling)].setOrigin({ 75 / 2, 75 / 2 });
	//m_Animation[static_cast<int>(WarriorAction::Falling)].setPosition({ 600,400 });

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getWarriorTexture(WarriorAction::TakeHit));
	//m_Animation[static_cast<int>(WarriorAction::TakeHit)].setSize({ 75, 75 });
	//m_Animation[static_cast<int>(WarriorAction::TakeHit)].setOrigin({ 75 / 2, 75 / 2 });
	//m_Animation[static_cast<int>(WarriorAction::TakeHit)].setPosition({ 600,400 });
	//
	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getWarriorTexture(WarriorAction::Death));
	//m_Animation[static_cast<int>(WarriorAction::Death)].setSize({ 75, 75 });
	//m_Animation[static_cast<int>(WarriorAction::Death)].setOrigin({ 75 / 2, 75 / 2 });
	//m_Animation[static_cast<int>(WarriorAction::Death)].setPosition({ 600,400 });

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getWarriorTexture(WarriorAction::SpellCast));
	//m_Animation[static_cast<int>(WarriorAction::SpellCast)].setSize({ 75, 75 });
	//m_Animation[static_cast<int>(WarriorAction::SpellCast)].setOrigin({ 75 / 2, 75 / 2 });
	//m_Animation[static_cast<int>(WarriorAction::SpellCast)].setPosition({ 600,400 });

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getWarriorTexture(WarriorAction::Crouch));
	//m_Animation[static_cast<int>(WarriorAction::Crouch)].setSize({ 75, 75 });
	//m_Animation[static_cast<int>(WarriorAction::Crouch)].setOrigin({ 75 / 2, 75 / 2 });
	//m_Animation[static_cast<int>(WarriorAction::Crouch)].setPosition({ 600,400 });

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getWarriorTexture(WarriorAction::Shield));
	//m_Animation[static_cast<int>(WarriorAction::Shield)].setSize({ 75, 75 });
	//m_Animation[static_cast<int>(WarriorAction::Shield)].setOrigin({ 75 / 2, 75 / 2 });
	//m_Animation[static_cast<int>(WarriorAction::Shield)].setPosition({ 600,400 });

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getFlyingEyeTexture(FlyingEyeAction::Attack));
	//m_Animation[static_cast<int>(FlyingEyeAction::Attack)].setSize({ 75, 75 });
	//m_Animation[static_cast<int>(FlyingEyeAction::Attack)].setOrigin({ 75 / 2, 75 / 2 });
	//m_Animation[static_cast<int>(FlyingEyeAction::Attack)].setPosition({ 600,400 });

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getFlyingEyeTexture(FlyingEyeAction::Death));
	//m_Animation[static_cast<int>(FlyingEyeAction::Death)].setSize({ 75, 75 });
	//m_Animation[static_cast<int>(FlyingEyeAction::Death)].setOrigin({ 75 / 2, 75 / 2 });
	//m_Animation[static_cast<int>(FlyingEyeAction::Death)].setPosition({ 600,400 });

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getFlyingEyeTexture(FlyingEyeAction::Flight));
	//m_Animation[static_cast<int>(FlyingEyeAction::Flight)].setSize({ 75, 75 });
	//m_Animation[static_cast<int>(FlyingEyeAction::Flight)].setOrigin({ 75 / 2, 75 / 2 });
	//m_Animation[static_cast<int>(FlyingEyeAction::Flight)].setPosition({ 600,400 });

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getFlyingEyeTexture(FlyingEyeAction::TakeHit));
	//m_Animation[static_cast<int>(FlyingEyeAction::TakeHit)].setSize({ 75, 75 });
	//m_Animation[static_cast<int>(FlyingEyeAction::TakeHit)].setOrigin({ 75 / 2, 75 / 2 });
	//m_Animation[static_cast<int>(FlyingEyeAction::TakeHit)].setPosition({ 600,400 });

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getGoblinTexture(GoblinAction::Attack));
	//m_Animation[static_cast<int>(GoblinAction::Attack)].setSize({ 90, 90 });
	//m_Animation[static_cast<int>(GoblinAction::Attack)].setOrigin({ 90 / 2, 90 / 2 });
	////m_Animation[static_cast<int>(GoblinAction::Attack)].setScale({ -1, 1 });
	//m_Animation[static_cast<int>(GoblinAction::Attack)].setPosition({ 600,400 });

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getGoblinTexture(GoblinAction::Death));
	//m_Animation[static_cast<int>(GoblinAction::Death)].setSize({ 90, 90 });
	//m_Animation[static_cast<int>(GoblinAction::Death)].setOrigin({ 90 / 2, 90 / 2 });
	////m_Animation[static_cast<int>(GoblinAction::Attack)].setScale({ -1, 1 });
	//m_Animation[static_cast<int>(GoblinAction::Death)].setPosition({ 600,400 });

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getGoblinTexture(GoblinAction::Idle));
	//m_Animation[static_cast<int>(GoblinAction::Idle)].setSize({ 90, 90 });
	//m_Animation[static_cast<int>(GoblinAction::Idle)].setOrigin({ 90 / 2, 90 / 2 });
	////m_Animation[static_cast<int>(GoblinAction::Attack)].setScale({ -1, 1 });
	//m_Animation[static_cast<int>(GoblinAction::Idle)].setPosition({ 600,400 });

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getGoblinTexture(GoblinAction::Run));
	//m_Animation[static_cast<int>(GoblinAction::Run)].setSize({ 90, 90 });
	//m_Animation[static_cast<int>(GoblinAction::Run)].setOrigin({ 90 / 2, 90 / 2 });
	////m_Animation[static_cast<int>(GoblinAction::Attack)].setScale({ -1, 1 });
	//m_Animation[static_cast<int>(GoblinAction::Run)].setPosition({ 600,400 });

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getGoblinTexture(GoblinAction::TakeHit));
	//m_Animation[static_cast<int>(GoblinAction::TakeHit)].setSize({ 90, 90 });
	//m_Animation[static_cast<int>(GoblinAction::TakeHit)].setOrigin({ 90 / 2, 90 / 2 });
	////m_Animation[static_cast<int>(GoblinAction::Attack)].setScale({ -1, 1 });
	//m_Animation[static_cast<int>(GoblinAction::TakeHit)].setPosition({ 600,400 });

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getMushroomTexture(MushroomAction::Attack));
	//m_Animation[static_cast<int>(MushroomAction::Attack)].setSize({ 90, 90 });
	//m_Animation[static_cast<int>(MushroomAction::Attack)].setOrigin({ 90 / 2, 90 / 2 });
	////m_Animation[static_cast<int>(GoblinAction::Attack)].setScale({ -1, 1 });
	//m_Animation[static_cast<int>(MushroomAction::Attack)].setPosition({ 600,400 });

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getMushroomTexture(MushroomAction::Death));
	//m_Animation[static_cast<int>(MushroomAction::Death)].setSize({ 90, 90 });
	//m_Animation[static_cast<int>(MushroomAction::Death)].setOrigin({ 90 / 2, 90 / 2 });
	////m_Animation[static_cast<int>(GoblinAction::Attack)].setScale({ -1, 1 });
	//m_Animation[static_cast<int>(MushroomAction::Death)].setPosition({ 600,400 });

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getMushroomTexture(MushroomAction::Idle));
	//m_Animation[static_cast<int>(MushroomAction::Idle)].setSize({ 90, 90 });
	//m_Animation[static_cast<int>(MushroomAction::Idle)].setOrigin({ 90 / 2, 90 / 2 });
	////m_Animation[static_cast<int>(GoblinAction::Attack)].setScale({ -1, 1 });
	//m_Animation[static_cast<int>(MushroomAction::Idle)].setPosition({ 600,400 });

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getMushroomTexture(MushroomAction::Run));
	//m_Animation[static_cast<int>(MushroomAction::Run)].setSize({ 90, 90 });
	//m_Animation[static_cast<int>(MushroomAction::Run)].setOrigin({ 90 / 2, 90 / 2 });
	////m_Animation[static_cast<int>(GoblinAction::Attack)].setScale({ -1, 1 });
	//m_Animation[static_cast<int>(MushroomAction::Run)].setPosition({ 600,400 });

	//m_Animation.emplace_back().setTexture(&GameResources::getInstance().getMushroomTexture(MushroomAction::TakeHit));
	//m_Animation[static_cast<int>(MushroomAction::TakeHit)].setSize({ 90, 90 });
	//m_Animation[static_cast<int>(MushroomAction::TakeHit)].setOrigin({ 90 / 2, 90 / 2 });
	////m_Animation[static_cast<int>(GoblinAction::Attack)].setScale({ -1, 1 });
	//m_Animation[static_cast<int>(MushroomAction::TakeHit)].setPosition({ 600,400 });

	m_Animation.emplace_back().setTexture(&GameResources::getInstance().getSkeletonTexture(SkeletonAction::Attack));
	m_Animation[static_cast<int>(SkeletonAction::Attack)].setSize({ 90, 90 });
	m_Animation[static_cast<int>(SkeletonAction::Attack)].setOrigin({ 90 / 2, 90 / 2 });
	//m_Animation[static_cast<int>(GoblinAction::Attack)].setScale({ -1, 1 });
	m_Animation[static_cast<int>(SkeletonAction::Attack)].setPosition({ 600,400 });

	m_Animation.emplace_back().setTexture(&GameResources::getInstance().getSkeletonTexture(SkeletonAction::Death));
	m_Animation[static_cast<int>(SkeletonAction::Death)].setSize({ 90, 90 });
	m_Animation[static_cast<int>(SkeletonAction::Death)].setOrigin({ 90 / 2, 90 / 2 });
	//m_Animation[static_cast<int>(GoblinAction::Attack)].setScale({ -1, 1 });
	m_Animation[static_cast<int>(SkeletonAction::Death)].setPosition({ 600,400 });

	m_Animation.emplace_back().setTexture(&GameResources::getInstance().getSkeletonTexture(SkeletonAction::Idle));
	m_Animation[static_cast<int>(SkeletonAction::Idle)].setSize({ 90, 90 });
	m_Animation[static_cast<int>(SkeletonAction::Idle)].setOrigin({ 90 / 2, 90 / 2 });
	//m_Animation[static_cast<int>(GoblinAction::Attack)].setScale({ -1, 1 });
	m_Animation[static_cast<int>(SkeletonAction::Idle)].setPosition({ 600,400 });

	m_Animation.emplace_back().setTexture(&GameResources::getInstance().getSkeletonTexture(SkeletonAction::Shield));
	m_Animation[static_cast<int>(SkeletonAction::Shield)].setSize({ 90, 90 });
	m_Animation[static_cast<int>(SkeletonAction::Shield)].setOrigin({ 90 / 2, 90 / 2 });
	//m_Animation[static_cast<int>(GoblinAction::Attack)].setScale({ -1, 1 });
	m_Animation[static_cast<int>(SkeletonAction::Shield)].setPosition({ 600,400 });

	m_Animation.emplace_back().setTexture(&GameResources::getInstance().getSkeletonTexture(SkeletonAction::TakeHit));
	m_Animation[static_cast<int>(SkeletonAction::TakeHit)].setSize({ 90, 90 });
	m_Animation[static_cast<int>(SkeletonAction::TakeHit)].setOrigin({ 90 / 2, 90 / 2 });
	//m_Animation[static_cast<int>(GoblinAction::Attack)].setScale({ -1, 1 });
	m_Animation[static_cast<int>(SkeletonAction::TakeHit)].setPosition({ 600,400 });

	m_Animation.emplace_back().setTexture(&GameResources::getInstance().getSkeletonTexture(SkeletonAction::Walk));
	m_Animation[static_cast<int>(SkeletonAction::Walk)].setSize({ 90, 90 });
	m_Animation[static_cast<int>(SkeletonAction::Walk)].setOrigin({ 90 / 2, 90 / 2 });
	//m_Animation[static_cast<int>(GoblinAction::Attack)].setScale({ -1, 1 });
	m_Animation[static_cast<int>(SkeletonAction::Walk)].setPosition({ 600,400 });

	setSprite();
}
