#include "../lib/Precompile.hpp"
#include "../lib/Trash.hpp"
#include "../lib/Game.hpp"

Game::Game()
{
	//Create window and set the framerate
	window.create(sf::VideoMode(1280, 720), "Game"/*, sf::Style::Fullscreen*/);
	window.setFramerateLimit(60);
	garbageCooldown = 300;
	//Load game textures
	buttonOneTexture.loadFromFile("../Assets/one_button.png");
	buttonTwoTexture.loadFromFile("../Assets/two_button.png");
	buttonThreeTexture.loadFromFile("../Assets/three_button.png");
	moneyTexture.loadFromFile("../Assets/coins.png");
	startTexture.loadFromFile("../Assets/start_button.png");
	quitTexture.loadFromFile("../Assets/exiting_button.png");
	mainMenuTexture.loadFromFile("../Assets/cloud_back.png");
	blueTrashBinTexture.loadFromFile("../Assets/sin_kosh.png");
	yellowTrashBinTexture.loadFromFile("../Assets/jult_kosh.png");
	greenTrashBinTexture.loadFromFile("../Assets/zelen_kosh.png");
	glassTexture.loadFromFile("../Assets/glass.png");
	cardboardTexture.loadFromFile("../Assets/box.png");
	plasticTexture.loadFromFile("../Assets/plastic.png");
	backgroundTexture1.loadFromFile("../Assets/background.png");
	backgroundTexture2.loadFromFile("../Assets/background_cloud.png");
	backgroundTexture3.loadFromFile("../Assets/background_three.png");
	backgroundTexture4.loadFromFile("../Assets/background_flowers.png");
	finishScreenTexture.loadFromFile("../Assets/cloud_back.png");
	font.loadFromFile("../Assets/Agbalumo-Regular.ttf");

	trashBinTextures = {
		{1, blueTrashBinTexture},
		{2, yellowTrashBinTexture},
		{3, greenTrashBinTexture}
	};

	garbageTextures = {
		{1, cardboardTexture},
		{2, plasticTexture},
		{3, glassTexture}
	};

	backgroundTextures = {
		{1, backgroundTexture1},
		{2, backgroundTexture2},
		{3, backgroundTexture3},
		{4, backgroundTexture4}
	};
	//Set the texture of the main menu
	mainMenu.setTexture(mainMenuTexture);
	mainMenu.setButtons(startTexture, quitTexture);
	//Set the cooldown text
	cooldownText.setFont(font);
	cooldownText.setFillColor(sf::Color::White);
	cooldownText.setCharacterSize(120);
	cooldownText.setPosition(sf::Vector2f(580, 240));
	//Set textures of miscellanious elements
	misc[0].setTexture(moneyTexture);
	misc[0].setPosition(sf::Vector2f(960, 160));

	misc[1].setTexture(blueTrashBinTexture);
	misc[1].setPosition(sf::Vector2f(20, 140));
	misc[1].setScale(0.5f);

	misc[2].setTexture(yellowTrashBinTexture);
	misc[2].setPosition(sf::Vector2f(20, 220));
	misc[2].setScale(0.5f);

	misc[3].setTexture(greenTrashBinTexture);
	misc[3].setPosition(sf::Vector2f(20, 300));
	misc[3].setScale(0.5f);

	misc[4].setTexture(cardboardTexture);
	misc[4].setPosition(sf::Vector2f(80, 140));
	misc[4].setScale(0.5f);

	misc[5].setTexture(plasticTexture);
	misc[5].setPosition(sf::Vector2f(80, 220));
	misc[5].setScale(0.5f);

	misc[6].setTexture(glassTexture);
	misc[6].setPosition(sf::Vector2f(80, 300));
	misc[6].setScale(0.5f);

	misc[7].setTexture(moneyTexture);
	misc[7].setPosition(sf::Vector2f(1160, 310));

	misc[8].setTexture(moneyTexture);
	misc[8].setPosition(sf::Vector2f(1160, 360));

	misc[9].setTexture(moneyTexture);
	misc[9].setPosition(sf::Vector2f(1140, 410));

	misc[10].setTexture(buttonOneTexture);
	misc[10].setPosition(sf::Vector2f(850, 310));
	misc[10].setScale(0.25f);

	misc[11].setTexture(buttonTwoTexture);
	misc[11].setPosition(sf::Vector2f(850, 360));
	misc[11].setScale(0.25f);

	misc[12].setTexture(buttonThreeTexture);
	misc[12].setPosition(sf::Vector2f(850, 410));
	misc[12].setScale(0.25f);
	//Set the money text
	moneyText.setFont(font);
	moneyText.setFillColor(sf::Color::White);
	moneyText.setCharacterSize(32);
	moneyText.setPosition(sf::Vector2f(1000, 150));
	//Set text for upgrade 1
	upgrade1Text.setFont(font);
	upgrade1Text.setFillColor(sf::Color::White);
	upgrade1Text.setCharacterSize(32);
	upgrade1Text.setPosition(sf::Vector2f(890, 300));
	//Set text for upgrade 2
	upgrade2Text.setFont(font);
	upgrade2Text.setFillColor(sf::Color::White);
	upgrade2Text.setCharacterSize(32);
	upgrade2Text.setPosition(sf::Vector2f(890, 350));
	//Set text for upgrade 3
	upgrade3Text.setFont(font);
	upgrade3Text.setFillColor(sf::Color::White);
	upgrade3Text.setCharacterSize(32);
	upgrade3Text.setPosition(sf::Vector2f(890, 400));
	//Set first text of finish screen
	finishScreenText1.setFont(font);
	finishScreenText1.setFillColor(sf::Color::White);
	finishScreenText1.setCharacterSize(60);
	finishScreenText1.setPosition(sf::Vector2f(120, 400));
	finishScreenText1.setString("Congratilations, you finished the game");
	//Set second text of finish screen
	finishScreenText2.setFont(font);
	finishScreenText2.setFillColor(sf::Color::White);
	finishScreenText2.setCharacterSize(60);
	finishScreenText2.setPosition(sf::Vector2f(300, 600));
	finishScreenText2.setString("Press Esc to close the game");
	//Set blue trash bin texture
	blueTrashBin.setTexture(trashBinTextures[1]);
	blueTrashBin.setPosition(sf::Vector2f(340, 480));
	blueTrashBin.setValue(1);
	//Set yellow trash bin texture
	yellowTrashBin.setTexture(trashBinTextures[2]);
	yellowTrashBin.setPosition(sf::Vector2f(580, 480));
	yellowTrashBin.setValue(2);
	//Set green trash bin texture
	greenTrashBin.setTexture(trashBinTextures[3]);
	greenTrashBin.setPosition(sf::Vector2f(820, 480));
	greenTrashBin.setValue(3);
	//Set background texture
	background.setTexture(backgroundTextures[1]);
	background.setSize();

	finishScreen.setTexture(finishScreenTexture);
	//Spawn initial garbage
	garbageShouldDraw = true;
	garbage.setValue(getRandomGarbage());

	update();
}
//Display ythings on the window
void Game::displayWindow()
{
	window.clear();

	background.draw(window);

	blueTrashBin.draw(window);
	yellowTrashBin.draw(window);
	greenTrashBin.draw(window);

	if (garbageShouldDraw)
		garbage.draw(window);
	else
		window.draw(cooldownText);

	misc[0].draw(window);
	window.draw(moneyText);

	misc[1].draw(window);
	misc[2].draw(window);
	misc[3].draw(window);
	misc[4].draw(window);
	misc[5].draw(window);
	misc[6].draw(window);
	misc[7].draw(window);
	misc[8].draw(window);
	misc[9].draw(window);
	misc[10].draw(window);
	misc[11].draw(window);
	misc[12].draw(window);

	window.draw(upgrade1Text);
	window.draw(upgrade2Text);
	window.draw(upgrade3Text);

	window.display();
}
//Handle program runtime
void Game::update()
{
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || shouldWindowClose)
			{
				window.close();
			}
			else
			{
				if (event.type == sf::Event::KeyPressed && !shouldMainMenuDisplay)
				{
					processKeyPressed();
				}
			}
		}
		if (shouldMainMenuDisplay)
		{
			mainMenu.handleButtons(window, shouldWindowClose, shouldMainMenuDisplay);
			mainMenu.draw(window);
		}
		else
		{
			if (shouldFinishScreenDisplay)
			{
				displayFinishWindow();
			}
			else
			{
				handleText();
				displayWindow();
				garbageLogic();
			}
		}

	}
}
//Load random garbage
int Game::getRandomGarbage()
{
	std::random_device generator;
	std::uniform_int_distribution<int> garbageValueGen(1, 3);
	return garbageValueGen(generator);
}
//Handle garbage pickup, spawn, despawn and money increase
void Game::garbageLogic()
{
	//Start garbage movement
	if ((sf::Mouse::getPosition(window).x > 580 && sf::Mouse::getPosition(window).x < 700 && sf::Mouse::getPosition(window).y > 300 && sf::Mouse::getPosition(window).y < 420) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		isGarbageFollowingMouse = true;
	}

	if (isGarbageFollowingMouse)
	{
		garbage.setPosition(sf::Vector2f(sf::Mouse::getPosition(window).x - 60.f, sf::Mouse::getPosition(window).y - 60.f));
	}
	//Check for garbage to trash bin
	switch (garbageValue)
	{
		//Check for garbage on the blue bin
	case 1:
		if ((sf::Mouse::getPosition(window).x > 340 && sf::Mouse::getPosition(window).x < 460 && sf::Mouse::getPosition(window).y >480 && sf::Mouse::getPosition(window).y < 600) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && isGarbageFollowingMouse)
		{
			garbageShouldDraw = false;
			isClockAlreadyRestarted = false;
			garbage.setStatus(true);
			isGarbageFollowingMouse = false;
			money.setValue(money.moneyIncrease);
		}
		break;
		//Check for garbage on the yellow bin
	case 2:
		if ((sf::Mouse::getPosition(window).x > 580 && sf::Mouse::getPosition(window).x < 700 && sf::Mouse::getPosition(window).y >480 && sf::Mouse::getPosition(window).y < 600) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && isGarbageFollowingMouse)
		{
			garbageShouldDraw = false;
			isClockAlreadyRestarted = false;
			garbage.setStatus(true);
			isGarbageFollowingMouse = false;
			money.setValue(money.moneyIncrease);
		}
		break;
		//Check for garbage on green bin
	case 3:
		if ((sf::Mouse::getPosition(window).x > 820 && sf::Mouse::getPosition(window).x < 1000 && sf::Mouse::getPosition(window).y >480 && sf::Mouse::getPosition(window).y < 600) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && isGarbageFollowingMouse)
		{
			garbageShouldDraw = false;
			isClockAlreadyRestarted = false;
			garbage.setStatus(true);
			isGarbageFollowingMouse = false;
			money.setValue(money.moneyIncrease);
		}
		break;
	}
	//Set garbage status
	if (garbage.getStatus())
	{
		if (!isClockAlreadyRestarted)
		{
			garbageCounter = garbageCooldown;
			isClockAlreadyRestarted = true;
		}
	}
	//Allow garbage to respawn
	if (garbage.getStatus() && garbageCounter == 0)
	{
		garbage.setStatus(false);
		garbageShouldDraw = true;
		isAlreadyChanged = false;
	}
	//Set garbage properties for respawn
	if (!garbage.getStatus() && !isAlreadyChanged)
	{
		garbageValue = getRandomGarbage();
		garbage.setTexture(garbageTextures[garbageValue]);
		garbage.setPosition(sf::Vector2f(580, 300));
		garbage.setValue(garbageValue);
		isAlreadyChanged = true;
	}
}
//Process pressing of keys
void Game::processKeyPressed()
{
	if (event.key.code == sf::Keyboard::Num1)
	{
		if (money.getValue() >= money.cost1)
		{
			upgrade1();
		}
	}
	if (event.key.code == sf::Keyboard::Num2)
	{
		if (money.getValue() >= money.cost2)
		{
			upgrade2();
		}
	}
	if (event.key.code == sf::Keyboard::Num3)
	{
		if (money.getValue() >= money.cost3)
		{
			upgrade3();
		}
	}
	if (event.key.code == sf::Keyboard::Escape)
	{
		if (shouldFinishScreenDisplay)
		{
			shouldWindowClose = true;
		}
		else
		{
			shouldMainMenuDisplay = true;
		}
	}
}
//Handling of the first upgrade
void Game::upgrade1()
{
	money.setValue(-money.cost1);
	money.upgrade1Level++;
	money.setCost1(money.cost1 * (1 + (0.1f * money.upgrade1Level)));
	money.moneyIncrease += 20;
}
//Handling of the second upgrade 
void Game::upgrade2()
{
	money.setValue(-money.cost2);
	money.upgrade2Level++;
	money.setCost2(money.cost2 * (1 + (0.1f * money.upgrade2Level)));
	garbageCooldown -= 60;
	if (garbageCooldown < 0) {
		garbageCooldown = 0;
	}
}
//Handling of the third upgrade
void Game::upgrade3()
{
	money.setValue(-money.cost3);
	money.upgrade3Level++;
	money.setCost3(100 * money.upgrade3Level);
	if (money.upgrade3Level == 2)
		background.setTexture(backgroundTextures[2]);
	if (money.upgrade3Level == 3)
		background.setTexture(backgroundTextures[3]);
	if (money.upgrade3Level == 4)
		background.setTexture(backgroundTextures[4]);
	if (money.upgrade3Level > 4)
		shouldFinishScreenDisplay = true;
}
//Handling of text updates
void Game::handleText()
{
	cooldownText.setString(std::to_string((garbageCounter / 60) + 1) + "s");
	garbageCounter--;
	moneyText.setString(std::to_string(money.getValue()));

	upgrade1Text.setString("Upgrade income:         " + std::to_string((int)money.cost1));
	upgrade2Text.setString("Reduce cooldown:      " + std::to_string((int)money.cost2));
	upgrade3Text.setString("Buy next stage:           " + std::to_string((int)money.cost3));
}

void Game::displayFinishWindow()
{
	window.clear();

	window.draw(finishScreen);
	window.draw(finishScreenText1);
	window.draw(finishScreenText2);

	window.display();
}