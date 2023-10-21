#include "Precompile.hpp"

Game::Game()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game", 60);
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
    }
}