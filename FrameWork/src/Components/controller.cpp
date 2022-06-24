#include "controller.h"

#include <iostream>

Controller::Controller() : Component("Controller") { }

Controller::~Controller() = default;

void Controller::on_update(const float delta_time)
{
	Component::on_update(delta_time);
}

void Controller::on_fixed_update(const float delta_time)
{
	Component::on_fixed_update(delta_time);
}

void Controller::on_input(sf::Keyboard::Key input[2])
{
	if (input[0] != sf::Keyboard::Unknown) {
		std::cout << "Up/Down input\n";
	}
	else if (input[1] != sf::Keyboard::Unknown) {
		std::cout << "Left/Right input\n";
	}
}