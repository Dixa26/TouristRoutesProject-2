#pragma once
#include "Point.h"

class NodePoint{
private:
	NodePoint* next;
	NodePoint* previous;
	Point* dataPoint = nullptr;

public:
	NodePoint(Point* data);
	~NodePoint();
	NodePoint* getNextNodePoint();
	void setNextNodePoint(NodePoint* nextNode);
	NodePoint* getPreviousNodePoint();
	void setPreviousNodePoint(NodePoint* previousNode);
	Point* getDataPoint();
	void setDataPoint(Point* data);
};

