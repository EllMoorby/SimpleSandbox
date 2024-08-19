#include "application.h"

Application::Application(unsigned int screenHeight, unsigned int screenWidth, unsigned int fps, unsigned int pixelWidth) {
	this->screenHeight = screenHeight;
	this->screenWidth = screenWidth;
	this->fps = fps;
	this->pixelWidth = pixelWidth;
}

void Application::start() {
	grid.start(screenHeight, screenWidth, pixelWidth);
	texture.create(screenWidth, screenHeight);
	grid.updateRenderGrid();
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(pixelWidth, pixelWidth));

	createWindow();
	while (window.isOpen()) {
		update();
	}
	destroyWindow();
}

void Application::createWindow() {
	window.create(sf::VideoMode(screenWidth, screenHeight), "SimpleSandbox", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(fps);
}

void Application::update() {
	while (window.pollEvent(event))
	{
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;

		case sf::Event::MouseButtonPressed:
			switch (event.mouseButton.button) {
			case sf::Mouse::Left:
				grid.toggleTile(findVectorFromOnScreenPosition());
				break;
			}
			break;
		}
	}

	window.clear();


	grid.updateRenderGrid();
	texture.update(grid.getRenderImage());
	window.draw(sprite);


	window.display();
}

void Application::destroyWindow() {
	window.close();
}

sf::Vector2i Application::findVectorFromOnScreenPosition() {
	sf::Vector2i pos = sf::Mouse::getPosition(window);
	int x = pos.x;
	int y = pos.y;

	x /= pixelWidth;
	y /= pixelWidth;

	return sf::Vector2i(x,y);
}
