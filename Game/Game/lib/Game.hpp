#include "Precompile.hpp"
#include "Trash.hpp"
#include "Background.hpp"
#include "Garbage.hpp"
#include "Money.hpp"
#include "MainMenu.hpp"
#include "Miscellanious.hpp"
#pragma once

class Game {
public:
	Game();
	void displayWindow();
	void update();
	int getRandomGarbage();
	void garbageLogic();
	void processKeyPressed();
	void upgrade1();
	void upgrade2();
	void upgrade3();
	void handleText();
	void displayFinishWindow();

private:

	sf::RenderWindow window;
	sf::Event event;

	std::map<int, sf::Texture> trashBinTextures;
	std::map<int, sf::Texture> garbageTextures;
	std::map<int, sf::Texture> backgroundTextures;
	sf::Texture blueTrashBinTexture;
	sf::Texture yellowTrashBinTexture;
	sf::Texture greenTrashBinTexture;
	sf::Texture backgroundTexture1;
	sf::Texture backgroundTexture2;
	sf::Texture backgroundTexture3;
	sf::Texture backgroundTexture4;
	sf::Texture glassTexture;
	sf::Texture cardboardTexture;
	sf::Texture plasticTexture;
	sf::Texture moneyTexture;
	sf::Texture mainMenuTexture;
	sf::Texture buttonOneTexture;
	sf::Texture buttonTwoTexture;
	sf::Texture buttonThreeTexture;
	sf::Texture startTexture;
	sf::Texture quitTexture;
	sf::Texture finishScreenTexture;

	sf::Sprite finishScreen;

	sf::Font font;
	sf::Text cooldownText;
	sf::Text moneyText;
	sf::Text upgrade1Text;
	sf::Text upgrade2Text;
	sf::Text upgrade3Text;
	sf::Text finishScreenText1;
	sf::Text finishScreenText2;

	Trash blueTrashBin;
	Trash yellowTrashBin;
	Trash greenTrashBin;
	Garbage garbage;
	Background background;
	Money money;
	MainMenu mainMenu;
	Misc misc[13];

	int garbageValue;
	int garbageCooldown;
	int garbageCounter;
	bool isAlreadyChanged;
	bool isClockAlreadyRestarted;
	bool isGarbageFollowingMouse;
	bool garbageShouldDraw;
	bool shouldMainMenuDisplay = true;
	bool shouldWindowClose = false;
	bool shouldFinishScreenDisplay = false;
};