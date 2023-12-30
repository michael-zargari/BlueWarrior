#include "Window.h"

Window::Window()
	:m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My First Project")
{
	m_window.setFramerateLimit(60);
}

sf::RenderWindow& Window::getWindow()
{
	return m_window;
}


