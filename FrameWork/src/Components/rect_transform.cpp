#include "rect_transform.h"

RectTransform::RectTransform() : Component("RectTransform")
{
	disable();	// disables update and fixed update

	position = sf::Vector2f(900, 500);
	rotation = 0;
	scale = sf::Vector2f(1, 1);

	transform = new sf::RectangleShape(scale);
}

RectTransform::RectTransform(sf::Vector2f position, float rotation, sf::Vector2f scale) : Component("RectTransform")
{
	disable();	// disables update and fixed update

	this->position = position;
	this->rotation = rotation;
	this->scale = scale;

	transform = new sf::RectangleShape(scale);
}

RectTransform::~RectTransform()
{
	delete transform;
}

void RectTransform::set_position(float x, float y) const
{
	transform->setPosition(x, y);
}

void RectTransform::set_rotation(float angle) const
{
	transform->setRotation(angle);
}

void RectTransform::set_scale(float x, float y) const
{
	transform->setScale(x, y);
}

sf::RectangleShape* RectTransform::get_transform() const
{
	return transform;
}
