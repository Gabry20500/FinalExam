#include "render2d.h"

#include <iostream>

Render2d::Render2d() : Component("Renderer 2D")
{
	source = nullptr;
}

Render2d::Render2d(std::string source_path, bool smooth, bool repeat) : Component("Renderer 2D")
{
	source = new sf::Texture();
	source->create(10, 10);
	if (!source->loadFromFile(source_path))
	{
		std::cout<<"Can't load texture at path "<< source_path.c_str()<< "\n";
		return;
	}
	source->setSmooth(smooth);
	source->setRepeated(repeat);

	const auto rect = get_owner()->get_component<RectTransform, RectTransform>();
	if (!rect)
	{
		printf("can't load rect transform from component owner\n");
		system("pause");
		return;
	}

	rect->get_transform()->setTexture(source);
}

Render2d::~Render2d()
{
}

void Render2d::set_texture_source(std::string source_path, bool smooth, bool repeat)
{

}
