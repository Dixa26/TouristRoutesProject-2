#include "NodePoint.h"

NodePoint::NodePoint(Point* data) : dataPoint(data), next(nullptr), previous(nullptr) {	}

NodePoint::~NodePoint() {
	delete dataPoint;
}

NodePoint* NodePoint::getNextNodePoint() {
	return next;
}

void NodePoint::setNextNodePoint(NodePoint* nextNode) {
	next = nextNode;
}

NodePoint* NodePoint::getPreviousNodePoint() {
	return previous;
}

void NodePoint::setPreviousNodePoint(NodePoint* previousNode) {
	previous = previousNode;
}

Point* NodePoint::getDataPoint() {
	return dataPoint;
}

void NodePoint::setDataPoint(Point* data) {
	dataPoint = data;
}