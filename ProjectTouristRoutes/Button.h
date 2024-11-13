#pragma once
#include <SFML/Graphics.hpp>
#include "FileManager.h"
#include "GraphicPoint.h"

using namespace sf;

class Button {
private:
	int const static quantityOfButton = 7;
	RectangleShape button[quantityOfButton];
	float broad = 200.0;
	float alture = 50.0;
	Font font;
	Text text[quantityOfButton];

	bool optionSaveRoute;
	bool routeIsAdded;
	bool stopAddRoute;
	bool editRoute;
	bool removeRoute;

	FileManager fileManager;
	RouteList* routeList;

public:
	Button();
	void getOptionAddRoute(int optionNumber);
	void getOptionOfRemove(int optionNumber);
	void saveAndLoadOption(int optionNumber);
	void getExit(int optionNumber, RenderWindow& window);
	bool checkAddRoute();
	bool isStopAddRoute();
	bool getEditROute();
	bool isRemoveRoute();
	void writeTextOfButton();
	void setRouteList(RouteList* list);
	void chooseNumberOfOption(RenderWindow& window, Event& eventOfWindow);
	void drawButton(RenderWindow& window, Event event);
};



