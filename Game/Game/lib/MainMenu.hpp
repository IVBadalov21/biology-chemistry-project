#include "Precompile.hpp"
#pragma once

class MainMenu {
public:
	void setTexture(sf::Texture& texture);
	void setButtons(sf::Texture& startTexture, sf::Texture& quitTexture);
	void draw(sf::RenderWindow& window);
	void handleButtons(sf::RenderWindow& window, bool& shouldWindowClose, bool& shouldMainMenuDisplay);

private:
	sf::Sprite mainMenuBackgroundSprite;
	sf::Sprite startButton;
	sf::Sprite quitButton;
};