#pragma once
#include "RouteList.h"
#include "GraphicPoint.h"
#include "Button.h"
using namespace sf;

class Map {
private:
	RenderWindow* windowOfMap;
	Event* eventOfWidow;

	Texture* mapTexture;
	Sprite* mapSprite;
	float broadOfMap = 1024.0f;
	float altureOfMap = 768.0f;

	GraphicPoint graphicPoint;
	RouteList routeList;
	Route* route;
	Button button;

public:
	Map();
	~Map();
	void createDesignOfMap();
	void manipulateWindow();
	void sendCoordinate();
	void checkAddCordinate();
	void checkRemoveRoute();
	void setOption();
	void draw();
	void showWindow();
};

