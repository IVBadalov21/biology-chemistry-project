#include "Precompile.hpp"
#include "Miscellanious.hpp"

void Misc::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

void Misc::setPosition(sf::Vector2f position)
{
	this->sprite.setPosition(position);
}

void Misc::draw(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}

void Misc::setScale(float scale = 1)
{
	sprite.setScale(scale, scale);
}