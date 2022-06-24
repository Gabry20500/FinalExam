//Include project classes
#include "Application.h"
#include "Drawable.h"

//Include external libraries

//My FrameWork.dll
#include <component.h>
#include <Components/render2d.h>
#include <Components/controller.h>
#include <Classes/sprite.h>
#include <Classes/area2d.h>

//Standart libraries
#include <iostream>
//SFML libraries
#include <SFML/Graphics.hpp>

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

bool Application::isRunning() const
{
	return newWindow->isOpen();
}

unsigned Application::getFrameRate() const
{
	return 1/ elapsedTime;
}

void Application::setMaxFPS(unsigned limit)
{
	maxFPS = limit;
}

void Application::enableFPSLimit()
{
	fpsLimitEnabled = true;
}
void Application::disableFPSLimit()
{
	fpsLimitEnabled = false;
}

void Application::enableFixedUpdate()
{
	fixedUpdateEnabled = true;
}
void Application::disableFixedUpdate()
{
	fixedUpdateEnabled = false;
}

void Application::setMillisecondsForFixedUpdate(float milliseconds)
{
	msForFixedUpdate = milliseconds;
}



void Application::setBackgroundColor(sf::Color color)
{
	backgroundColor = color;
}

void Application::setBackgroundColor(float red, float green, float blue, float alpha)
{
	backgroundColor = sf::Color(red, green, blue, alpha);
}

void Application::initialize()
{
	auto background = new Sprite();
	background->renderer->set_texture_source("res/background/prato.jpg", true, true);
	background->rectTransform->set_scale(1920, 1080);
	allEntities.push_back(background);

	const auto character = new Sprite();
	character->renderer->set_texture_source("res/Character/player.png", true, false);
	character->rectTransform->set_scale(64, 64);
	character->rectTransform->set_position(960 - 32, 540 - 32);
	character->addComponent(new Controller());
	allEntities.push_back(character);
}

void Application::processInput()
{
	for each (auto actor in allEntities)
	{
		auto controllers = actor->get_components<Controller>();

		if (controllers.size() == 0) continue;

		for each (auto controller in controllers)
		{
			sf::Keyboard::Key key1;
			sf::Keyboard::Key key2;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				key1 = sf::Keyboard::Up;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				key1 = sf::Keyboard::Down;
			}
			else
			{
				key1 = sf::Keyboard::Unknown;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				key2 = sf::Keyboard::Left;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				key2 = sf::Keyboard::Left;
			}
			else
			{
				key2 = sf::Keyboard::Unknown;
			}

			sf::Keyboard::Key inputs[] = { key1, key2 };
			controller

		}
	}
}

void Application::draw()
{
}

void Application::processWindowEvents()
{
}

void Application::fixedUpdate()
{
}

void Application::update()
{
}

void Application::updateGameTime()
{
}
