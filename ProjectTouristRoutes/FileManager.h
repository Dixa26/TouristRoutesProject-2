#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include "RouteList.h"
class FileManager {
private:

public:
	FileManager();
	void saveRoute(string nameOfFile, RouteList& routeList);
	void loadRoute(string nameOfFile, RouteList& routeList);
	
};
