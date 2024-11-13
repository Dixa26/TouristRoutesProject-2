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
	VertexArray line(LineStrip);
	NodePoint* current = tail;
	while (current != nullptr) {
		Vector2f position = Vector2f(current->getDataPoint()->getAxisX(), current->getDataPoint()->getAxisY());
		Vertex point(position, Color::Black);
		line.append(point);
		current = current->getPreviousNodePoint();
	}
	window.draw(line);
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