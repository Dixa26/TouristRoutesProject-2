#include "RouteList.h"


RouteList::RouteList() :head(nullptr), tail(nullptr) {}

RouteList::~RouteList() {
	NodeRoute* current = head;
	while (current != nullptr) {
		NodeRoute* temporal = current->getPreviousNodeRoute();
		delete current->getDataRoute();
		delete current;
		current = temporal;
	}
	head = nullptr;
	tail = nullptr;
}

NodeRoute* RouteList::getTail() {
	return tail;
}

NodeRoute* RouteList::getHead() {
	return head;
}

void RouteList::addRouteInTheList(Route* route) {
	NodeRoute* newNode = new NodeRoute(route);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->setNextNodeRoute(newNode);
		newNode->setPreviousNodeRoute(tail);
		tail = newNode;
	}
}

void RouteList::removeFirst(NodeRoute* current) {
	if (current == head) {
		head = current->getNextNodeRoute();
		if (head != nullptr) {
			head->setPreviousNodeRoute(nullptr);
		}
	}
}

void RouteList::removeLast(NodeRoute* current) {
	if (current == tail) {
		tail = current->getPreviousNodeRoute();
		if (tail != nullptr) {
			tail->setNextNodeRoute(nullptr);
		}
	}
}

void RouteList::removeRouteOfTheList(Route* route) {
	NodeRoute* current = head;
	while (current != nullptr && current->getDataRoute() != route) {
		current = current->getNextNodeRoute();
	}
	if (current != nullptr) {
		removeFirst(current);
		removeLast(current);
		if (current->getPreviousNodeRoute() != nullptr) {
			current->getPreviousNodeRoute()->setNextNodeRoute(current->getNextNodeRoute());
		}
		if (current->getNextNodeRoute() != nullptr) {
			current->getNextNodeRoute()->setPreviousNodeRoute(current->getPreviousNodeRoute());
		}
		delete current;
	}
}
