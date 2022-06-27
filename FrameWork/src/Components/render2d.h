#ifndef RENDERER2D_H
#define RENDERER2D_H

#include "component.h"
#include "Components/rect_transform.h"
#include "Classes/game_object.h"
#include "dll_header.h" 

#include <SFML/Graphics.hpp>

class DECLSPEC Render2d : public Component
{
public:
	Render2d();
	explicit Render2d(std::string source_path, bool smooth, bool repeat);
	~Render2d() override;

	void set_texture_source(std::string source_path, bool smooth, bool repeat);

private:
	sf::Texture* source;
};
#endif