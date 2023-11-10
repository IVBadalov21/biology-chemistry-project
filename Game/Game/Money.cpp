#include "Precompile.hpp"
#include "Money.hpp"

void Money::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

void Money::setPosition(sf::Vector2f position)
{
	this->sprite.setPosition(position);
}

void Money::setValue(float change)
{
	this->value += change;
}

int Money::getValue()
{
	return this->value;
}

void Money::setCost1(float change)
{
	this->cost1 += change * this->upgrade1Level;
	upgrade1Level++;
}

void Money::setCost2(float change)
{
	this->cost2 += change * this->upgrade2Level;
	upgrade2Level++;
}

void Money::setCost3(float change)
{
	this->cost3 += change * this->upgrade3Level;
	upgrade3Level++;
}