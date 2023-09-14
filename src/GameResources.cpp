#include "GameResources.h"

//constructor
GameResources::GameResources()
{
    initTextures();
    initFonts();
    initSounds();
}

//static func - singelton class
//return intance to the class
GameResources& GameResources::getInstance()
{
    static GameResources resources;
    return resources;
}


//get font
sf::Font& GameResources::getFont(const int& index)
{
    if (index < 2 && index >= 0)
        return m_font[index];
}


//create the text 
sf::Text& GameResources::createText(const std::string& dataName, const sf::Color& color, const int& font, const int& size)
{
    m_text.setString(dataName);
    m_text.setFont(getFont(font));
    const auto rect = m_text.getLocalBounds();
    m_text.setOrigin(rect.width / 2, rect.height / 2);
    m_text.setCharacterSize(size);
    m_text.setFillColor(color);
    m_text.setStyle(sf::Text::Bold);
    return m_text;
}

//load the texture for the game
void GameResources::initTextures()
{
    //std::array<std::string, 3> menuTextureNames{ "play.png", "help.png", "exit.png" };
    //for (size_t i = 0; i < menuTextureNames.size(); i++)
    //    m_menuTexture[i].loadFromFile(menuTextureNames.at(i));

}

//load the fonts for the game
void GameResources::initFonts()
{
    std::array<std::string, 2> fontsPath = { "C:/Windows/Fonts/Arial.ttf" ,"C:/Windows/Fonts/Ravie.ttf" };
    for (int i = 0; i < 2; i++)
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