#include "Map.h"

Map::Map() {
	int broad = 1400;
	int alture = 700;
	windowOfMap = new sf::RenderWindow(sf::VideoMode(broad, alture), "Mapa Turístico");
	eventOfWidow = new sf::Event;
	mapTexture = new sf::Texture;
	mapSprite = new sf::Sprite;

	backgroundTexture = new sf::Texture();
	if (!backgroundTexture->loadFromFile("Resources/fondo.png")) {
		exit(EXIT_FAILURE); 
	}
	backgroundSprite = new sf::Sprite(*backgroundTexture);
	
}

Map::~Map() {
	delete windowOfMap;
	delete eventOfWidow;
	delete mapTexture;
	delete mapSprite;
}

void Map::createDesignOfMap() {
	mapTexture->loadFromFile("Resources/mapa_cr_degradado.png");
	mapSprite->setTexture(*mapTexture);

	float scaleFactor = 0.6f;
	mapSprite->setScale(scaleFactor, scaleFactor);

	mapSprite->setPosition(500.f, 0.f);
	windowOfMap->draw(*mapSprite);
}

void Map::manipulateWindow() {
	while (windowOfMap->pollEvent(*eventOfWidow)) {
		if (eventOfWidow->type == sf::Event::Closed) {
			windowOfMap->close();
		}
	}
}

void Map::draw() {
	createDesignOfMap();
	button.drawButton(*windowOfMap, *eventOfWidow);
}

void Map::run() {
	while (windowOfMap->isOpen()) {
		windowOfMap->clear();
		draw();
		manipulateWindow();
		windowOfMap->display();
	}
}