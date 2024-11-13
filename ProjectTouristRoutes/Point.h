#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Point {
private:
	float x = 0.0;
	float y = 0.0;
public:
	Point(float pX, float pY);
	float getX();
	float getY();
};
