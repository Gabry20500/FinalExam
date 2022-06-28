#include "game_object.h"

GameObject::GameObject(const std::string name, const bool is_active) : Object(name, is_active)
{
	this->userName = name;
	this->isActive = is_active;
}

GameObject::GameObject(const std::string name, const std::vector<Component*> components, const bool is_active) : Object(name, is_active)
{
	this->userName = name;
	this->components = components;
	this->isActive = is_active;
}

void GameObject::addComponent(Component* component)
{
	component->owner = this;
	components.push_back(component);
}

void GameObject::on_fixed_update(const float delta_time)
{
	for (auto item : components)
	{
		if (item->isActive && item->tickEnabled()) { item->on_fixed_update(delta_time); }
	}
}

void GameObject::on_update(const float delta_time)
{
	for (auto item : components)
	{
		if (item->isActive && item->tickEnabled()) { item->on_update(delta_time); }
	}
}
