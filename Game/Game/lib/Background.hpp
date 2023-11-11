#include "Precompile.hpp"
#pragma once


class Background {
public:
	void setTexture(sf::Texture& texture);
	void setSize();
	void draw(sf::RenderWindow& window);

private:
	sf::Sprite backgroundSprite;
};