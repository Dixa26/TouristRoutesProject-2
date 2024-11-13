#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Point {
private:
	float xAxis = 0.0;
	float yAxis = 0.0;
public:
	Point(float axisX, float axisY);
	float getAxisX();
	float getAxisY();
};
