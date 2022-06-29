#include "object.h"

#include <iostream>

Object::Object(const std::string user_Name, bool active)
{
	this->userName = user_Name;
	this->isActive = active;
}
