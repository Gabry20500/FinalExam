#include "Application.h"
#include <iostream>

Application::~Application()
{
	delete newWindow;
}

void Application::createWindow(unsigned int Width, unsigned int Height, const char* Title)
{
	newWindow = new sf::RenderWindow(sf::VideoMode(Width, Height), Title);
	if (!newWindow)
	{
		std::cout << "Window inizialization fail\n";
		return;
	}
}

void Application::initialize()
{
	/*auto background = new gfl::Sprite();
	background->renderer->set_texture_source("res/textures/background.png", true, true);
	background->rect_transform->set_scale(1920, 1080);
	allEntities.push_back(background);*/
}
