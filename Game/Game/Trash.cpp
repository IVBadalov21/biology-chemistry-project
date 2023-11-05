#include "Precompile.hpp"

void Trash::draw(sf::RenderWindow& window)
{
	window.draw(this->trashSprite);

}

void Trash::setPosition(sf::Vector2f& position)
{
	this->position.x = position.x;
	this->position.y = position.y;
}

void Trash::setTexture(sf::Texture& texture)
{
	this->trashSprite.setTexture(texture);
}