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
    this->backgroundTexture.loadFromFile("../Assets/background.png");
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

    this->cooldownText.setFont(font);
    this->cooldownText.setFillColor(sf::Color::White);
    this->cooldownText.setCharacterSize(120);
    this->cooldownText.setPosition(sf::Vector2f(580, 240));

    this->blueTrashBin.setTexture(this->trashBinTextures[1]);
    this->blueTrashBin.setPosition(sf::Vector2f(340, 480));
    this->blueTrashBin.setValue(1);

    this->yellowTrashBin.setTexture(this->trashBinTextures[2]);
    this->yellowTrashBin.setPosition(sf::Vector2f(580, 480));
    this->yellowTrashBin.setValue(2);

    this->greenTrashBin.setTexture(this->trashBinTextures[3]);
    this->greenTrashBin.setPosition(sf::Vector2f(820, 480));
    this->greenTrashBin.setValue(3);

    this->background.setTexture(this->backgroundTexture);
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
            //else
            //{
            //    if (this->event.type == sf::Event::KeyPressed)
            //    {
            //        processKeyPressed();
            //    }
            //}
        }
        this->cooldownText.setString(std::to_string(garbageCounter / 60)+"s");
        displayWindow();
        garbageLogic();
        this->garbageCounter++;

    }
}

int Game::getRandomGarbage()
{
    std::default_random_engine generator;
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
            if ((sf::Mouse::getPosition(this->window).x > 340 && sf::Mouse::getPosition(this->window).x < 460 && sf::Mouse::getPosition(this->window).y >480 && sf::Mouse::getPosition(this->window).y < 600) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                this->garbageShouldDraw = false;
                this->isClockAlreadyRestarted = false;
                this->garbage.setStatus(true);
                this->isGarbageFollowingMouse = false;
            }
            break;
        case 2:
            if ((sf::Mouse::getPosition(this->window).x > 580 && sf::Mouse::getPosition(this->window).x < 700 && sf::Mouse::getPosition(this->window).y >480 && sf::Mouse::getPosition(this->window).y < 600) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                this->garbageShouldDraw = false;
                this->isClockAlreadyRestarted = false;
                this->garbage.setStatus(true);
                this->isGarbageFollowingMouse = false;
            }
            break;
        case 3:
            if ((sf::Mouse::getPosition(this->window).x > 820 && sf::Mouse::getPosition(this->window).x < 1000 && sf::Mouse::getPosition(this->window).y >480 && sf::Mouse::getPosition(this->window).y < 600) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                this->garbageShouldDraw = false;
                this->isClockAlreadyRestarted = false;
                this->garbage.setStatus(true);
                this->isGarbageFollowingMouse = false;
            }
            break;
    }

    if (this->garbage.getStatus())
    {
        if (!this->isClockAlreadyRestarted)
        {
            garbageCounter = 0;
            isClockAlreadyRestarted = true;
        }
    }

    if (this->garbage.getStatus() && this->garbageCounter == this->garbageCooldown)
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

//void Game::processKeyPressed()
//{
//    if (this->event.key.code == sf::Keyboard::Num1)
//    {
//        if(this->)
//    }
//}