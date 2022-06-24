#pragma once

#include <Classes/game_object.h>

#include <vector>
#include <SFML/Graphics.hpp>

class Application {

	friend class Controller;

public:
	Application() : newWindow(nullptr),
		maxFPS(0),
		fpsLimitEnabled(false),
		backgroundColor(sf::Color::Black) {
		initialize();
	}
	~Application(); 

	/// <summary>
	/// Create window for the application
	/// </summary>
	/// <param name="windowWidth">the window width</param>
	/// <param name="windowHeight">the window height</param>
	/// <param name="windowTitle">window main title</param>
	void createWindow(unsigned int Width, unsigned int Height, const char* Title);

	/// <summary>
	/// If the return is FALSE the window is open
	/// </summary>
	/// <returns> TRUE or FALSE</returns>
	bool isRunning()const;

	/// <summary>
	/// Execute game loop
	/// </summary>
	void run();

	/// <summary>
	/// Calculate the total frames in one seconds by elapsed time
	/// </summary>
	/// <returns>total frames</returns>
	unsigned getFrameRate()const;

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
	void setBackgroundColor(float red, float green, float blue, float alpha);

private:

	void initialize();
	void processInput();
	void draw();
	void processWindowEvents();
	void fixedUpdate();
	void update();
	void updateGameTime();

	sf::RenderWindow* newWindow;
	//TimeManager tm;
	sf::Time lastTime, currentTime;
	float elapsedTime;
	float lag;
	unsigned maxFPS;
	bool fpsLimitEnabled;
	bool fixedUpdateEnabled;
	float msForFixedUpdate;
	sf::Color backgroundColor;
	std::vector<GameObject*> allEntities;
};
