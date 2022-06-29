#ifndef APPLICATION_H
#define APPLICATION_H

#include "time_manager.h"
#include "Classes/game_object.h"
#include "Components/rect_transform.h"
#include "gameManager.h"
#include "Components/InputElaborator.h"
#include "dll_header.h"

#include <vector>
#include <SFML/Graphics.hpp>

class DECLSPEC Application 
{
public:
	Application(const float Width, const float Height, const char* WindowTitle);
	~Application();

	/// <summary>
	/// Execute game loop
	/// </summary>
	void execute();

	/// <summary>
	/// Calculate the total frames in one seconds by elapsed time
	/// </summary>
	/// <returns>total frames</returns>
	unsigned getFPS()const;

	/// <summary>
	/// Set the maximum number of FPS reachable
	/// </summary>
	/// <param name="limit"></param>
	void setMaxFPS(unsigned limit);

	/// <summary>
	/// Enabled/Disable the FPS limit
	/// </summary>
	void enableFPSLimit();
	void disableFPSLimit();

	/// <summary>
	/// Enable/Disable fixed update
	/// </summary>
	void enableFixedUpdate();
	void disableFixedUpdate();


	/// <summary>
	/// Set milliseconds for fixed update
	/// </summary>
	/// <param name="milliseconds"></param>
	void setMillisecondsForFixedUpdate(float milliseconds);

	/// <summary>
	/// Set the color for the background
	/// </summary>
	/// <param name="color"></param>
	void setBackgroundColor(sf::Color color);

	GameManager gm;

private:

	void draw();
	void processWindowEvents();
	void fixedUpdate();
	void update();
	void updateGameTime();

	sf::RenderWindow* newWindow;
	unsigned maxFPS;
	bool fpsLimitEnabled;
	bool fixedUpdateEnabled;

	GameTimeManager tm;
	sf::Time lastTime, inGameTime;

	float pastTime;
	float lag;
	
	float msForFixedUpdate;
	sf::Color backgroundColor;
};

#endif // !APPLICATION_H




