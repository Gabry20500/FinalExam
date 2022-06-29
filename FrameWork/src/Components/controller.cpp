#include "controller.h"


#include <iostream>

Controller::Controller() : Component("Controller") { 
	forWardMove = false;
	rightMove = true;
	xAxis = 0;
	yAxis = 0;
}

Controller::~Controller() = default;

void Controller::on_update(const float delta_time)
{
	Component::on_update(delta_time);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		forWardMove = true;
		yAxis = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		forWardMove = true;
		yAxis = 1;
	}
	else
	{
		forWardMove = false;
		yAxis = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rightMove = true;
		xAxis = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rightMove = true;
		xAxis = -1;
	}
	else
	{
		rightMove = false;
		xAxis = 0;
	}

	printf("%f, %f \n", xAxis, yAxis);
}

void Controller::on_fixed_update(const float delta_time)
{
	Component::on_fixed_update(delta_time);
}

sf::Vector2f Controller::getAxisVector()
{
	return {xAxis, yAxis};
}


