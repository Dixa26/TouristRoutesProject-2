#include "Button.h"

Button::Button() {
	routeIsAdded = false;
	stopAddRoute = false;
	editRoute = false;
	removeRoute = false;
	optionSaveRoute = false;
	font.loadFromFile("resources/arial.ttf");
	for (int i = 0; i < quantityOfButton; i++) {
		button[i].setFillColor(sf::Color::Magenta);
		button[i].setSize(sf::Vector2f(270.f, 50.f)); 
		button[i].setPosition(50.f, 30.f + i * 60); 

		text[i].setFont(font);
		text[i].setFillColor(sf::Color::White);
		text[i].setCharacterSize(30);

		text[i].setPosition(60.f, 35 + i * 60);
	}
	writeTextOfButton();
}

void Button::getExit(int optionNumber, sf::RenderWindow& window) {
	int optionSeven = 6;
	if (optionNumber == optionSeven) {
		window.close();
	}
}

void Button::writeTextOfButton() {
	text[0].setString("Insertar");
	text[1].setString("Seleccionar punto");
	text[2].setString("Eliminar punto");
	text[3].setString("Cargar ruta");
	text[4].setString("Salir");
}

void Button::drawButton(sf::RenderWindow& window, sf::Event event) {
	for (int i = 0; i < quantityOfButton; i++) {
		window.draw(button[i]);
		window.draw(text[i]);
	}
}