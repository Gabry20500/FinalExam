#ifndef RECTTRANSFORMH
#define RECTTRANSFORMH

#include <component.h>
#include <SFML/Graphics.hpp>

/// <summary>
/// Set initial position, rotation and scale
/// </summary>
class RectTransform : public Component
{

public:
	RectTransform();
	explicit RectTransform(sf::Vector2f position, float rotation, sf::Vector2f scale);
	~RectTransform() override;

	/// <summary>
	/// Set position in world
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void set_position(float x, float y) const;

	/// <summary>
	/// Set position in world
	/// </summary>
	/// <param name="angle"></param>
	void set_rotation(float angle) const;


	/// <summary>
	/// Set size in pixel
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void set_scale(float x, float y) const;

	/*
	Get transform data
	*/
	[[nodiscard]] sf::RectangleShape* get_transform()const;

private:
	sf::Vector2f position;
	float rotation;
	sf::Vector2f scale;

	sf::RectangleShape* transform;
};

#endif
