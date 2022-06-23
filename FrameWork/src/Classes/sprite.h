#ifndef SPRITEH
#define SPIRTEH

#include "area2d.h"
#include "Components/render2d.h"

class Sprite : public Area2d
{
public:
	Sprite();
	~Sprite() override;

	Render2d* renderer;
};

#endif
