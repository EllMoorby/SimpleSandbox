#pragma once
#include "grid.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Application
{
private:
	unsigned int screenHeight;
	unsigned int screenWidth;
	unsigned int fps;

	sf::RenderWindow window;
	sf::Event event;

	Grid grid;
public:
	Application(unsigned int screenHeight,unsigned int screenWidth,unsigned int fps);
	void start(); //Starts the program
	void createWindow();
	void update(); //Runs every frame
	void destroyWindow();
	void drawGrid();
};

