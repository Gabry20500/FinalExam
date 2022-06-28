#ifndef INPUTELABORATOR_H
#define INPUTELABORATOR_H

#include "dll_header.h"
#include "component.h"

class DECLSPEC InputElaboratorComponent : public Component
{
public:
	InputElaboratorComponent();
	~InputElaboratorComponent();

	float velocity;

	
};
#endif // !INPUTELABORATOR_H

