#include "InputElaborator.h"

InputElaboratorComponent::InputElaboratorComponent() : Component("InputElaborator Component")
{
	velocity = 50;
}

InputElaboratorComponent::~InputElaboratorComponent()
{
	//delete input;
	//delete transform;
}

sf::Vector2f InputElaboratorComponent::getVelocity() const
{
	return {xAxis*velocity, yAxis* velocity};
}

sf::Vector2f InputElaboratorComponent::getDirectionVect() const
{
	const auto velocityVect = getVelocity();
	const float length = sqrt(velocityVect.x * velocityVect.x + velocityVect.y * velocityVect.y);

	if (length == 0.0f) {
		return { 0,0 };
	}
	return { velocityVect.x / length, velocityVect.y / length };
}

void InputElaboratorComponent::setXAxis(float x)
{
	xAxis = x;
}

void InputElaboratorComponent::setyAxis(float y)
{
	yAxis = y;
}

/*bool InputElaboratorComponent::motionValid() const
{
	return false;
}

void InputElaboratorComponent::on_update(const float deltaTime)
{
}*/
