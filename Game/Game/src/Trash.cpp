#include "../lib/Precompile.hpp"
#include "../lib/Trash.hpp"
//Draw trash bin
void Trash::draw(sf::RenderWindow& window)
{
	window.draw(trashSprite);
}
//Set bin position
void Trash::setPosition(sf::Vector2f position)
{
	trashSprite.setPosition(position);
}
//Set bin texture
void Trash::setTexture(sf::Texture& texture)
{
	trashSprite.setTexture(texture);
}
//Set bin value
void Trash::setValue(int value)
{
	this->value = value;
}