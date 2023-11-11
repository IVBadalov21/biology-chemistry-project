#include "../lib/Precompile.hpp"
#include "../lib/Trash.hpp"
#include "../lib/Game.hpp"

Game::Game()
{
    //Create window and set the framerate
    this->window.create(sf::VideoMode(1280, 720), "Game"/*, sf::Style::Fullscreen*/);
    this->window.setFramerateLimit(60);
    this->garbageCooldown = 300;
    //Load game textures
    this->buttonOneTexture.loadFromFile("../Assets/one_button.png");
    this->buttonTwoTexture.loadFromFile("../Assets/two_button.png");
    this->buttonThreeTexture.loadFromFile("../Assets/three_button.png");
    this->moneyTexture.loadFromFile("../Assets/coins.png");
    this->mainMenuTexture.loadFromFile("../Assets/cloud_back.png");
    this->blueTrashBinTexture.loadFromFile("../Assets/sin_kosh.png");
    this->yellowTrashBinTexture.loadFromFile("../Assets/jult_kosh.png");
    this->greenTrashBinTexture.loadFromFile("../Assets/zelen_kosh.png");
    this->glassTexture.loadFromFile("../Assets/glass.png");
    this->cardboardTexture.loadFromFile("../Assets/box.png");
    this->plasticTexture.loadFromFile("../Assets/plastic.png");
    this->backgroundTexture1.loadFromFile("../Assets/background.png");
    //this->backgroundTexture2.loadFromFile("../Assets/background_flowers.png");
    //this->backgroundTexture3.loadFromFile("../Assets/background_three.png");
    this->font.loadFromFile("../Assets/Agbalumo-Regular.ttf");

    this->trashBinTextures = {
        {1, this->blueTrashBinTexture},
        {2, this->yellowTrashBinTexture},        
        {3, this->greenTrashBinTexture}
    };

    this->garbageTextures = {
        {1, this->cardboardTexture},
        {2, this->plasticTexture},
        {3, this->glassTexture}
    };

    this->backgroundTextures = {
        {1, this->backgroundTexture1},
        //{2, this->backgroundTexture2},
        //{3, this->backgroundTexture3}
    };
    //Set the texture of the main menu
    this->mainMenu.setTexture(this->mainMenuTexture);
    this->mainMenu.setButtons();
    //Set the cooldown text
    this->cooldownText.setFont(this->font);
    this->cooldownText.setFillColor(sf::Color::White);
    this->cooldownText.setCharacterSize(120);
    this->cooldownText.setPosition(sf::Vector2f(580, 240));
    //Set textures of miscellanious elements
    this->misc[0].setTexture(moneyTexture);
    this->misc[0].setPosition(sf::Vector2f(960, 160));

    this->misc[1].setTexture(blueTrashBinTexture);
    this->misc[1].setPosition(sf::Vector2f(20, 200));
    this->misc[1].setScale(0.5f);

    this->misc[2].setTexture(yellowTrashBinTexture);
    this->misc[2].setPosition(sf::Vector2f(20, 280));
    this->misc[2].setScale(0.5f);

    this->misc[3].setTexture(greenTrashBinTexture);
    this->misc[3].setPosition(sf::Vector2f(20, 360));
    this->misc[3].setScale(0.5f);

    this->misc[4].setTexture(cardboardTexture);
    this->misc[4].setPosition(sf::Vector2f(80, 200));
    this->misc[4].setScale(0.5f);

    this->misc[5].setTexture(plasticTexture);
    this->misc[5].setPosition(sf::Vector2f(80, 280));
    this->misc[5].setScale(0.5f);

    this->misc[6].setTexture(glassTexture);
    this->misc[6].setPosition(sf::Vector2f(80, 360));
    this->misc[6].setScale(0.5f);

    this->misc[7].setTexture(moneyTexture);
    this->misc[7].setPosition(sf::Vector2f(1210, 310));

    this->misc[8].setTexture(moneyTexture);
    this->misc[8].setPosition(sf::Vector2f(1210, 360));

    this->misc[9].setTexture(moneyTexture);
    this->misc[9].setPosition(sf::Vector2f(1190, 410));

    this->misc[10].setTexture(buttonOneTexture);
    this->misc[10].setPosition(sf::Vector2f(900, 310));
    this->misc[10].setScale(0.25f);

    this->misc[11].setTexture(buttonTwoTexture);
    this->misc[11].setPosition(sf::Vector2f(900, 360));
    this->misc[11].setScale(0.25f);

    this->misc[12].setTexture(buttonThreeTexture);
    this->misc[12].setPosition(sf::Vector2f(900, 410));
    this->misc[12].setScale(0.25f);
    //Set the money text
    this->moneyText.setFont(this->font);
    this->moneyText.setFillColor(sf::Color::White);
    this->moneyText.setCharacterSize(32);
    this->moneyText.setPosition(sf::Vector2f(1000,150));
    //Set text for upgrade 1
    this->upgrade1Text.setFont(this->font);
    this->upgrade1Text.setFillColor(sf::Color::White);
    this->upgrade1Text.setCharacterSize(32);
    this->upgrade1Text.setPosition(sf::Vector2f(940, 300));
    //Set text for upgrade 2
    this->upgrade2Text.setFont(this->font);
    this->upgrade2Text.setFillColor(sf::Color::White);
    this->upgrade2Text.setCharacterSize(32);
    this->upgrade2Text.setPosition(sf::Vector2f(940, 350));
    //Set text for upgrade 3
    this->upgrade3Text.setFont(this->font);
    this->upgrade3Text.setFillColor(sf::Color::White);
    this->upgrade3Text.setCharacterSize(32);
    this->upgrade3Text.setPosition(sf::Vector2f(940, 400));
    //Set blue trash bin texture
    this->blueTrashBin.setTexture(this->trashBinTextures[1]);
    this->blueTrashBin.setPosition(sf::Vector2f(340, 480));
    this->blueTrashBin.setValue(1);
    //Set yellow trash bin texture
    this->yellowTrashBin.setTexture(this->trashBinTextures[2]);
    this->yellowTrashBin.setPosition(sf::Vector2f(580, 480));
    this->yellowTrashBin.setValue(2);
    //Set green trash bin texture
    this->greenTrashBin.setTexture(this->trashBinTextures[3]);
    this->greenTrashBin.setPosition(sf::Vector2f(820, 480));
    this->greenTrashBin.setValue(3);
    //Set background texture
    this->background.setTexture(this->backgroundTextures[1]);
    this->background.setSize();
    //Spawn initial garbage
    this->garbageShouldDraw = true;
    this->garbage.setValue(getRandomGarbage());

    update();
}
//Display ythings on the window
void Game::displayWindow()
{
    this->window.clear();

    this->background.draw(this->window);

    this->blueTrashBin.draw(this->window);
    this->yellowTrashBin.draw(this->window);
    this->greenTrashBin.draw(this->window);

    if (this->garbageShouldDraw)
        this->garbage.draw(this->window);
    else
        this->window.draw(this->cooldownText);

    this->misc[0].draw(this->window);
    this->window.draw(this->moneyText);

    this->misc[1].draw(this->window);
    this->misc[2].draw(this->window);
    this->misc[3].draw(this->window);
    this->misc[4].draw(this->window);
    this->misc[5].draw(this->window);
    this->misc[6].draw(this->window);
    this->misc[7].draw(this->window);
    this->misc[8].draw(this->window);
    this->misc[9].draw(this->window);
    this->misc[10].draw(this->window);
    this->misc[11].draw(this->window);
    this->misc[12].draw(this->window);

    window.draw(this->upgrade1Text);
    window.draw(this->upgrade2Text);
    window.draw(this->upgrade3Text);

    this->window.display();
}
//Handle program runtime
void Game::update()
{
    while (this->window.isOpen())
    {
        while (this->window.pollEvent(this->event))
        {
            if (this->event.type == sf::Event::Closed || this->shouldWindowClose)
            {
                this->window.close();
            }
            else
            {
                if (this->event.type == sf::Event::KeyPressed && !this->shouldMainMenuDisplay)
                {
                    processKeyPressed();
                }
            }
        }
        if (this->shouldMainMenuDisplay)
        {
            this->mainMenu.handleButtons(this->window, this->shouldWindowClose, this->shouldMainMenuDisplay);
            this->mainMenu.draw(this->window);
        }
        else
        {
            handleText();
            displayWindow();
            garbageLogic();
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
    if ((sf::Mouse::getPosition(this->window).x > 580 && sf::Mouse::getPosition(this->window).x < 700 && sf::Mouse::getPosition(this->window).y > 300 && sf::Mouse::getPosition(this->window).y < 420) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        this->isGarbageFollowingMouse = true;
    }

    if (this->isGarbageFollowingMouse)
    {
        garbage.setPosition(sf::Vector2f(sf::Mouse::getPosition(this->window).x - 60.f, sf::Mouse::getPosition(this->window).y - 60.f));
    }
    //Check for garbage to trash bin
    switch (this->garbageValue)
    {
        //Check for garbage on the blue bin
        case 1: 
            if ((sf::Mouse::getPosition(this->window).x > 340 && sf::Mouse::getPosition(this->window).x < 460 && sf::Mouse::getPosition(this->window).y >480 && sf::Mouse::getPosition(this->window).y < 600) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->isGarbageFollowingMouse)
            {
                this->garbageShouldDraw = false;
                this->isClockAlreadyRestarted = false;
                this->garbage.setStatus(true);
                this->isGarbageFollowingMouse = false;
                this->money.setValue(money.moneyIncrease);
            }
            break;
        //Check for garbage on the yellow bin
        case 2:
            if ((sf::Mouse::getPosition(this->window).x > 580 && sf::Mouse::getPosition(this->window).x < 700 && sf::Mouse::getPosition(this->window).y >480 && sf::Mouse::getPosition(this->window).y < 600) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->isGarbageFollowingMouse)
            {
                this->garbageShouldDraw = false;
                this->isClockAlreadyRestarted = false;
                this->garbage.setStatus(true);
                this->isGarbageFollowingMouse = false;
                this->money.setValue(money.moneyIncrease);
            }
            break;
        //Check for garbage on green bin
        case 3:
            if ((sf::Mouse::getPosition(this->window).x > 820 && sf::Mouse::getPosition(this->window).x < 1000 && sf::Mouse::getPosition(this->window).y >480 && sf::Mouse::getPosition(this->window).y < 600) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->isGarbageFollowingMouse)
            {
                this->garbageShouldDraw = false;
                this->isClockAlreadyRestarted = false;
                this->garbage.setStatus(true);
                this->isGarbageFollowingMouse = false;
                this->money.setValue(money.moneyIncrease);
            }
            break;
    }
    //Set garbage status
    if (this->garbage.getStatus())
    {
        if (!this->isClockAlreadyRestarted)
        {
            garbageCounter = garbageCooldown;
            isClockAlreadyRestarted = true;
        }
    }
    //Allow garbage to respawn
    if (this->garbage.getStatus() && this->garbageCounter == 0)
    {
        this->garbage.setStatus(false);
        this->garbageShouldDraw = true;
        this->isAlreadyChanged = false;
    }
    //Set garbage properties for respawn
    if (!this->garbage.getStatus() && !this->isAlreadyChanged)
    {
        this->garbageValue = getRandomGarbage();
        this->garbage.setTexture(this->garbageTextures[garbageValue]);
        garbage.setPosition(sf::Vector2f(580, 300));
        garbage.setValue(garbageValue);
        this->isAlreadyChanged = true;
    }
}
//Process pressing of keys
void Game::processKeyPressed()
{
    if (this->event.key.code == sf::Keyboard::Num1)
    {
        if (money.getValue() >= this->money.cost1)
        {
            upgrade1();
        }
    }
    if (this->event.key.code == sf::Keyboard::Num2)
    {
        if (money.getValue() >= this->money.cost2)
        {
            upgrade2();
        }
    }
    if (this->event.key.code == sf::Keyboard::Num3)
    {
        if (money.getValue() >= this->money.cost3)
        {
            upgrade3();
        }
    }
    if (this->event.key.code == sf::Keyboard::Escape)
    {
        this->shouldMainMenuDisplay = true;
    }
}
//Handling of the first upgrade
void Game::upgrade1()
{
    this->money.setValue(-this->money.cost1);
    this->money.upgrade1Level++;
    this->money.setCost1(money.cost1 * (1 + (0.1f * money.upgrade1Level)));
    this->money.moneyIncrease += 2;
}
//Handling of the second upgrade 
void Game::upgrade2()
{
    this->money.setValue(-this->money.cost2);
    this->money.upgrade2Level++;
    this->money.setCost2(money.cost2 * (1 + (0.1f * money.upgrade2Level)));
    this->garbageCooldown -= 50;
}
//Handling of the third upgrade
void Game::upgrade3()
{
    this->money.setValue(-this->money.cost3);
    this->money.upgrade3Level++;
    this->money.setCost3(money.cost3 * 0.1f * money.upgrade3Level);
    if (this->money.upgrade3Level = 1)
        this->background.setTexture(backgroundTextures[2]);
    if (this->money.upgrade3Level = 2)
        this->background.setTexture(backgroundTextures[3]);
}
//Handling of text updates
void Game::handleText()
{
        this->cooldownText.setString(std::to_string((garbageCounter / 60) + 1) + "s");
        this->garbageCounter--;
        this->moneyText.setString(std::to_string(this->money.getValue()));

        this->upgrade1Text.setString("Upgrade income:         " + std::to_string((int)this->money.cost1));
        this->upgrade2Text.setString("Reduce cooldown:      " + std::to_string((int)this->money.cost2));
        this->upgrade3Text.setString("Buy next stage:           " + std::to_string((int)this->money.cost3));
}