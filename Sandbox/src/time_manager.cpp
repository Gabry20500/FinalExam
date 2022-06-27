#include "time_manager.h"

sf::Time GameTimeManager::getInGameTime() const
{
	return clock.getElapsedTime();
}

float GameTimeManager::calculatePastTime(float currentTime, float lastTime)
{
	return currentTime- lastTime;
}
