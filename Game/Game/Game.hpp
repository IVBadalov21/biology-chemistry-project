#include "Precompile.hpp"
#include "Trash.hpp"
#include "Background.hpp"
#pragma once

class Game {
public:
	Game();
	void displayWindow();
	void update();
	//void processKeyPressed();
private:

	sf::RenderWindow window;
	sf::Event event;
	std::map<int, sf::Texture> trashBinTextures;
	sf::Texture blueTrashBinTexture;
	sf::Texture yellowTrashBinTexture;
	sf::Texture greenTrashBinTexture;
	sf::Texture backgroundTexture;
	Trash blueTrashBin;
	Trash yellowTrashBin;
	Trash greenTrashBin;
	Background background;
};