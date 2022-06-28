#ifndef TIMEMANAGERH
#define TIMEMANAGERH

#include "dll_header.h"

#include <SFML/System.hpp>

struct DECLSPEC GameTimeManager
{
	GameTimeManager() {};
	virtual ~GameTimeManager() {};

	sf::Time getInGameTime()const;

	static float calculatePastTime(float currentTime, float lastTime);

private:
	sf::Clock clock;
};
#endif // !TIMEMANAGERH