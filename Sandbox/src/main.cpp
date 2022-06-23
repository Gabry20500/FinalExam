#include <SFML/Graphics.hpp>

#include "Application.h"

int main() {

	Application* appli = new Application();
	appli->createWindow(1920, 1080, "SandBox");
	return 0;
}