#include "Window.h"

Window::Window()
	:m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My First Project")
{}

sf::RenderWindow& Window::getWindow()
{
	return m_window;
}


