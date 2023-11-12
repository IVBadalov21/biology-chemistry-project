#include "../lib/Precompile.hpp"
#include "../lib/Money.hpp"
//Set money texture 
void Money::setTexture(sf::Texture& texture)
{
	sprite.setTexture(texture);
}
//Set money position 
void Money::setPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}
//Set money value 
void Money::setValue(float change)
{
	value += change;
}
//Get money texture 
int Money::getValue()
{
	return static_cast<int>(value);
}
//Set first upgrade cost
void Money::setCost1(float change)
{
	cost1 = change;
}
//Set second upgrade cost
void Money::setCost2(float change)
{
	cost2 = change;
}
//Set third upgrade cost
void Money::setCost3(float change)
{
	cost3 = change;
}