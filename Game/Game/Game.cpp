#include "Precompile.hpp"
#include "Trash.hpp"
#include "Game.hpp"

Game::Game()
{
    this->window.create(sf::VideoMode(1280, 720), "Game");
    this->window.setFramerateLimit(60);
    this->garbageCooldown = 300;

    this->blueTrashBinTexture.loadFromFile("../Assets/sin_kosh.png");
    this->yellowTrashBinTexture.loadFromFile("../Assets/jult_kosh.png");
    this->greenTrashBinTexture.loadFromFile("../Assets/zelen_kosh.png");
    this->glassTexture.loadFromFile("../Assets/glass.png");
    this->cardboardTexture.loadFromFile("../Assets/box.png");
    this->plasticTexture.loadFromFile("../Assets/plastic.png");
    this->backgroundTexture1.loadFromFile("../Assets/background.png");
    this->backgroundTexture2.loadFromFile("../Assets/background_flowers.png");
    this->backgroundTexture3.loadFromFile("../Assets/background_three.png");
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
        {2, this->backgroundTexture2},
        {3, this->backgroundTexture3}
    };

    this->cooldownText.setFont(this->font);
    this->cooldownText.setFillColor(sf::Color::White);
    this->cooldownText.setCharacterSize(120);
    this->cooldownText.setPosition(sf::Vector2f(580, 240));

    this->moneyText.setFont(this->font);
    this->moneyText.setFillColor(sf::Color::White);
    this->moneyText.setCharacterSize(32);
    this->moneyText.setPosition(sf::Vector2f(1000,150));

    this->blueTrashBin.setTexture(this->trashBinTextures[1]);
    this->blueTrashBin.setPosition(sf::Vector2f(340, 480));
    this->blueTrashBin.setValue(1);

    this->yellowTrashBin.setTexture(this->trashBinTextures[2]);
    this->yellowTrashBin.setPosition(sf::Vector2f(580, 480));
    this->yellowTrashBin.setValue(2);

    this->greenTrashBin.setTexture(this->trashBinTextures[3]);
    this->greenTrashBin.setPosition(sf::Vector2f(820, 480));
    this->greenTrashBin.setValue(3);

    this->background.setTexture(this->backgroundTextures[1]);
    this->background.setSize();

    this->garbageShouldDraw = true;
    this->garbage.setValue(getRandomGarbage());

    update();
}

void Game::displayWindow()
{
    this->window.clear();
    this->background.draw(this->window);
    if (this->garbageShouldDraw)
        this->garbage.draw(this->window);
    else
        this->window.draw(this->cooldownText);
    this->window.draw(this->moneyText);

    this->blueTrashBin.draw(this->window);
    this->yellowTrashBin.draw(this->window);
    this->greenTrashBin.draw(this->window);

    this->window.display();
}

void Game::update()
{
    while (this->window.isOpen())
    {
        while (this->window.pollEvent(this->event))
        {
            if (this->event.type == sf::Event::Closed)
            {
                this->window.close();
            }
            else
            {
                if (this->event.type == sf::Event::KeyPressed)
                {
                    processKeyPressed();
                }
            }
        }
        handleText();
        displayWindow();
        garbageLogic();
    }
}

int Game::getRandomGarbage()
{
    std::random_device generator;
    std::uniform_int_distribution<int> garbageValueGen(1, 3);
    return garbageValueGen(generator);
}

void Game::garbageLogic()
{

    if ((sf::Mouse::getPosition(this->window).x > 580 && sf::Mouse::getPosition(this->window).x < 700 && sf::Mouse::getPosition(this->window).y > 300 && sf::Mouse::getPosition(this->window).y < 420) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        this->isGarbageFollowingMouse = true;
    }

    if (this->isGarbageFollowingMouse)
    {
        garbage.setPosition(sf::Vector2f(sf::Mouse::getPosition(this->window).x - 60, sf::Mouse::getPosition(this->window).y - 60));
    }

    switch (this->garbageValue)
    {
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

    if (this->garbage.getStatus())
    {
        if (!this->isClockAlreadyRestarted)
        {
            garbageCounter = garbageCooldown;
            isClockAlreadyRestarted = true;
        }
    }

    if (this->garbage.getStatus() && this->garbageCounter == 0)
    {
        this->garbage.setStatus(false);
        this->garbageShouldDraw = true;
        this->isAlreadyChanged = false;
    }

    if (!this->garbage.getStatus() && !this->isAlreadyChanged)
    {
        this->garbageValue = getRandomGarbage();
        this->garbage.setTexture(this->garbageTextures[garbageValue]);
        garbage.setPosition(sf::Vector2f(580, 300));
        garbage.setValue(garbageValue);
        this->isAlreadyChanged = true;
    }
}

void Game::processKeyPressed()
{
    if (this->event.key.code == sf::Keyboard::Num1)
    {
        if (money.getValue() > this->money.cost1)
        {
            upgrade1();
        }
    }
    if (this->event.key.code == sf::Keyboard::Num2)
    {
        if (money.getValue() > this->money.cost2)
        {
            upgrade2();
        }
    }
    if (this->event.key.code == sf::Keyboard::Num3)
    {
        if (money.getValue() > this->money.cost3)
        {
            upgrade3();
        }
    }
}

void Game::upgrade1()
{
    this->money.setValue(-this->money.cost1);
    this->money.upgrade1Level++;
    this->money.setCost1(money.cost1 * 0.1 * money.upgrade1Level);
    this->money.moneyIncrease += 5;
}

void Game::upgrade2()
{
    this->money.setValue(-this->money.cost2);
    this->money.upgrade2Level++;
    this->money.setCost2(money.cost2 * 0.1 * money.upgrade2Level);
    this->garbageCooldown -= 50;
}

void Game::upgrade3()
{
    this->money.setValue(-this->money.cost3);
    this->money.upgrade3Level++;
    this->money.setCost3(money.cost3 * 0.1 * money.upgrade3Level);
    if (this->money.upgrade3Level = 1)
        this->background.setTexture(backgroundTextures[2]);
    if (this->money.upgrade3Level = 2)
        this->background.setTexture(backgroundTextures[3]);
}

void Game::handleText()
{
    //if (this->shouldMainMenuDisplay)
    //{

    //}
    //else
    //{
        this->cooldownText.setString(std::to_string(std::floor((garbageCounter / 60) + 1)) + "s");
        this->garbageCounter--;

        this->moneyText.setString(std::to_string(this->money.getValue()));
    //}
}