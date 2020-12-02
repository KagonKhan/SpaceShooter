#include "Game.h"
#include <exception>
Game::Game() {
	initWindow();
	initStates();
}

Game::~Game() {
	while (!states.empty())
		delete states.top();

	window->~RenderWindow();
	delete window;
}

void Game::initWindow() {
	sf::ContextSettings settings;

	settings.antialiasingLevel = 10; // ????????????????????????????????????????????????????????????????????????????????????????????????

	window = new sf::RenderWindow(sf::VideoMode(1920, 1024), "Space Shooter",7U, settings);
	window->setFramerateLimit(75);
}

void Game::initStates() {
	states.push(new GameState(window, &states));
}

void Game::update() {
	updateDeltaTime();


	if (!states.empty())
		states.top()->update(dt);
	else {
		try {
			throw std::runtime_error("State stack empty!\n");
		}
		catch (std::runtime_error& e) {
			std::cout << e.what();

			window->close();
		}
	}

}

void Game::updateDeltaTime() {
	dt = deltaTimeClock.restart().asSeconds();
}
 
void Game::render() {
	window->clear();

	if (!states.empty())
		states.top()->render();
	else {
		try {
			throw std::runtime_error("State stack empty!\n");
		}
		catch (std::runtime_error& e) {
			std::cout << e.what();
			
			window->close();
		}
	}
	window->display();
}


void Game::run() {
	while (window->isOpen()) {
		update();
		render();
	}
}
