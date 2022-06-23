#include "component.h"
#include <iostream>

void Component::on_update(const float delta_time)
{
	std::cout << "componente update\n";
}

void Component::on_fixed_update(const float delta_time)
{
}
