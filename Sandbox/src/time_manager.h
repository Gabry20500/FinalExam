#ifndef TIMEMANAGERH
#define TIMEMANAGERH

#include <SFML/System.hpp>

struct GameTimeManager
{
	GameTimeManager() {};
	virtual ~GameTimeManager() {};

	sf::Time getInGameTime()const;

	static float calculatePastTime(float currentTime, float lastTime);

private:
	sf::Clock clock;
};
#endif // !TIMEMANAGERH