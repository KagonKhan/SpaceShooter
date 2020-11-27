#include "Game.h"

void Game::initWindow() {
	window = new sf::RenderWindow(sf::VideoMode(1920, 1024), "Space Shooter");
	window->setFramerateLimit(120);
	window->setMouseCursorGrabbed(false);
	window->setVerticalSyncEnabled(true);
}

void Game::update() {

}

void Game::render() {
	window->clear();


	window->display();
}

Game::Game() {
	initWindow();
}

Game::~Game() {
	window->~RenderWindow();
	delete window;
}

void Game::run() {
	while (window->isOpen()) {
		update();
		render();
	}
}
