#ifndef INPUTELABORATOR_H
#define INPUTELABORATOR_H

#include "dll_header.h"
#include "component.h"
#include "controller.h"
#include "rect_transform.h"

#include <SFML/Graphics.hpp>

class DECLSPEC InputElaboratorComponent : public Component
{
public:
	InputElaboratorComponent();
	~InputElaboratorComponent();

	float velocity;

	sf::Vector2f getVelocity() const;
	sf::Vector2f getDirectionVect() const;

	void setXAxis(float x);
	void setyAxis(float y);

	//bool motionValid() const;
	//void on_update(const float deltaTime) override;

	//component for manage input
	//RectTransform* transform = nullptr; //game object transform
	//Controller* input = nullptr;   

protected:
	float xAxis = 0.0f, yAxis = 0.0f;
};
#endif // !INPUTELABORATOR_H

