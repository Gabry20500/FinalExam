#ifndef RENDERER2D_H
#define RENDERER2D_H

#include "component.h"
#include "Classes/area2d.h"
#include "dll_header.h" 

#include <SFML/Graphics.hpp>

class DECLSPEC Render2d : public Component
{
public:
	Render2d();
	explicit Render2d(std::string path, bool smooth, bool repeat);
	~Render2d() override;

	void set_texture_source(std::string path, bool smooth, bool repeat);

private:
	sf::Texture* fount;
};
#endif