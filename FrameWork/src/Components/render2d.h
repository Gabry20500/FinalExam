#ifndef RENDERER2DH
#define RENDERER2DH

#include "component.h"
#include "Components/rect_transform.h"
#include "Classes/game_object.h"

#include <SFML/Graphics.hpp>

class Render2d : public Component
{
public:
	Render2d();
	explicit Render2d(std::string basepath, bool smooth, bool repeat);
	~Render2d() override;

	void set_texture_source(std::string basepath, bool smooth, bool repeat);

private:
	sf::Texture* baseTexture;
};
#endif