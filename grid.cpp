#include "grid.h"
void Grid::generateGrid(unsigned int screenHeight, unsigned int screenWidth, unsigned int pixelWidth) {
	this->pixelWidth = pixelWidth;
	this->columns = screenWidth / pixelWidth;
	this->rows = screenHeight / pixelWidth;
	const int tileCount = rows * columns;
	grid.resize(tileCount,false);
}

void Grid::toggleTile(unsigned int x, unsigned int y) {
	if ((y * columns + x) >= grid.size()){return;}
	//If it is false set it to true otherwise set it to false
	grid[y * columns + x] = grid[y * columns + x] ? false : true;
}

unsigned int Grid::getRowCount() {
	return rows;
}
unsigned int Grid::getColumnCount() {
	return columns;
}
unsigned int Grid::getPixelWidth() {
	return pixelWidth;
}

void Grid::drawGrid() {
	// Maybe have some reference to a shared pointer struct in application called gamedata
	//https://github.com/SonarSystems/Flappy-Bird-SFML-Clone/blob/03b5c04de9b96531683115d61ec90df78d40d8e6/Code/GAME%20OVER/25%20-%20Setup/Game.hpp#L12
}