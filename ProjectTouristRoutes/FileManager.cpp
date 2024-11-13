#include "FileManager.h"

FileManager::FileManager() {
}

void FileManager::saveRoute(string nameOfFile, RouteList& routeList) {
	ofstream file("Resources/file/" + nameOfFile + ".txt");
	if (!file.is_open()) {
		throw("The file cannot open");
	}
	NodeRoute* currentRoute = routeList.getTail();
	while (currentRoute != nullptr) {
		NodePoint* currentPoint = currentRoute->getDataRoute()->getTail();
		file << "Route" << endl;
		while (currentPoint != nullptr) {
			file << currentPoint->getDataPoint()->getAxisX() << "-" << currentPoint->getDataPoint()->getAxisY() << endl;
			currentPoint = currentPoint->getPreviousNodePoint();
		}
		currentRoute = currentRoute->getPreviousNodeRoute();
	}
	file.close();
}

void FileManager::loadRoute(string nameOfFile, RouteList& routeList) {
	ifstream file("Resources/file/" + nameOfFile + ".txt");
	string line;
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
		stringstream ss(line);
		string segment;
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