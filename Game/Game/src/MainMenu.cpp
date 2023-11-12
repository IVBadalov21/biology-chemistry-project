#include "../lib/Precompile.hpp"
#include "../lib/MainMenu.hpp"
//Set texture and size of main menu
void MainMenu::setTexture(sf::Texture& texture)
{
	this->mainMenuBackgroundSprite.setTexture(texture);
	this->mainMenuBackgroundSprite.setScale(0.75f, 0.75f);
}
//Set texture and properties of main menu buttons
void MainMenu::setButtons(sf::Texture& startTexture, sf::Texture& quitTexture)
{
	//Set size, position and color of start button
	this->startButton.setPosition(sf::Vector2f(400, 120));
	this->startButton.setTexture(startTexture);
	//Set size, position and color of quit button
	this->quitButton.setPosition(sf::Vector2f(400, 480));
	this->quitButton.setTexture(quitTexture);
}
//Draw the main menu
void MainMenu::draw(sf::RenderWindow& window)
{
	window.clear();

	window.draw(this->mainMenuBackgroundSprite);
	window.draw(this->startButton);
	window.draw(this->quitButton);
	
	window.display();
}
//Handling button interactions
void MainMenu::handleButtons(sf::RenderWindow& window, bool& shouldWindowClose, bool& shouldMainMenuDisplay)
{
	//Handling start button interaction
	if ((sf::Mouse::getPosition(window).x > 400 && sf::Mouse::getPosition(window).x < 880 && sf::Mouse::getPosition(window).y > 120 && sf::Mouse::getPosition(window).y < 300) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		shouldMainMenuDisplay = false;
	}
	//Handling quit button interaction
	if ((sf::Mouse::getPosition(window).x > 400 && sf::Mouse::getPosition(window).x < 880 && sf::Mouse::getPosition(window).y > 480 && sf::Mouse::getPosition(window).y < 660) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		shouldWindowClose = true;
	}
}