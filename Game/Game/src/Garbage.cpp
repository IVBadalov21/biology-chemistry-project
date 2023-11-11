#include "../lib/Precompile.hpp"
#include "../lib/Garbage.hpp"

void Garbage::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

void Garbage::setPosition(sf::Vector2f position)
{
	this->sprite.setPosition(position);
}

void Garbage::setValue(int value)
{
	this->value = value;
}

void Garbage::draw(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}

bool Garbage::getStatus()
{
	return this->isCollected;
}

void Garbage::setStatus(bool status)
{
	this->isCollected = status;
}