#include "Precompile.hpp"
#include "Trash.hpp"
#include "Background.hpp"
#include "Garbage.hpp"
#pragma once

class Game {
public:
	Game();
	void displayWindow();
	void update();
	int getRandomGarbage();
	void garbageLogic();
	//void processKeyPressed();
private:

	sf::RenderWindow window;
	sf::Event event;
	sf::Time garbageRespawnCooldown;
	sf::Time elapsedTime;
	sf::Clock clock;
	std::map<int, sf::Texture> trashBinTextures;
	std::map<int, sf::Texture> garbageTextures;
	sf::Texture blueTrashBinTexture;
	sf::Texture yellowTrashBinTexture;
	sf::Texture greenTrashBinTexture;
	sf::Texture backgroundTexture;
	sf::Texture glassTexture;
	sf::Texture cardboardTexture;
	sf::Texture plasticTexture;
	Trash blueTrashBin;
	Trash yellowTrashBin;
	Trash greenTrashBin;
	Garbage garbage;
	Background background;
	int garbageValue;
	bool isAlreadyChanged;
	bool isClockAlreadyRestarted;
	bool isGarbageFollowingMouse;
	bool garbageShouldDraw;
};