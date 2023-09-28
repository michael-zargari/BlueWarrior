#include "GameResources.h"

//constructor
GameResources::GameResources()
{
    initTextures();
    initFonts();
    //initSounds();
}

//static func - singelton class
//return intance to the class
GameResources& GameResources::getInstance()
{
    static GameResources resources;
    return resources;
}

//===============================================================================
const sf::Texture& GameResources::getWarriorTexture(const WarriorAction& action) const
{
    switch (action)
    {
    case WarriorAction::Idle: 
    case WarriorAction::Attack: 
    case WarriorAction::Running: 
    case WarriorAction::Jump: 
    case WarriorAction::Falling:
    case WarriorAction::TakeHit:
    case WarriorAction::Death:
    case WarriorAction::SpellCast:
    case WarriorAction::Crouch:
    case WarriorAction::Shield:  return m_warrior; break;
    }
   
}

//===============================================================================
const sf::Texture& GameResources::getFlyingEyeTexture(const FlyingEyeAction& action) const
{
    switch (action)
    {
    case FlyingEyeAction::Attack: return m_FlyingEye[static_cast<int>(FlyingEyeAction::Attack)]; break;
    case FlyingEyeAction::Death:  return m_FlyingEye[static_cast<int>(FlyingEyeAction::Death)]; break;
    case FlyingEyeAction::Flight: return m_FlyingEye[static_cast<int>(FlyingEyeAction::Flight)]; break;
    case FlyingEyeAction::TakeHit:return m_FlyingEye[static_cast<int>(FlyingEyeAction::TakeHit)]; break;
    }
}

//===============================================================================
const sf::Texture& GameResources::getGoblinTexture(const GoblinAction& action) const
{
    switch (action)
    {
    case GoblinAction::Attack: return m_Goblin[static_cast<int>(GoblinAction::Attack)]; break;
    case GoblinAction::Death:  return m_Goblin[static_cast<int>(GoblinAction::Death)]; break;
    case GoblinAction::Idle:   return m_Goblin[static_cast<int>(GoblinAction::Idle)]; break;
    case GoblinAction::Run:    return m_Goblin[static_cast<int>(GoblinAction::Run)]; break;
    case GoblinAction::TakeHit:return m_Goblin[static_cast<int>(GoblinAction::TakeHit)]; break;
    }
}

const sf::Texture& GameResources::getMushroomTexture(const MushroomAction& action) const
{
    switch (action)
    {
    case MushroomAction::Attack: return m_Mushroom[static_cast<int>(GoblinAction::Attack)]; break;
    case MushroomAction::Death:  return m_Mushroom[static_cast<int>(GoblinAction::Death)]; break;
    case MushroomAction::Idle:   return m_Mushroom[static_cast<int>(GoblinAction::Idle)]; break;
    case MushroomAction::Run:    return m_Mushroom[static_cast<int>(GoblinAction::Run)]; break;
    case MushroomAction::TakeHit:return m_Mushroom[static_cast<int>(GoblinAction::TakeHit)]; break;
    }
}

const sf::Texture& GameResources::getSkeletonTexture(const SkeletonAction& action) const
{
    switch (action)
    {
    case SkeletonAction::Attack: return m_Skeleton[static_cast<int>(SkeletonAction::Attack)];  break;
    case SkeletonAction::Death:  return m_Skeleton[static_cast<int>(SkeletonAction::Death)];   break;
    case SkeletonAction::Idle:   return m_Skeleton[static_cast<int>(SkeletonAction::Idle)];    break;
    case SkeletonAction::Shield: return m_Skeleton[static_cast<int>(SkeletonAction::Shield)];  break;
    case SkeletonAction::TakeHit:return m_Skeleton[static_cast<int>(SkeletonAction::TakeHit)]; break;
    case SkeletonAction::Walk:   return m_Skeleton[static_cast<int>(SkeletonAction::Walk)];    break;
    }
}

//===============================================================================
//get font
sf::Font& GameResources::getFont(const int& index)
{
    if (index < 4 && index >= 0)
        return m_font[index];
}

//===============================================================================
//create the text 
sf::Text& GameResources::createText(const std::string& dataName, const sf::Color& color, const int& font, const int& size, sf::Vector2f position)
{
    m_text.setString(dataName);
    m_text.setFont(getFont(font));
    const auto rect = m_text.getLocalBounds();
    m_text.setOrigin(rect.width / 2, rect.height / 2);
    m_text.setPosition(position);
    m_text.setCharacterSize(size);
    m_text.setFillColor(color);
    m_text.setStyle(sf::Text::Bold);
    return m_text;
}


//===============================================================================
//load the texture for the game
void GameResources::initTextures()
{
    //warrior texture
    m_warrior.loadFromFile("char_blue_1.png");

    //flying eye textures
    std::array<std::string, 4> EvilEyeTextureNames {"flyingEyeAttack.png", "flyingEyeDeath.png", "flyingEyeFlight.png",
                                                    "flyingEyeTakeHit.png"};
    for (int i = 0; i < 4; i++)
        m_FlyingEye[i].loadFromFile(EvilEyeTextureNames.at(i));

    //goblin textures
    std::array<std::string, 5> goblinTextureNames {"goblinAttack.png", "goblinDeath.png", "goblinIdle.png", 
                                                   "goblinRun.png", "goblinTakeHit.png"};
    for (int i = 0; i < 5; i++)
        m_Goblin[i].loadFromFile(goblinTextureNames.at(i));

    //mushroom textures
    std::array<std::string, 5> mushroomTextureNames {"mushroomAttack.png", "mushroomDeath.png", "mushroomIdle.png",
                                                   "mushroomRun.png", "mushroomTakeHit.png"};
    for (int i = 0; i < 5; i++)
        m_Mushroom[i].loadFromFile(mushroomTextureNames.at(i));

    //skeleton textures
    std::array<std::string, 6> skeletonTextureNames {"skeletonAttack.png", "skeletonDeath.png", "skeletonIdle.png",
                                                     "skeletonShield.png", "skeletonTakeHit.png", "skeletonWalk.png"};
    for (int i = 0; i < 6; i++)
        m_Skeleton[i].loadFromFile(skeletonTextureNames.at(i));
}

//===============================================================================
//load the fonts for the game
void GameResources::initFonts()
{
    std::array<std::string, 4> fontsPath = { "C:/Windows/Fonts/Arial.ttf" ,"C:/Windows/Fonts/Ravie.ttf", 
                                             "C:/Windows/Fonts/ARLRDBD.ttf", "C:/Windows/Fonts/ALGER.ttf"};
    for (int i = 0; i < 4; i++)
    {
        sf::Font temp;
        temp.loadFromFile(fontsPath[i]);
        m_font[i] = temp;
    }
}

//===============================================================================
//load the sounds for the game
void GameResources::initSounds()
{
    ////load the music
    //m_BackGroundBuffer.loadFromFile("menuThemeSong.opus");

    ////init background music
    //m_BackGroundSound.setBuffer(m_BackGroundBuffer);
    //m_BackGroundSound.setLoop(true);
    //m_BackGroundSound.play();
}