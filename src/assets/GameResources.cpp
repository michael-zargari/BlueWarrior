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


const sf::Texture& GameResources::getSkeletonWarriorTexture(const Action& action) const
{
    return m_SkeltonWarrior[static_cast<int>(action)];
}

//get font
sf::Font& GameResources::getFont(const int& index)
{
    if (index < 4 && index >= 0)
        return m_font[index];
}


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



//load the texture for the game
void GameResources::initTextures()
{
    std::array<std::string, 2> skeletonTextureNames{ "Run.png", "Attack_1.png" };
    for (size_t i = 0; i < skeletonTextureNames.size(); i++)
        m_SkeltonWarrior[i].loadFromFile(skeletonTextureNames.at(i));

}

//load the fonts for the game
void GameResources::initFonts()
{
    std::array<std::string, 4> fontsPath = { "C:/Windows/Fonts/Arial.ttf" ,"C:/Windows/Fonts/Ravie.ttf", "C:/Windows/Fonts/ARLRDBD.ttf", "C:/Windows/Fonts/ALGER.ttf"};
    for (int i = 0; i < 4; i++)
    {
        sf::Font temp;
        temp.loadFromFile(fontsPath[i]);
        m_font[i] = temp;
    }
}

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