#ifndef SPRITE_H
#define SPIRTE_H

#include "area2d.h"
#include "dll_header.h" 
#include "Components/render2d.h"

class DECLSPEC Sprite : public Area2d
{
public:
	Sprite();
	~Sprite() override;

	Render2d* renderer;
};

#endif
