#include "../lib/Precompile.hpp"
#include "../lib/MainMenu.hpp"
//Set texture and size of main menu
void MainMenu::setTexture(sf::Texture& texture)
{
	mainMenuBackgroundSprite.setTexture(texture);
	mainMenuBackgroundSprite.setScale(0.75f, 0.75f);
}
//Set texture and properties of main menu buttons
void MainMenu::setButtons(sf::Texture& startTexture, sf::Texture& quitTexture)
{
	//Set size, position and color of start button
	startButton.setPosition(sf::Vector2f(460, 240));
	startButton.setTexture(startTexture);
	//Set size, position and color of quit button
	quitButton.setPosition(sf::Vector2f(460, 400));
	quitButton.setTexture(quitTexture);
}
//Draw the main menu
void MainMenu::draw(sf::RenderWindow& window)
{
	window.clear();

	window.draw(mainMenuBackgroundSprite);
	window.draw(startButton);
	window.draw(quitButton);
	
	window.display();
}
//Handling button interactions
void MainMenu::handleButtons(sf::RenderWindow& window, bool& shouldWindowClose, bool& shouldMainMenuDisplay)
{
	//Handling start button interaction
	if ((sf::Mouse::getPosition(window).x >= 460 && sf::Mouse::getPosition(window).x <= 820 && sf::Mouse::getPosition(window).y >= 240 && sf::Mouse::getPosition(window).y <= 375) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		shouldMainMenuDisplay = false;
	}
	//Handling quit button interaction
	if ((sf::Mouse::getPosition(window).x >= 460 && sf::Mouse::getPosition(window).x <= 820 && sf::Mouse::getPosition(window).y >= 400 && sf::Mouse::getPosition(window).y <= 535) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		shouldWindowClose = true;
	}
}