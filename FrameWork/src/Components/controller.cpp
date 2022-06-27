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

void Controller::on_input(sf::Keyboard::Key input)
{
	if (input != sf::Keyboard::Unknown) {
		if (input == sf::Keyboard::A || input == sf::Keyboard::Left) {
			std::cout << "Left input\n";
		}
		else if (input == sf::Keyboard::D || input == sf::Keyboard::Right) {
			std::cout << "Right input\n";
		}else if (input == sf::Keyboard::W || input == sf::Keyboard::Up) {
			std::cout << "Up input\n";
		}
		else if (input == sf::Keyboard::S || input == sf::Keyboard::Down) {
			std::cout << "Down input\n";
		}
	}
}
