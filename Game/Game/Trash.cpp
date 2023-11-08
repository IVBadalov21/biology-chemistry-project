#include "Precompile.hpp"
#include "Trash.hpp"
void Trash::draw(sf::RenderWindow& window)
{
	window.draw(this->trashSprite);
}

void Trash::setPosition(sf::Vector2f position)
{
	this->trashSprite.setPosition(position);
}

void Trash::setTexture(sf::Texture& texture)
{
	this->trashSprite.setTexture(texture);
}

void Trash::setValue(int value)
{
	this->value = value;
}