#include "Precompile.hpp"
#pragma once

class MainMenu {
public:
	void setTexture(sf::Texture& texture);
	void setButtons();
	void draw(sf::RenderWindow& window);
	void handleButtons(sf::RenderWindow& window, bool& shouldWindowClose, bool& shouldMainMenuDisplay);

private:
	sf::Sprite mainMenuBackgroundSprite;
	sf::RectangleShape startButton;
	sf::RectangleShape quitButton;
	sf::Font font;
	sf::Text startText;
	sf::Text quitText;
};