#include "guidableCharacter.h"

GuidableCharacter::GuidableCharacter(): Sprite()
{
	contrComp = new Controller();
	addComponent(contrComp);

	inputManager = new InputElaboratorComponent();
	inputManager->input = contrComp;
	inputManager->transform = rectTransform;
	inputManager->velocity = 200.0f;
	addComponent(inputManager);
}

GuidableCharacter::~GuidableCharacter()
{
	delete contrComp;
	delete inputManager;
}

void GuidableCharacter::on_fixed_update(const float delta_time)
{
	Sprite::on_fixed_update(delta_time);
}

void GuidableCharacter::on_update(const float delta_time)
{
	Sprite::on_update(delta_time);
}
