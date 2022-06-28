#include "sprite.h"

Sprite::Sprite() : Area2d()
{
	rectTransform = new RectTransform();
	renderer = new Render2d();
	addComponent(renderer);
}

Sprite::~Sprite()
{
	delete rectTransform;
	delete renderer;
}
