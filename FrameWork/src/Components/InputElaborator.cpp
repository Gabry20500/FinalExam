#include "InputElaborator.h"

InputElaboratorComponent::InputElaboratorComponent() : Component("InputElaborator Component")
{
	velocity = 50;
}

InputElaboratorComponent::~InputElaboratorComponent()
{
	delete input;
	delete transform;
}

sf::Vector2f InputElaboratorComponent::getVelocity() const
{
	auto direction = input->getAxisVector();
	return {direction.x*velocity, direction.y * velocity};
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

void InputElaboratorComponent::on_update(const float deltaTime)
{
	if (!motion_is_valid()) return;

	auto nextPos = transform->get_transform()->getPosition() + sf::Vector2f(getDirectionVect().x * velocity * deltaTime, getDirectionVect().y * velocity * deltaTime);
	printf("%f, %f\n", nextPos.x, nextPos.y);
	transform->set_position(nextPos.x, nextPos.y);
}
