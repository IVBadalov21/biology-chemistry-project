#include "Precompile.hpp"
#pragma once

class Misc
{
public:
	void setTexture(sf::Texture& texture);
	void setPosition(sf::Vector2f position);
	void draw(sf::RenderWindow& window);
	void setScale(float scale);
private:

	sf::Sprite sprite;
};