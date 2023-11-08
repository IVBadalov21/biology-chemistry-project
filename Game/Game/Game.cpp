#include "Precompile.hpp"
#include "Trash.hpp"
#include "Game.hpp"

Game::Game()
{
    this->window.create(sf::VideoMode(1280, 720), "Game");
    this->window.setFramerateLimit(60);
    this->garbageRespawnCooldown = sf::seconds(5.00f);

    this->blueTrashBinTexture.loadFromFile("../Assets/sin_kosh.png");
    this->yellowTrashBinTexture.loadFromFile("../Assets/jult_kosh.png");
    this->greenTrashBinTexture.loadFromFile("../Assets/zelen_kosh.png");
    this->glassTexture.loadFromFile("../Assets/glass.png");
    this->cardboardTexture.loadFromFile("../Assets/box.png");
    this->plasticTexture.loadFromFile("../Assets/plastic.png");
    this->backgroundTexture.loadFromFile("../Assets/background.png");

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

    this->blueTrashBin.setTexture(this->trashBinTextures[1]);
    this->blueTrashBin.setPosition(sf::Vector2f(340, 480));
    this->blueTrashBin.setValue(1);

    this->yellowTrashBin.setTexture(this->trashBinTextures[2]);
    this->yellowTrashBin.setPosition(sf::Vector2f(580, 480));
    this->yellowTrashBin.setValue(2);

    this->greenTrashBin.setTexture(this->trashBinTextures[3]);
    this->greenTrashBin.setPosition(sf::Vector2f(820, 480));
    this->greenTrashBin.setValue(3);

    this->garbageValue = getRandomGarbage();

    this->garbage.setTexture(this->garbageTextures[this->garbageValue]);
    this->garbage.setPosition(sf::Vector2f(580, 300));
    this->garbage.setValue(this->garbageValue);
    this->garbage.setStatus(false);

    this->background.setTexture(this->backgroundTexture);
    this->background.setSize();

    garbageShouldDraw = true;

    update();
}

void Game::displayWindow()
{
    this->window.clear();
    this->background.draw(this->window);
    if(garbageShouldDraw)
        this->garbage.draw(this->window);
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
        displayWindow();
        garbageLogic();
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

    if ((sf::Mouse::getPosition().x > 580 && sf::Mouse::getPosition().x < 700 && sf::Mouse::getPosition().y > 300 && sf::Mouse::getPosition().y < 420) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        this->isGarbageFollowingMouse = true;
    }

    if (this->isGarbageFollowingMouse)
    {
        garbage.setPosition(sf::Vector2f(sf::Mouse::getPosition().x - 60, sf::Mouse::getPosition().y - 60));
    }

    //switch (this->garbageValue)
    //{
    //    case 1: 

    //    case 2:

    //    case 3:

    //}

    if (this->garbage.getStatus())
    {
        this->isAlreadyChanged = false;
        if (!this->isClockAlreadyRestarted)
        {
            this->clock.restart();
        }
        this->elapsedTime = clock.getElapsedTime();
    }

    if (garbage.getStatus() && this->elapsedTime == this->garbageRespawnCooldown)
    {
        this->garbage.setStatus(false);
        this->garbageShouldDraw = true;
    }

    if (!this->garbage.getStatus() && !this->isAlreadyChanged)
    {
        this->garbageValue = getRandomGarbage();
        this->garbage.setTexture(this->garbageTextures[garbageValue]);
        garbage.setPosition(sf::Vector2f(580, 300));
        garbage.setValue(garbageValue);
        garbage.setStatus(false);
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