#include "Map.h"

Map::Map() {
	int broad = 1500;
	int alture = 768;
	windowOfMap = new RenderWindow(VideoMode(broad, alture), "Mapa turistico");
	eventOfWidow = new Event;
	mapTexture = new Texture;
	mapSprite = new Sprite;
	route = new Route();
}

Map::~Map() {
	delete windowOfMap;
	delete eventOfWidow;
	delete mapTexture;
	delete mapSprite;
	delete route;
}

void Map::createDesignOfMap() {
	mapTexture->loadFromFile("Resources/mapa_cr_degradado.png");
	mapSprite->setTexture(*mapTexture);
	mapSprite->setScale(broadOfMap / mapSprite->getLocalBounds().width, altureOfMap / mapSprite->getLocalBounds().height);
	windowOfMap->draw(*mapSprite);
}

void Map::manipulateWindow() {
	while (windowOfMap->pollEvent(*eventOfWidow)) {
		if (eventOfWidow->type == Event::Closed) {
			windowOfMap->close();
		}
	}
}

void Map::sendCoordinate() {
	IntRect areaLimit(0, 0, broadOfMap, altureOfMap);
	if (eventOfWidow->type == Event::MouseButtonPressed && eventOfWidow->mouseButton.button == Mouse::Left) {
		Vector2i mousePosition = Mouse::getPosition(*windowOfMap);
		if (areaLimit.contains(mousePosition)) {
			route->addPoint(new Point(mousePosition.x, mousePosition.y));
		}
	}
}

void Map::checkAddCordinate() {
	if (button.checkAddRoute()) {
		graphicPoint.drawColor(*windowOfMap, *eventOfWidow);
		sendCoordinate();
	}
	if (button.isStopAddRoute()) {
		routeList.addRouteInTheList(new Route(*route));
		route = new Route();
	}
}

void Map::checkRemoveRoute() {
	if (button.getEditROute()) {
		if (eventOfWidow->type == Event::MouseButtonPressed && eventOfWidow->mouseButton.button == Mouse::Left) {
			Vector2i mousePosition = Mouse::getPosition(*windowOfMap);
			graphicPoint.removePointOfRouteList(mousePosition, routeList);
		}
	}
	if (button.isRemoveRoute()) {
		if (eventOfWidow->type == Event::MouseButtonPressed && eventOfWidow->mouseButton.button == Mouse::Left) {
			Vector2i mousePosition = Mouse::getPosition(*windowOfMap);
			graphicPoint.removeRoute(mousePosition, routeList);
		}
	}
}

void Map::setOption() {
	checkAddCordinate();
	checkRemoveRoute();
	button.setRouteList(&routeList);
}

void Map::draw() {
	createDesignOfMap();
	button.drawButton(*windowOfMap, *eventOfWidow);
	graphicPoint.drawRoute(*windowOfMap, route->getTail());
	graphicPoint.drawRouteList(*windowOfMap, routeList.getTail());
}

void Map::showWindow() {
	while (windowOfMap->isOpen()) {
		windowOfMap->clear();
		draw();
		setOption();
		manipulateWindow();
		windowOfMap->display();
	}
}