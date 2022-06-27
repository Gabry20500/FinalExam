#include "render2d.h"
#include "Classes/area2d.h"

#include <iostream>

Render2d::Render2d() : Component("Renderer 2D")
{
	baseTexture = nullptr;
}

Render2d::Render2d(std::string basepath, bool smooth, bool repeat) : Component("Renderer 2D")
{
	baseTexture = new sf::Texture();
	baseTexture->create(10, 10);
	if (!baseTexture->loadFromFile(basepath))
	{
		std::cout<<"Can't load texture at path "<< basepath.c_str()<< "\n";
		return;
	}
	baseTexture->setSmooth(smooth);
	baseTexture->setRepeated(repeat);

	const auto rect = get_owner()->get_component<RectTransform, RectTransform>();
	if (!rect)
	{
		printf("can't load rect transform from component owner\n");
		system("pause");
		return;
	}

	rect->get_transform()->setTexture(baseTexture);
}

Render2d::~Render2d()
{
}

void Render2d::set_texture_source(std::string basepath, bool smooth, bool repeat)
{
<<<<<<< Updated upstream
=======
	delete baseTexture;
	baseTexture = new sf::Texture();
	if (!baseTexture->loadFromFile(basepath))
	{
		printf("Can't load texture int the path: %s \n", basepath.c_str());
		return;
	}
	
	baseTexture->setSmooth(smooth);
	baseTexture->setRepeated(repeat);

	const auto owner = dynamic_cast<Area2d*>(get_owner());
	if (!owner) {
		printf("Owner creation failed");
		system("pause");
		return;
	}

	owner->rectTransform->get_transform()->setTexture(baseTexture);
>>>>>>> Stashed changes
}
