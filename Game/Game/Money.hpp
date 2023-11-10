#include "Precompile.hpp"
#pragma once

class Money
{
public:
	void setTexture(sf::Texture& texture);
	void setValue(float change);
	void setPosition(sf::Vector2f position);
	void setCost1(float change);
	void setCost2(float change);
	void setCost3(float change);
	int getValue();

	int upgrade1Level = 0;
	int upgrade2Level = 0;
	int upgrade3Level = 0;
	int moneyIncrease = 10;
	float cost1;
	float cost2;
	float cost3;
private:
	int value;
	

	sf::Sprite sprite;
};