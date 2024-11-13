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
		circlePoint.setPosition(current->getDataPoint()->getAxisX(), current->getDataPoint()->getAxisY());
		circlePoint.setFillColor(color);
		window.draw(circlePoint);
		current = current->getPreviousNodePoint();
	}
}

void GraphicPoint::drawLineBetweenPoint(RenderWindow& window, NodePoint* tail) {
	int size = 0;
	NodePoint* current = tail;
	while (current != nullptr) {
		size++;
		current = current->getPreviousNodePoint();
	}

	//if (size < 4) {
	//	return; // Se necesitan al menos cuatro puntos para la interpolación cúbica segmentaria
	//}

	// Paso 2: Crear el arreglo dinámico y recolectar los puntos
	sf::Vector2f* points = new Vector2f[size];
	current = tail;
	for (int i = size - 1; i >= 0; i--) {
		points[i] = sf::Vector2f(current->getDataPoint()->getAxisX(), current->getDataPoint()->getAxisY());
		current = current->getPreviousNodePoint();
	}

	// Paso 3: Crear la curva usando interpolación cúbica segmentaria
	sf::VertexArray spline(sf::LineStrip);

	for (int i = 1; i < size - 2; i++) {
		sf::Vector2f p0 = points[i - 1];
		sf::Vector2f p1 = points[i];
		sf::Vector2f p2 = points[i + 1];
		sf::Vector2f p3 = points[i + 2];

		for (float t = 0; t <= 1; t += 0.05f) { // Ajusta la precisión de la curva
			float t2 = t * t;
			float t3 = t2 * t;

			sf::Vector2f interpolatedPoint =
				0.5f * ((2.0f * p1) +
					(-p0 + p2) * t +
					(2.0f * p0 - 5.0f * p1 + 4.0f * p2 - p3) * t2 +
					(-p0 + 3.0f * p1 - 3.0f * p2 + p3) * t3);

			spline.append(sf::Vertex(interpolatedPoint, sf::Color::Black));
		}
	}

	// Dibujar la curva
	window.draw(spline);

	// Paso 4: Liberar memoria
	delete[] points;
}

void GraphicPoint::drawPointOfTheRouteList(RenderWindow& window, NodeRoute* tail) {
	NodeRoute* currentNode = tail;
	while (currentNode != nullptr) {
		NodePoint* currentPoint = currentNode->getDataRoute()->getTail();
		while (currentPoint != nullptr) {
			circlePoint.setPosition(currentPoint->getDataPoint()->getAxisX(), currentPoint->getDataPoint()->getAxisY());
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
		drawLineBetweenPoint(window, currentPoint);
		currentNode = currentNode->getPreviousNodeRoute();
	}
}

void GraphicPoint::drawRoute(RenderWindow& window, NodePoint* tail) {
	drawPoint(window, tail);
	drawLineBetweenPoint(window, tail);
}

void GraphicPoint::drawRouteList(RenderWindow& window, NodeRoute* tail) {
	drawPointOfTheRouteList(window, tail);
	drawLineOfTheRouteList(window, tail);
}

void GraphicPoint::removePointOfRoute(Vector2i& mousePosition, Route& route) {
	NodePoint* current = route.getTail();
	while (current != nullptr) {
		float distance = sqrt(pow(mousePosition.x - current->getDataPoint()->getAxisX(), 2) +
			pow(mousePosition.y - current->getDataPoint()->getAxisY(), 2));
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
			float distance = sqrt(pow(mousePosition.x - currentPoint->getDataPoint()->getAxisX(), 2) +
				pow(mousePosition.y - currentPoint->getDataPoint()->getAxisY(), 2));
			if (distance < distanceOfMause) {
				routeList.removeRouteOfTheList(currentNode->getDataRoute());
				return;
			}
			currentPoint = currentPoint->getPreviousNodePoint();
		}
		currentNode = currentNode->getNextNodeRoute();
	}
}