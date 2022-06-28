#include "gameManager.h"

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::update(float DeltaTime)
{
	for (GameObject* item : allEntities)
	{
		if (item->isActive && item->tickEnabled()) item->on_update(DeltaTime);
	}
}
