//Include project classes
#include "Application.h"

//Standart libraries
#include <iostream>
//SFML libraries
#include <SFML/Graphics.hpp>

Application::Application(const float Width, const float Height, const char* WindowTitle)
{
	newWindow = new sf::RenderWindow(sf::VideoMode(Width, Height), WindowTitle);
	maxFPS = 0;
	fpsLimitEnabled = false;
	backgroundColor = sf::Color::Black;
}

Application::~Application()
{
	delete newWindow;
}

unsigned Application::getFPS() const
{
	return 1/pastTime;
}

void Application::setMaxFPS(unsigned limit)
{
	this->maxFPS = limit;
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
	this->backgroundColor = color;
}

void Application::draw()
{
	newWindow->clear(backgroundColor);
	for each (auto item in gm.allEntities)
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
	while (this->newWindow->pollEvent(evt))
	{
		if (evt.type == sf::Event::EventType::Closed) {
			newWindow->close();
		}
	}
}

void Application::fixedUpdate()
{
	for (auto item : gm.allEntities)
	{
		if (item->isActive && item->tickEnabled()) item->on_fixed_update(pastTime);
	}
}

void Application::update()
{
	gm.update(this->pastTime);
}

void Application::updateGameTime()
{
	inGameTime = tm.getInGameTime();
	pastTime = GameTimeManager::calculatePastTime(inGameTime.asSeconds(), lastTime.asSeconds());
	lag += pastTime;
	lastTime = inGameTime;
}


void Application::execute()
{
	lastTime = tm.getInGameTime();
	while (newWindow->isOpen())
	{
		updateGameTime();
		std::cout << "FPS:" << getFPS() << "\n";
		std::cout << "Delta:" << pastTime << "\n";
		processWindowEvents();
		if (fixedUpdateEnabled)
		{
			while (lag < msForFixedUpdate)
			{
				fixedUpdate();
				lag -= msForFixedUpdate;
			}
		}

		update();
		draw();
		if (fpsLimitEnabled) 
		{
			sf::sleep(sf::seconds((1.0f / maxFPS)));
		}
	}

}