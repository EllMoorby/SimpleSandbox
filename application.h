#pragma once
#include "grid.h"

class Application
{
private:
	unsigned int screenHeight;
	unsigned int screenWidth;
	unsigned int fps;
	unsigned int pixelWidth;

	sf::RenderWindow window;
	sf::Event event;
	sf::Texture texture;
	sf::Sprite sprite;

	Grid grid;
public:
	Application(unsigned int screenHeight,unsigned int screenWidth,unsigned int fps, unsigned int pixelWidth);
	void start(); //Starts the program
	void createWindow();
	void update(); //Runs every frame
	void destroyWindow();
	void drawGrid();
	sf::Vector2i findVectorFromOnScreenPosition();
};

