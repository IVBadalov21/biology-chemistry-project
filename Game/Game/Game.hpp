#pragma once
class Game {
public:
	Game();
	void displayWindow(sf::Vector2i position);
private:
	sf::RenderWindow window;
};