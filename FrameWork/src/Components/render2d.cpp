#include "render2d.h"
#include <Classes/area2d.h>

#include <iostream>

Render2d::Render2d() : Component("Renderer 2D")
{
	fount = nullptr;
}

Render2d::Render2d(std::string path, bool smooth, bool repeat) : Component("Renderer 2D")
{
	fount = new sf::Texture();
	fount->create(10, 10);
	if (!fount->loadFromFile(path))
	{
		std::cout<<"Can't load texture at path "<< path.c_str()<< "\n";
		return;
	}
	fount->setSmooth(smooth);
	fount->setRepeated(repeat);

	const auto rect = get_owner()->get_component<RectTransform, RectTransform>();
	if (!rect)
	{
		printf("can't load rect transform from component owner\n");
		system("pause");
		return;
	}

	rect->get_transform()->setTexture(fount);
}

Render2d::~Render2d()
{
	delete fount;
}

void Render2d::set_texture_source(std::string path, bool smooth, bool repeat)
{
	delete fount;
	fount = new sf::Texture();
	if (!fount->loadFromFile(path)) {
		printf("Path loading error [%S]\n", path.c_str());
		return;
	}

	fount->setSmooth(smooth);
	fount->setRepeated(repeat);

	const auto keeper = dynamic_cast<Area2d*>(get_owner());
	if (!keeper) {
		printf("Owner not found\n");
		return;
	}

	keeper->rectTransform->get_transform()->setTexture(fount);
}
