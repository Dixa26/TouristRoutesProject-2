#include "Button.h"

Button::Button() {
	routeIsAdded = false;
	stopAddRoute = false;
	editRoute = false;
	removeRoute = false;
	optionSaveRoute = false;
	font.loadFromFile("resources/arial.ttf");
	for (int i = 0; i < quantityOfButton; i++) {
		button[i].setFillColor(Color::White);
		button[i].setSize(Vector2f(broad, alture));
		button[i].setPosition(1050, 80 + i * 90);
		text[i].setFont(font);
		text[i].setFillColor(Color::Black);
		text[i].setCharacterSize(30);
		text[i].setPosition(1050, 80 + i * 90);
	}
	writeTextOfButton();
}

void Button::getOptionAddRoute(int optionNumber) {
	int optionOne = 0;
	int optionTwo = 1;
	if (optionNumber == optionOne) {
		removeRoute = false;
		editRoute = false;
		stopAddRoute = false;
		routeIsAdded = true;
	}
	if (optionNumber == optionTwo) {
		removeRoute = false;
		editRoute = false;
		routeIsAdded = false;
		stopAddRoute = true;
	}
}

void Button::getOptionOfRemove(int optionNumber) {
	int optionThree = 2;
	int optionFour = 3;
	if (optionNumber == optionThree) {
		routeIsAdded = false;
		stopAddRoute = false;
		removeRoute = false;
		editRoute = true;
	}
	if (optionNumber == optionFour) {
		routeIsAdded = false;
		stopAddRoute = false;
		editRoute = false;
		removeRoute = true;
	}
}

void Button::saveAndLoadOption(int optionNumber) {
	int optionFive = 4;
	int optionSix = 5;
	if (optionNumber == optionFive) {
		routeIsAdded = false;
		stopAddRoute = false;
		editRoute = false;
		removeRoute = false;
		string nameOfSaveFile;
		cin >> nameOfSaveFile;
		fileManager.saveRoute(nameOfSaveFile, *routeList);
	}
	if (optionNumber == optionSix) {
		routeIsAdded = false;
		stopAddRoute = false;
		editRoute = false;
		removeRoute = false;
		string nameOfFile;
		cin >> nameOfFile;
		fileManager.loadRoute(nameOfFile, *routeList);
	}
}

void Button::getExit(int optionNumber, RenderWindow& window) {
	int optionSeven = 6;
	if (optionNumber == optionSeven) {
		window.close();
	}
}

void Button::chooseNumberOfOption(RenderWindow& window, Event& eventOfWidow) {
	Vector2i mousePosition = Mouse::getPosition(window);
	for (int i = 0; i < quantityOfButton; i++) {
		if (button[i].getGlobalBounds().contains(Vector2f(mousePosition)) &&
			eventOfWidow.type == Event::MouseButtonReleased && eventOfWidow.mouseButton.button == Mouse::Left) {
			getOptionAddRoute(i);
			getOptionOfRemove(i);
			saveAndLoadOption(i);
			getExit(i, window);
			button[i].setFillColor(Color::Green);
		}
	}
}

bool Button::getEditROute() {
	return editRoute;
}

bool Button::isStopAddRoute() {
	return stopAddRoute;
}

bool Button::checkAddRoute() {
	return routeIsAdded;
}

bool Button::isRemoveRoute() {
	return removeRoute;
}

void Button::writeTextOfButton() {
	text[0].setString("Agregar ruta");
	text[1].setString("Terminar ruta");
	text[2].setString("Eliminar punto");
	text[3].setString("Eliminar ruta");
	text[4].setString("Guardar ruta");
	text[5].setString("Cargar ruta");
	text[6].setString("Salir");
}

void Button::setRouteList(RouteList* list) {
	routeList = list;
}

void Button::drawButton(RenderWindow& window, Event event) {
	chooseNumberOfOption(window, event);
	for (int i = 0; i < quantityOfButton; i++) {
		window.draw(button[i]);
		window.draw(text[i]);
	}
}