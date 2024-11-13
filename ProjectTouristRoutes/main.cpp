#include <iostream>
#include "Map.h"

int main(){
	Map* map = new Map();
	map->showWindow();
	delete map;

    return 0;
}