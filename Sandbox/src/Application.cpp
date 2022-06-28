//Include project classes
#include "Application.h"
#include "Drawable.h"



//Include external libraries

//My FrameWork.dll
#include <component.h>
#include <Components/render2d.h>
#include "Components/controller.h"
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

unsigned Application::getFPS() const
{
	return 1/pastTime;
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

void Application::setBackgroundColor(sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue, sf::Uint8 alpha)
{
	backgroundColor = sf::Color(red, green, blue, alpha);
}

void Application::initialize()
{
	auto background = new Sprite();
	background->renderer->set_texture_source("res/background/back.jpg", true, true);
	background->rectTransform->set_scale(1920, 1080);
	allEntities.push_back(background);

	const auto character = new Sprite();
	character->renderer->set_texture_source("res/Character/player.png", true, false);
	character->rectTransform->set_scale(180, 180);
	character->rectTransform->set_position(960 - 32, 540 - 32);
	character->addComponent(new Controller());
	allEntities.push_back(character);

	for (GameObject* go : allEntities) {
		printf("%s", go->get_name().c_str());
	}
}

void Application::processInput()
{
	for each (auto actor in allEntities)
	{
		auto controllers = actor->get_components<Controller>();

		if (controllers.size() == 0) continue;

		for each (auto controller in controllers)
		{

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				controller->on_input(sf::Keyboard::Up);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				controller->on_input(sf::Keyboard::Down);
			}
			else
			{
				controller->on_input(sf::Keyboard::Unknown);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				controller->on_input(sf::Keyboard::Left);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				controller->on_input(sf::Keyboard::Right);
			}
			else
			{
				controller->on_input(sf::Keyboard::Unknown);
			}

			
			

		}
	}
}

void Application::draw()
{
	newWindow->clear(backgroundColor);
	for each (auto item in allEntities)
	{
		const auto renders = item->get_components<RectTransform>();

		for each (auto rend in renders)
		{
			newWindow->draw(*rend->get_transform());
		}
	}

	newWindow->display();
}

void Application::processWindowEvents()
{
	sf::Event evt{};
	while (newWindow->pollEvent(evt))
	{
		if (evt.type == sf::Event::Closed) {
			newWindow->close();
		}
	}
}

void Application::fixedUpdate()
{
	for (auto item : allEntities) {
		if (item->has_activity() && item->tickEnabled())
		{
			item->on_fixed_update(pastTime);
		}
	}
}

void Application::update()
{
	for (GameObject* item : allEntities) {
		if (item->has_activity() && item->tickEnabled()) {
			item->on_update(pastTime);
		}
	}
}

void Application::updateGameTime()
{
	inGameTime = tm.getInGameTime();
	pastTime = GameTimeManager::calculatePastTime(inGameTime.asSeconds(), lastTime.asSeconds());
	lag = lag + pastTime;
	lastTime = inGameTime;
}


void Application::execute()
{
	lastTime = tm.getInGameTime();
	while (newWindow->isOpen())
	{
		updateGameTime();
		std::cout << "FPS:" << getFPS() << "\n";
		processWindowEvents();
		processInput();
		if (fixedUpdateEnabled)
		{
			while (lag < msForFixedUpdate)
			{
				fixedUpdate();
				lag = lag - msForFixedUpdate;
			}
		}

		update();
		draw();
		if (fpsLimitEnabled) sf::sleep(sf::seconds(1.0f / maxFPS));
	}

}