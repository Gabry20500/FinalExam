#ifndef CONTROLLERH
#define CONTROLLERH

#include <component.h>

#include <SFML/Graphics.hpp>

/// <summary>
/// Manage user input
/// </summary>
class Controller : public Component
{
public:
	Controller ();
	~Controller () override;
<<<<<<< Updated upstream
=======
	virtual void on_input(sf::Keyboard::Key input);
>>>>>>> Stashed changes

protected:
	void on_update(const float delta_time)override;
	void on_fixed_update(const float delta_time)override;
	virtual void on_input(sf::Keyboard::Key input[2]);
};
#endif 

