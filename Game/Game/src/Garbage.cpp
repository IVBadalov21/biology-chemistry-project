#include "../lib/Precompile.hpp"
#include "../lib/Garbage.hpp"
//Set texture of the garbage
void Garbage::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}
//Set position of the garbage
void Garbage::setPosition(sf::Vector2f position)
{
	this->sprite.setPosition(position);
}
//Set value of the garbage
void Garbage::setValue(int value)
{
	this->value = value;
}
//Draw the garbage
void Garbage::draw(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}
//Get garbage status
bool Garbage::getStatus()
{
	return this->isCollected;
}
//Set garbage status
void Garbage::setStatus(bool status)
{
	this->isCollected = status;
}