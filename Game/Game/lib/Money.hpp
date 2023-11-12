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
	int upgrade3Level = 1;
	float moneyIncrease = 100;
	float cost1 = 30;
	float cost2 = 50;
	float cost3 = 100;
private:
	float value = 0;


	sf::Sprite sprite;
};