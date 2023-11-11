#include "../lib/Precompile.hpp"
#include "../lib/Money.hpp"

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
	return static_cast<int>(this->value);
}

void Money::setCost1(float change)
{
	this->cost1 = change;
	upgrade1Level++;
}

void Money::setCost2(float change)
{
	this->cost2 = change;
	upgrade2Level++;
}

void Money::setCost3(float change)
{
	this->cost3 = change;
	upgrade3Level++;
}