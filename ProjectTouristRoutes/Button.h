#pragma once
#include <SFML/Graphics.hpp>

class Button{
private:
	int const static quantityOfButton = 5;
	sf::RectangleShape button[quantityOfButton];
	float broad = 170.0;
	float alture = 50.0;
	sf::Font font;
	sf::Text text[quantityOfButton];

	bool optionSaveRoute;
	bool routeIsAdded;
	bool stopAddRoute;
	bool editRoute;
	bool removeRoute;

public:
	Button();
	void getExit(int optionNumber, sf::RenderWindow& window);
	void writeTextOfButton();
	void drawButton(sf::RenderWindow& window, sf::Event event);
};

