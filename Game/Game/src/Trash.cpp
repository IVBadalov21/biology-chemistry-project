#include "../lib/Precompile.hpp"
#include "../lib/Trash.hpp"
//Draw trash bin
void Trash::draw(sf::RenderWindow& window)
{
	window.draw(this->trashSprite);
}
//Set bin position
void Trash::setPosition(sf::Vector2f position)
{
	this->trashSprite.setPosition(position);
}
//Set bin texture
void Trash::setTexture(sf::Texture& texture)
{
	this->trashSprite.setTexture(texture);
}
//Set bin value
void Trash::setValue(int value)
{
	this->value = value;
}