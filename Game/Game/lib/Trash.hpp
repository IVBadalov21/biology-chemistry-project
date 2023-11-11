#include "Precompile.hpp"
#pragma once

class Trash
{
public:
	void draw(sf::RenderWindow& window);
	void setPosition(sf::Vector2f position);
	void setTexture(sf::Texture& texture);
	void setValue(int value);

private:
	sf::Sprite trashSprite;
	int value = 0;
};