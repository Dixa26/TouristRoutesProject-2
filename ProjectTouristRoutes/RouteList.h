#pragma once
#include "NodeRoute.h"

class RouteList{
private:
	NodeRoute* head;
	NodeRoute* tail;

public:
	RouteList();
	~RouteList();
	NodeRoute* getTail();
	NodeRoute* getHead();
	void addRouteInTheList(Route* route);
	void removeFirst(NodeRoute* current);
	void removeLast(NodeRoute* current);
	void removeRouteOfTheList(Route* route);
};

