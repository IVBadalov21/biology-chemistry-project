#include "Precompile.hpp"

Game::Game()
{
    this->window.create(sf::VideoMode(1920, 1080), "Game", sf::Style::Fullscreen);
    this->window.setFramerateLimit(60);

}

void Game::displayWindow()
{
    this->window.clear();
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
        displayWindow();
    }
}

void Game::processKeyPressed()
{
    //if (this->event.key.code == sf::Keyboard::Num1)
    //{
    //    if(this->)
    //}
}