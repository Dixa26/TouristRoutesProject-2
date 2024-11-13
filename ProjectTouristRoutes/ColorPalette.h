#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class ColorPalette {
private:
	int const static TOTAL_OF_COLOR = 9;
	RectangleShape square[TOTAL_OF_COLOR];
	Color colorList[TOTAL_OF_COLOR];
	int squareSize = 50;
	Color colorOfRoute;
public:
	ColorPalette();
	void fillColor();
	void createColorPalette(RenderWindow& window);
	void getColorOfPalette(Vector2f mousePosition, int index);
	void choseColor(RenderWindow& window, Event eventOfColor);
	Color getColor();
	void drawColorPalette(RenderWindow& window);
};



