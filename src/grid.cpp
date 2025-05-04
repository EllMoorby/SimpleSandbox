#include "grid.h"
void Grid::start(unsigned int screenHeight, unsigned int screenWidth, unsigned int pixelWidth) {
	this->pixelWidth = pixelWidth;
	this->columns = screenWidth / pixelWidth;
	this->rows = screenHeight / pixelWidth;
	grid = createEmptyGrid();
	createRenderGrid();
}

std::vector<bool> Grid::createEmptyGrid() {
	std::vector<bool> gridToReturn;
	const int tileCount = rows * columns;
	gridToReturn.resize(tileCount, false);
	return gridToReturn;
}

void Grid::toggleTile(sf::Vector2i vector) {
	unsigned int index = vector.y * columns + vector.x;
	if ((index) >= grid.size()){return;}
	//If it is true set it to false otherwise set it to true
	grid[index] = grid[index] ? false : true;
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

void Grid::createRenderGrid() {
	image.create(columns, rows);
}

void Grid::updateRenderGrid() {
	generateNextGrid();
	int index = 0;
	for (bool tile : grid) {
		sf::Color color = tile ? sf::Color::White : sf::Color::Black;
		image.setPixel(indexToCoords(index).x, indexToCoords(index).y, color);
		index++;
	}
}

sf::Image Grid::getRenderImage() {
	return image;
}

void Grid::generateNextGrid() {
	int index = 0;
	std::vector<bool> newGrid = createEmptyGrid();
	for (bool tile : grid) {
		int below = indexBelow(index);
		int belowR = indexBelow(index + 1);
		int belowL = indexBelow(index - 1);
		if (getRowOfIndex(index + 1) != getRowOfIndex(index)) {
			belowR = indexBelow(index);
		}
		if (getRowOfIndex(index - 1) != getRowOfIndex(index)) {
			belowL = indexBelow(index);
		}
		
		if (tile == true) {
			if (index > ((rows - 1) * columns) - 1) {
				newGrid[index] = true;
			}
			else if (grid[below] != true && newGrid[below] != true) {
				newGrid[below] = true;
			}
			else{
				if (grid[belowR] != true && newGrid[belowR] != true) {
					newGrid[belowR] = true;
				}
				else if (grid[belowL] != true && newGrid[belowL] != true) {
					newGrid[belowL] = true;
				}
				else {
					newGrid[index] = true;
				}

			}
		}
		
		index++;
	}
	grid = newGrid;
}

sf::Vector2i Grid::indexToCoords(int index) {
	return sf::Vector2i(index % columns, div(index, rows).quot);
}

int Grid::CoordsToIndex(sf::Vector2i vector) {
	return vector.y * columns + vector.x;
}

int Grid::getRowOfIndex(int index) {
	return div(index, rows).quot;
}

int Grid::indexBelow(int index) {
	int belowIndex = index + columns;
	if (belowIndex > grid.size()-1) {
		return index;
	}
	else {
		return belowIndex;
	}
}