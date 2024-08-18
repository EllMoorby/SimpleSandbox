#pragma once
#include <iostream>
#include <vector>
class Grid
{
private:
	unsigned int pixelWidth;
	unsigned int rows;
	unsigned int columns;
	std::vector<bool> grid;
public:
	void generateGrid(unsigned int screenHeight, unsigned int screenWidth, unsigned int pixelWidth);
	void toggleTile(unsigned int x, unsigned int y);
	unsigned int getRowCount();
	unsigned int getColumnCount();
	unsigned int getPixelWidth();
	std::vector<bool> getGrid();
	void drawGrid();
};

