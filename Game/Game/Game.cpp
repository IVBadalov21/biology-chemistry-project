#include "Precompile.hpp"

void Game::displayWindow(sf::Vector2i position)
{
    window.clear();
    sf::CircleShape circle;
    circle.setFillColor(sf::Color(100, 100, 100));
    circle.setRadius(100);
    circle.setPosition(position.x, position.y);
    this->window.draw(circle);
    window.display();
}

Game::Game()
{
    sf::Vector2i position;
    position.x = 5;
    position.y = 5;
    sf::Vector2i velocity;
    velocity.x = 5;
    velocity.y = 5;
    this->window.create(sf::VideoMode(1920, 1080), "Game", sf::Style::Fullscreen);
    this->window.setFramerateLimit(60);
    
    while (this->window.isOpen())
    {
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->window.close();
        }
        position.x += velocity.x;
        position.y += velocity.y;
        if (position.x + 200 == 1920 || position.x == 0) {
            velocity.x *= -1;
        }
        if (position.y + 200 == 1080 || position.y == 0) {
            velocity.y *= -1;
        }
        displayWindow(position);
    }

}