#include "ColorPalette.h"

ColorPalette::ColorPalette() {
    fillColor();
}

void ColorPalette::fillColor() {
    colorList[0] = Color::Red;
    colorList[1] = Color::Green;
    colorList[2] = Color::Blue;
    colorList[3] = Color::Yellow;
    colorList[4] = Color::Magenta;
    colorList[5] = Color::Cyan;
    colorList[6] = Color(81, 0, 93);
    colorList[7] = Color::Black;
    colorList[8] = Color(128, 128, 128);
}

void ColorPalette::createColorPalette(RenderWindow& window) {
    fillColor();
    for (int i = 0; i < TOTAL_OF_COLOR; i++) {
        square[i].setSize(Vector2f(50, 50));
        square[i].setFillColor(colorList[i]);
        float positionX = window.getSize().x - ((i % 3) * (squareSize)) - squareSize;
        float positionY = (i / 3) * (squareSize);
        square[i].setPosition(positionX, positionY);
    }
}

void ColorPalette::getColorOfPalette(Vector2f mousePosition, int index) {
    if (square[index].getGlobalBounds().contains(Vector2f(mousePosition))) {
        colorOfRoute = colorList[index];
    }
}

void ColorPalette::choseColor(RenderWindow& window, Event eventOfColor) {
    Vector2i mousePosition = Mouse::getPosition(window);
    for (int i = 0; i < TOTAL_OF_COLOR; i++) {
        if (eventOfColor.type == Event::MouseButtonPressed && eventOfColor.mouseButton.button == Mouse::Left) {
            getColorOfPalette(Vector2f(mousePosition), i);
        }
    }
}

Color ColorPalette::getColor() {
    return colorOfRoute;
}

void ColorPalette::drawColorPalette(RenderWindow& window) {
    createColorPalette(window);
    for (int i = 0; i < TOTAL_OF_COLOR; i++) {
        window.draw(square[i]);
    }
}
