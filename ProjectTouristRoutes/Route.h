#pragma once
#include "NodePoint.h"
class Route {
private:
	NodePoint* head;
	NodePoint* tail;

public:
	Route();
	~Route();
	void addPoint(Point* point);
	void removeFirst(NodePoint* current);
	void removeLast(NodePoint* current);
	void removePoint(Point* point);
	NodePoint* getTail();
	NodePoint* getHead();
};

