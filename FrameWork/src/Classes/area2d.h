#ifndef AREA2D_H
#define AREA2D_H

#include "game_object.h"
#include "Components/rect_transform.h"
#include "dll_header.h" 

class DECLSPEC Area2d : public GameObject
{
public:
	Area2d();
	~Area2d() override;

	RectTransform* rectTransform;
};
#endif