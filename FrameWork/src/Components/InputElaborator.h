#ifndef INPUTELABORATOR_H
#define INPUTELABORATOR_H

#include "dll_header.h"
#include "component.h"
#include "controller.h"
#include "rect_transform.h"

class DECLSPEC InputElaboratorComponent : public Component
{
public:
	InputElaboratorComponent();
	~InputElaboratorComponent() override;

	float velocity;

	[[nodiscard]] bool motion_is_valid()const { return (input->forWardMove || input->rightMove); }

	[[nodiscard]] sf::Vector2f getVelocity() const;
	[[nodiscard]] sf::Vector2f getDirectionVect() const;

	void on_update(const float deltaTime) override;

	//component for manage input
	RectTransform* transform = nullptr; //game object transform
	Controller* input = nullptr;   

};
#endif // !INPUTELABORATOR_H

