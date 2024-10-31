#include "Route.h"

Route::Route() : head(nullptr), tail(nullptr) {}

Route::~Route() {
	NodePoint* current = head;
	while (current != nullptr) {
		NodePoint* temporal = current->getNextNodePoint();
		delete current;
		current = temporal;
	}
	head = nullptr;
	tail = nullptr;
}

void Route::addPoint(Point* point) {
	NodePoint* newNode = new NodePoint(point);
	if (!head) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->setNextNodePoint(newNode);
		newNode->setPreviousNodePoint(tail);
		tail = newNode;
	}
}

void Route::removeFirst(NodePoint* current) {
	if (current == head) {
		head = current->getNextNodePoint();
		if (head != nullptr) {
			head->setPreviousNodePoint(nullptr);
		}
	}
}

void Route::removeLast(NodePoint* current) {
	if (current == tail) {
		tail = current->getPreviousNodePoint();
		if (tail != nullptr) {
			tail->setNextNodePoint(nullptr);
		}
	}
}

void Route::removePoint(Point* point) {
	NodePoint* current = head;
	while (current != nullptr && current->getDataPoint() != point) {
		current = current->getNextNodePoint();
	}
	if (current != nullptr) {
		removeFirst(current);
		removeLast(current);
		if (current->getPreviousNodePoint() != nullptr) {
			current->getPreviousNodePoint()->setNextNodePoint(current->getNextNodePoint());
		}
		if (current->getNextNodePoint() != nullptr) {
			current->getNextNodePoint()->setPreviousNodePoint(current->getPreviousNodePoint());
		}
		delete current;
	}
}

NodePoint* Route::getTail() {
	return tail;
}

NodePoint* Route::getHead() {
	return head;
}