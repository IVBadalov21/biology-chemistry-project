#include "Precompile.hpp"
#include "Trash.hpp"
#include "Game.hpp"

Game::Game()
{
    this->window.create(sf::VideoMode(1280, 720), "Game");
    this->window.setFramerateLimit(60);

    this->blueTrashBinTexture.loadFromFile("../Assets/sin_kosh.png");
    this->yellowTrashBinTexture.loadFromFile("../Assets/jult_kosh.png");
    this->greenTrashBinTexture.loadFromFile("../Assets/zelen_kosh.png");
    this->backgroundTexture.loadFromFile("../Assets/background.png");

    this->trashBinTextures = {
        {1, this->blueTrashBinTexture},
        {2, this->yellowTrashBinTexture},        
        {3, this->greenTrashBinTexture}
    };

    this->blueTrashBin.setTexture(this->trashBinTextures[1]);
    this->blueTrashBin.setPosition(sf::Vector2f(340, 580));
    this->yellowTrashBin.setTexture(this->trashBinTextures[2]);
    this->yellowTrashBin.setPosition(sf::Vector2f(580, 580));
    this->greenTrashBin.setTexture(this->trashBinTextures[3]);
    this->greenTrashBin.setPosition(sf::Vector2f(820, 580));
    this->background.setTexture(this->backgroundTexture);
    this->background.setSize();
    update();
}

void Game::displayWindow()
{
    this->window.clear();
    this->background.draw(this->window);
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
    }
}

//void Game::processKeyPressed()
//{
//    if (this->event.key.code == sf::Keyboard::Num1)
//    {
//        if(this->)
//    }
//}