#include "Precompile.hpp"
#pragma once

class Trash
{
public:
	void draw(sf::RenderWindow& window);
	void setPosition(sf::Vector2f& position);
	void setTexture(sf::Texture& texture);
	
private:
	sf::Texture trashTexture;
	sf::Sprite trashSprite;
	sf::Vector2u position;
	int value;
};