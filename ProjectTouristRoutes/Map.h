#pragma once
#include "Button.h"

class Map{
	sf::RenderWindow* windowOfMap;
	sf::Event* eventOfWidow;
	sf::Texture* backgroundTexture;
	sf::Sprite* backgroundSprite;

	sf::Texture* mapTexture;
	sf::Sprite* mapSprite;
	float broadOfMap = 1024.0f;
	float altureOfMap = 768.0f;

	Button button;

public:
	Map();
	~Map();
	void createDesignOfMap();
	void manipulateWindow();
	void draw();
	void run();

};

