#include <Application.h>
#include <string.h>
#include <iostream>
#include <Classes/guidableCharacter.h>

int main()
{

	Application* mywindow = new Application(1920, 1080, "Sandbox");
	mywindow->setMaxFPS(120);
	mywindow->disableFixedUpdate();
	mywindow->enableFPSLimit();

	auto background = new Sprite();
	background->renderer->set_texture_source("Textures/Sala Principale.jpg", true, true);
	background->rectTransform->set_scale(1920, 1080);
	mywindow->gm.allEntities.push_back(background);

	GuidableCharacter* player = new GuidableCharacter();
	player->renderer->set_texture_source("Textures/Arcon.png", true, false);
	player->rectTransform->set_scale(64, 64);
	player->rectTransform->set_position(960 - 32, 540 - 32);
	mywindow->gm.allEntities.push_back(player);

	mywindow->execute();
	return 0;

}