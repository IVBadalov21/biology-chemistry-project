#include "Precompile.hpp"
#include "Background.hpp"

void Background::setTexture(sf::Texture& texture)
{
	this->backgroundSprite.setTexture(texture);
}

void Background::setSize()
{
	this->backgroundSprite.scale(0.75f, 0.75f);
}

void Background::draw(sf::RenderWindow& window)
{
	window.draw(this->backgroundSprite);
}