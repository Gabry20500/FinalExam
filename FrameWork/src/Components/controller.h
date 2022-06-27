#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <component.h>

#include <SFML/Graphics.hpp>
#include "dll_header.h" 

/// <summary>
/// Manage user input
/// </summary>
class DECLSPEC Controller : public Component
{ 
public:
	Controller ();
	~Controller () override;
<<<<<<< Updated upstream
	virtual void on_input(sf::Keyboard::Key input[2]);
=======
>>>>>>> Stashed changes

protected:
	void on_update(const float delta_time)override;
	void on_fixed_update(const float delta_time)override;
	
};
#endif 

