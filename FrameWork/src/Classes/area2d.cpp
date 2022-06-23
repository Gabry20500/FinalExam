#include "area2d.h"

Area2d::Area2d() : GameObject("Area 2D")
{
	rectTransform = new RectTransform();
	rectTransform->set_scale(32, 32);
	rectTransform->get_transform()->setFillColor(sf::Color::White);

	addComponent(rectTransform);
}

Area2d::~Area2d()
{
	delete rectTransform;
}
