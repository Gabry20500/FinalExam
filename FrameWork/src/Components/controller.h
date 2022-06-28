#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "component.h"
#include "dll_header.h"

#include <SFML/Graphics.hpp>

/// <summary>
/// Manage user input
/// </summary>
class DECLSPEC Controller : public Component
{
	friend class GameManager;
	friend class InputElaborator;
public:
	Controller ();
	~Controller () override;

	[[nodiscard]] sf::Vector2f getAxisVector();
	
	bool rightMove = false;
	bool forWardMove = false;
protected:
	void on_update(const float delta_time)override;
	void on_fixed_update(const float delta_time)override;

private:
	float xAxis = 0.0f, yAxis = 0.0f;
};
#endif 

