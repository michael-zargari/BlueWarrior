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
const sf::Texture& GameResources::getCharacterTexture(const Characters& character, const Action& action) const
{
    switch (character)
    {
    case Characters::Warrior:   return getWarriorTexture(action);
    case Characters::FlyingEye: return getFlyingEyeTexture(action);
    case Characters::Goblin:    return getGoblinTexture(action);
    case Characters::Mushroom:  return getMushroomTexture(action);
    case Characters::Skeleton:  return getSkeletonTexture(action);
    }
}

//===============================================================================
const sf::Texture& GameResources::getWarriorTexture(const Action& action) const
{
    switch (action)
    {
    case Action::Attack:
    case Action::Death:
    case Action::Idle:
    case Action::Move:
    case Action::TakeHit:
    case Action::Jump:
    case Action::Falling:
   // case Action::Landing:
    case Action::SpellCast:
    case Action::Crouch:
    case Action::Shield:  return m_warrior; break;
    }
   
}
//===============================================================================
const sf::Texture& GameResources::getFlyingEyeTexture(const Action& action) const
{
    switch (action)
    {
    case Action::Attack: return m_FlyingEye[static_cast<int>(Action::Attack)]; break;
    case Action::Death:  return m_FlyingEye[static_cast<int>(Action::Death)]; break;
    case Action::Idle:  return m_FlyingEye[static_cast<int>(Action::Idle)]; break;
    case Action::Move: return m_FlyingEye[static_cast<int>(Action::Move)]; break;
    case Action::TakeHit:return m_FlyingEye[static_cast<int>(Action::TakeHit)]; break;
    }
}

//===============================================================================
const sf::Texture& GameResources::getGoblinTexture(const Action& action) const
{
    switch (action)
    {
    case Action::Attack: return m_Goblin[static_cast<int>(Action::Attack)]; break;
    case Action::Death:  return m_Goblin[static_cast<int>(Action::Death)]; break;
    case Action::Idle:   return m_Goblin[static_cast<int>(Action::Idle)]; break;
    case Action::Move:    return m_Goblin[static_cast<int>(Action::Move)]; break;
    case Action::TakeHit:return m_Goblin[static_cast<int>(Action::TakeHit)]; break;
    }
}

//===============================================================================
const sf::Texture& GameResources::getMushroomTexture(const Action& action) const
{
    switch (action)
    {
    case Action::Attack: return m_Mushroom[static_cast<int>(Action::Attack)]; break;
    case Action::Death:  return m_Mushroom[static_cast<int>(Action::Death)]; break;
    case Action::Idle:   return m_Mushroom[static_cast<int>(Action::Idle)]; break;
    case Action::Move:    return m_Mushroom[static_cast<int>(Action::Move)]; break;
    case Action::TakeHit:return m_Mushroom[static_cast<int>(Action::TakeHit)]; break;
    }
}

//===============================================================================
const sf::Texture& GameResources::getSkeletonTexture(const Action& action) const
{
    switch (action)
    {
    case Action::Attack: return m_Skeleton[static_cast<int>(Action::Attack)];  break;
    case Action::Death:  return m_Skeleton[static_cast<int>(Action::Death)];   break;
    case Action::Idle:   return m_Skeleton[static_cast<int>(Action::Idle)];    break;
    case Action::Move:   return m_Skeleton[static_cast<int>(Action::Move)];    break;
    case Action::TakeHit:return m_Skeleton[static_cast<int>(Action::TakeHit)]; break;
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
    std::array<std::string, 5> EvilEyeTextureNames {"flyingEyeAttack.png", "flyingEyeDeath.png", "flyingEyeFlight.png", 
                                                    "flyingEyeFlight.png", "flyingEyeTakeHit.png"};
    for (int i = 0; i < 5; i++)
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
    std::array<std::string, 5> skeletonTextureNames {"skeletonAttack.png", "skeletonDeath.png", "skeletonIdle.png",
                                                         "skeletonWalk.png", "skeletonTakeHit.png"};
    for (int i = 0; i < 5; i++)
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