#include "Precompile.hpp"
#pragma once

class Garbage {
public:
	void setTexture(sf::Texture& texture);
	void setPosition(sf::Vector2f position);
	void draw(sf::RenderWindow& window);
	void setValue(int value);
	void setStatus(bool status);
	bool getStatus();

private:
	sf::Sprite sprite;
	int value = 0;
	bool isCollected = false;
};
