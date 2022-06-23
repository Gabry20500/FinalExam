#include "sprite.h"

Sprite::Sprite() : Area2d()
{
	renderer = new Render2d();
	addComponent(renderer);
}

Sprite::~Sprite()
{
	delete rectTransform;
	delete renderer;
}
