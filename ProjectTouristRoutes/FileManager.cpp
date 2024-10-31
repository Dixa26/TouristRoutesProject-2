#include "FileManager.h"

FileManager::FileManager(){

}

void FileManager::saveRoute(std::string nameOfFile, RouteList& routeList){
	std::ofstream file("resources/File/" + nameOfFile + ".txt");
	if (!file.is_open()) {
		throw("The file cannot open");
	}
	NodeRoute* currentRoute = routeList.getTail();
	while (currentRoute != nullptr) {
		NodePoint* currentPoint = currentRoute->getDataRoute()->getTail();
		file << "Route\n";
		while (currentPoint != nullptr) {
			file << currentPoint->getDataPoint()->getAxisX() << "-" << currentPoint->getDataPoint()->getAxisY() << "\n";
			currentPoint = currentPoint->getPreviousNodePoint();
		}
		currentRoute = currentRoute->getPreviousNodeRoute();
	}
	file.close();
}

void FileManager::loadRoute(std::string nameOfFile, RouteList& routeList){
	std::ifstream file("resources/File/" + nameOfFile + ".txt");
	std::string line;
	bool routeStarted = false;
	Route* currentRoute = nullptr;
	if (!file.is_open()) {
		throw("The file cannot open");
	}
	while (getline(file, line)) {
		if (line == "Route") {
			routeStarted = true;
			currentRoute = new Route();
			routeList.addRouteInTheList(currentRoute);
			continue;
		}
		std::stringstream ss(line);
		std::string segment;
		int positionX;
		int positionY;
		getline(ss, segment, '-');
		positionX = stoi(segment);
		getline(ss, segment);
		positionY = stoi(segment);
		if (routeStarted) {
			currentRoute->addPoint(new Point(positionX, positionY));
		}
	}
	file.close();
}
