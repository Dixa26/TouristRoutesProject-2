#include "Point.h"
Point::Point(float axisX, float axisY) :xAxis(axisX), yAxis(axisY) {}

float Point::getAxisX() {
	return xAxis;
}

float Point::getAxisY() {
	return yAxis;
}
