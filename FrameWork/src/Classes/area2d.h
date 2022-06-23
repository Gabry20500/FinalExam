#ifndef AREA2DH
#define AREA2DH

#include "game_object.h"
#include "Components/rect_transform.h"

class Area2d : public GameObject
{
public:
	Area2d();
	~Area2d() override;

	RectTransform* rectTransform;
};
#endif