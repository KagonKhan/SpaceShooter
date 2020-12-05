#include "Game.h"

Game::Game() {
	initWindow();
	initStates();
}

Game::~Game() {
	std::cout << "\nDELETING GAME\n";
	std::cout << "\nstack empty?: " << states.empty();

	while (!states.empty()) {

		std::cout << "- deleting state\n";
			delete states.top();
			states.pop();
		
	}

	std::cout << "- renderwindow\n";
	window->~RenderWindow();
	std::cout << "- deleting window\n";
	delete window;
}

void Game::initWindow() {
	sf::ContextSettings settings;

	settings.antialiasingLevel = 16;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.majorVersion = 4;
	settings.minorVersion = 6;


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
