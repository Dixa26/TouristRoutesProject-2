#pragma once
#include "RouteList.h"
#include "ColorPalette.h"
#include "FileManager.h"

class GraphicPoint {
private:
	CircleShape circlePoint;
	float radius = 5.0;
	ColorPalette colorPalette;
	Color color;
	float distanceOfMause = 10.0f;
	FileManager file;

public:
	GraphicPoint();
	void drawColor(RenderWindow& window, Event eventOfColor);
	void drawPoint(RenderWindow& window, NodePoint* tail);
	void drawLineBetweenPoint(RenderWindow& window, NodePoint* tail);
	void drawPointOfTheRouteList(RenderWindow& window, NodeRoute* tail);
	void drawLineOfTheRouteList(RenderWindow& window, NodeRoute* tail);
	void drawRoute(RenderWindow& window, NodePoint* tail);
	void drawRouteList(RenderWindow& window, NodeRoute* tail);
	void removePointOfRoute(Vector2i& mousePosition, Route& route);
	void removePointOfRouteList(Vector2i& mousePosition, RouteList& routeList);
	void removeRoute(Vector2i& mousePosition, RouteList& routeList);
};
