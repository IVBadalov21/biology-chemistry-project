#include "../lib/Precompile.hpp"
#include "../lib/Miscellanious.hpp"
//Set texture of miscellanious elements 
void Misc::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}
//Set position of miscellanious elements 
void Misc::setPosition(sf::Vector2f position)
{
	this->sprite.setPosition(position);
}
//Draw miscellanious elements 
void Misc::draw(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}
//Set size of miscellanious elements 
void Misc::setScale(float scale = 1)
{
	sprite.setScale(scale, scale);
}