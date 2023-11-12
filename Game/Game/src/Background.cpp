#include "../lib/Precompile.hpp"
#include "../lib/Background.hpp"
//Set texture of the background
void Background::setTexture(sf::Texture& texture)
{
	backgroundSprite.setTexture(texture);
}
//Set size of the background
void Background::setSize()
{
	backgroundSprite.scale(0.75f, 0.75f);
}
//Draw the background
void Background::draw(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);
}