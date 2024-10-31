#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include "RouteList.h"
class FileManager {
private:

public:
	FileManager();
	void saveRoute(std::string nameOfFile, RouteList& routeList);
	void loadRoute(std::string nameOfFile, RouteList& routeList);
};

