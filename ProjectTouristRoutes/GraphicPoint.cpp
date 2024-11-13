#include "GraphicPoint.h"

GraphicPoint::GraphicPoint() {
	circlePoint.setRadius(radius);
}

void GraphicPoint::drawColor(RenderWindow& window, Event eventOfColor) {
	colorPalette.drawColorPalette(window);
	colorPalette.choseColor(window, eventOfColor);
	color = colorPalette.getColor();
}

void GraphicPoint::drawPoint(RenderWindow& window, NodePoint* tail) {
	NodePoint* current = tail;
	while (current != nullptr) {
		circlePoint.setPosition(current->getDataPoint()->getX(), current->getDataPoint()->getY());
		circlePoint.setFillColor(color);
		window.draw(circlePoint);
		current = current->getPreviousNodePoint();
	}
}

void GraphicPoint::drawInterpolation(RenderWindow& window, NodePoint* tail) {
	int size = 0;
	NodePoint* current = tail;
	while (current != nullptr) {
		size++;
		current = current->getPreviousNodePoint();
	}

	Vector2f* points = new sf::Vector2f[size];
	current = tail;
	for (int i = size - 1; i >= 0; i--) {
		points[i] = sf::Vector2f(current->getDataPoint()->getX(), current->getDataPoint()->getY());
		current = current->getPreviousNodePoint();
	}
	
	VertexArray spline(sf::LineStrip);

	for (int i = 0; i < size - 1; i++) {
		Vector2f p0 = (i > 0) ? points[i - 1] : points[i];
		Vector2f p1 = points[i];
		Vector2f p2 = points[i + 1];
		Vector2f p3 = (i + 2 < size) ? points[i + 2] : points[i + 1]; 

		for (float t = 0; t <= 1; t += 0.05f) {
			float t2 = t * t;
			float t3 = t2 * t;

			Vector2f interpolatedPoint = 0.5f * ((2.0f * p1) + (-p0 + p2) * t + 
				(2.0f * p0 - 5.0f * p1 + 4.0f * p2 - p3) * t2 +
				(-p0 + 3.0f * p1 - 3.0f * p2 + p3) * t3);

			spline.append(Vertex(interpolatedPoint, Color::Black));
		}
	}

	window.draw(spline);

	delete[] points;
}

void GraphicPoint::drawPointOfTheRouteList(RenderWindow& window, NodeRoute* tail) {
	NodeRoute* currentNode = tail;
	while (currentNode != nullptr) {
		NodePoint* currentPoint = currentNode->getDataRoute()->getTail();
		while (currentPoint != nullptr) {
			circlePoint.setPosition(currentPoint->getDataPoint()->getX(), currentPoint->getDataPoint()->getY());
			window.draw(circlePoint);
			currentPoint = currentPoint->getPreviousNodePoint();
		}
		currentNode = currentNode->getPreviousNodeRoute();
	}
}

void GraphicPoint::drawLineOfTheRouteList(RenderWindow& window, NodeRoute* tail) {
	NodeRoute* currentNode = tail;
	while (currentNode != nullptr) {
		NodePoint* currentPoint = currentNode->getDataRoute()->getTail();
		drawInterpolation(window, currentPoint);
		currentNode = currentNode->getPreviousNodeRoute();
	}
}

void GraphicPoint::drawRoute(RenderWindow& window, NodePoint* tail) {
	drawPoint(window, tail);
	drawInterpolation(window, tail);
}

void GraphicPoint::drawRouteList(RenderWindow& window, NodeRoute* tail) {
	drawPointOfTheRouteList(window, tail);
	drawLineOfTheRouteList(window, tail);
}

void GraphicPoint::removePointOfRoute(Vector2i& mousePosition, Route& route) {
	NodePoint* current = route.getTail();
	while (current != nullptr) {
		float distance = sqrt(pow(mousePosition.x - current->getDataPoint()->getX(), 2) +
			pow(mousePosition.y - current->getDataPoint()->getY(), 2));
		if (distance < distanceOfMause) {
			route.removePoint(current->getDataPoint());
			return;
		}
		current = current->getPreviousNodePoint();
	}
}

void GraphicPoint::removePointOfRouteList(Vector2i& mousePosition, RouteList& routeList) {
	NodeRoute* currentNode = routeList.getTail();
	while (currentNode != nullptr) {
		Route* currentRoute = currentNode->getDataRoute();
		removePointOfRoute(mousePosition, *currentRoute);
		currentNode = currentNode->getPreviousNodeRoute();
	}
}

void GraphicPoint::removeRoute(Vector2i& mousePosition, RouteList& routeList) {
	NodeRoute* currentNode = routeList.getHead();
	while (currentNode != nullptr) {
		NodePoint* currentPoint = currentNode->getDataRoute()->getTail();
		while (currentPoint != nullptr) {
			float distance = sqrt(pow(mousePosition.x - currentPoint->getDataPoint()->getX(), 2) +
				pow(mousePosition.y - currentPoint->getDataPoint()->getY(), 2));
			if (distance < distanceOfMause) {
				routeList.removeRouteOfTheList(currentNode->getDataRoute());
				return;
			}
			currentPoint = currentPoint->getPreviousNodePoint();
		}
		currentNode = currentNode->getNextNodeRoute();
	}
}