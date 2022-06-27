#include "Application.h"

int main() {

	Application* appli = new Application();
	appli->createWindow(1920, 1080, "SandBox");
	appli->setMaxFPS(60);
	appli->enableFPSLimit();
	appli->disableFixedUpdate();
	appli->execute();
	return 0;
}