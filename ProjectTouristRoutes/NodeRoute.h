#pragma once
#include "Route.h"
class NodeRoute {
private:
	NodeRoute* next;
	NodeRoute* previuos;
	Route* dataRoute;
public:
	NodeRoute(Route* data);
	~NodeRoute();
	NodeRoute* getNextNodeRoute();
	void setNextNodeRoute(NodeRoute* nextNode);
	NodeRoute* getPreviousNodeRoute();
	void setPreviousNodeRoute(NodeRoute* previuosNode);
	Route* getDataRoute();
	void setDataRoute(Route* data);
};

