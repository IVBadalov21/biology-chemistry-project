#pragma once
class Game {
public:
	Game();
	void displayWindow();
	void update();
	void processKeyPressed();
private:
	sf::RenderWindow window;
	sf::Event event;
	std::map<int, sf::Texture> trashTextures;
};