#ifndef CHARACTER_H
#define CHARACTER_H

#include "Classes/sprite.h"
#include "Components/controller.h"
#include "Components/InputElaborator.h"

class DECLSPEC GuidableCharacter : public Sprite 
{
public:
	GuidableCharacter();
	~GuidableCharacter() override;

protected:
	void on_fixed_update(const float delta_time)override;
	void on_update(const float delta_time)override;

public:
	Controller* contrComp;
	InputElaboratorComponent* inputManager;

};
#endif // !CHARACTER_H
