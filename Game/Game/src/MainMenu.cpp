#include "../lib/Precompile.hpp"
#include "../lib/MainMenu.hpp"

void MainMenu::setTexture(sf::Texture& texture)
{
	this->mainMenuBackgroundSprite.setTexture(texture);
	this->mainMenuBackgroundSprite.setScale(0.75f, 0.75f);
}

void MainMenu::setButtons()
{
	this->startButton.setSize(sf::Vector2f(480, 180));
	this->startButton.setPosition(sf::Vector2f(400, 120));
	this->startButton.setFillColor(sf::Color::Blue);

	this->quitButton.setSize(sf::Vector2f(480, 180));
	this->quitButton.setPosition(sf::Vector2f(400, 480));
	this->quitButton.setFillColor(sf::Color::Cyan);

	this->font.loadFromFile("../Assets/Agbalumo-Regular.ttf");

	this->startText.setFont(this->font);
	this->startText.setFillColor(sf::Color::White);
	this->startText.setCharacterSize(120);
	this->startText.setString("START");
	this->startText.setPosition(sf::Vector2f(460, 140));

	this->quitText.setFont(this->font);
	this->quitText.setFillColor(sf::Color::White);
	this->quitText.setCharacterSize(120);
	this->quitText.setString("QUIT");
	this->quitText.setPosition(sf::Vector2f(500, 500));
}

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

void MainMenu::handleButtons(sf::RenderWindow& window, bool& shouldWindowClose, bool& shouldMainMenuDisplay)
{
	if ((sf::Mouse::getPosition(window).x > 400 && sf::Mouse::getPosition(window).x < 880 && sf::Mouse::getPosition(window).y > 120 && sf::Mouse::getPosition(window).y < 300) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		shouldMainMenuDisplay = false;
	}

	if ((sf::Mouse::getPosition(window).x > 400 && sf::Mouse::getPosition(window).x < 880 && sf::Mouse::getPosition(window).y > 480 && sf::Mouse::getPosition(window).y < 660) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		shouldWindowClose = true;
	}
}