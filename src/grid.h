#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
class Grid
{
private:
	unsigned int pixelWidth;
	unsigned int rows;
	unsigned int columns;
	std::vector<bool> grid;
	sf::Image image;
public:
	void start(unsigned int screenHeight, unsigned int screenWidth, unsigned int pixelWidth);
	std::vector<bool> createEmptyGrid();
	void toggleTile(sf::Vector2i vector);
	unsigned int getRowCount();
	unsigned int getColumnCount();
	unsigned int getPixelWidth();
	void createRenderGrid();
	void updateRenderGrid();
	void generateNextGrid();
	sf::Image getRenderImage();
	sf::Vector2i indexToCoords(int index);
	int CoordsToIndex(sf::Vector2i vector);
	int indexBelow(int index);
	int getColumnOfIndex(int index);
	int getRowOfIndex(int index);
};

