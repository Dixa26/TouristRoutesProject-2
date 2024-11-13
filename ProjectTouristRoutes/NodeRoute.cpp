#include "NodeRoute.h"

NodeRoute::NodeRoute(Route* data) : dataRoute(data), next(nullptr), previuos(nullptr) {

}

NodeRoute::~NodeRoute() {
	delete dataRoute;
}

NodeRoute* NodeRoute::getNextNodeRoute() {
	return next;
}

void NodeRoute::setNextNodeRoute(NodeRoute* nextNode) {
	next = nextNode;
}

NodeRoute* NodeRoute::getPreviousNodeRoute() {
	return previuos;
}

void NodeRoute::setPreviousNodeRoute(NodeRoute* previuosNode) {
	previuos = previuosNode;
}

Route* NodeRoute::getDataRoute() {
	return dataRoute;
}

void NodeRoute::setDataRoute(Route* data) {
	dataRoute = data;
}
