#include "../lib/Precompile.hpp"
#include "../lib/MainMenu.hpp"
//Set texture and size of main menu
void MainMenu::setTexture(sf::Texture& texture)
{
	this->mainMenuBackgroundSprite.setTexture(texture);
	this->mainMenuBackgroundSprite.setScale(0.75f, 0.75f);
}
//Set texture and properties of main menu buttons
void MainMenu::setButtons()
{
	//Set size, position and color of start button
	this->startButton.setSize(sf::Vector2f(480, 180));
	this->startButton.setPosition(sf::Vector2f(400, 120));
	this->startButton.setFillColor(sf::Color::Blue);
	//Set size, position and color of quit button
	this->quitButton.setSize(sf::Vector2f(480, 180));
	this->quitButton.setPosition(sf::Vector2f(400, 480));
	this->quitButton.setFillColor(sf::Color::Cyan);
	//Load button font
	this->font.loadFromFile("../Assets/Agbalumo-Regular.ttf");
	//Set properties and value of start button text
	this->startText.setFont(this->font);
	this->startText.setFillColor(sf::Color::White);
	this->startText.setCharacterSize(120);
	this->startText.setString("START");
	this->startText.setPosition(sf::Vector2f(460, 140));
	//Set properties and value of quit button text
	this->quitText.setFont(this->font);
	this->quitText.setFillColor(sf::Color::White);
	this->quitText.setCharacterSize(120);
	this->quitText.setString("QUIT");
	this->quitText.setPosition(sf::Vector2f(500, 500));
}
//Draw the main menu
void MainMenu::draw(sf::RenderWindow& window)
{
	window.clear();

	window.draw(this->mainMenuBackgroundSprite);
	window.draw(this->startButton);
	window.draw(this->quitButton);
	window.draw(this->startText);
	window.draw(this->quitText);

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