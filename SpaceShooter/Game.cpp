#include "Game.h"

Game::Game() {
	initWindow();
	initStates();
}

Game::~Game() {
	window->~RenderWindow();
	delete window;
}

void Game::initWindow() {
	window = new sf::RenderWindow(sf::VideoMode(1920, 1024), "Space Shooter");
	window->setFramerateLimit(120);
	window->setMouseCursorGrabbed(false);
	window->setVerticalSyncEnabled(true);
}

void Game::initStates() {
	states.push(new GameState(window, &states));
}

void Game::update() {
	updateDeltaTime();


	if (!states.empty())
		states.top()->update(dt);
	else
		throw std::runtime_error("State stack empty!\n");
}

void Game::updateDeltaTime() {
	dt = deltaTimeClock.restart().asSeconds();
}
 
void Game::render() {
	window->clear();

	if (!states.empty())
		states.top()->render();
	else
		throw std::runtime_error("State stack empty!\n");

	window->display();
}


void Game::run() {
	while (window->isOpen()) {
		update();
		render();
	}
}
