#include "../lib/Precompile.hpp"
#include "../lib/Money.hpp"
//Set money texture 
void Money::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}
//Set money position 
void Money::setPosition(sf::Vector2f position)
{
	this->sprite.setPosition(position);
}
//Set money value 
void Money::setValue(float change)
{
	this->value += change;
}
//Get money texture 
int Money::getValue()
{
	return static_cast<int>(this->value);
}
//Set first upgrade cost
void Money::setCost1(float change)
{
	this->cost1 = change;
	upgrade1Level++;
}
//Set second upgrade cost
void Money::setCost2(float change)
{
	this->cost2 = change;
	upgrade2Level++;
}
//Set third upgrade cost
void Money::setCost3(float change)
{
	this->cost3 = change;
	upgrade3Level++;
}