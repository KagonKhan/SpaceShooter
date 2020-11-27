#include "State.h"

void State::updateMousePosition() {
	mousePosition = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
}

void State::updateSFMLEvents() {
	while (window->pollEvent(sfEvent)) {
		if (sfEvent.type == sf::Event::Closed)
			window->close();
	}
}

State::State(sf::RenderWindow* window, std::stack<State*>* states) {
	this->window = window;
	this->states = states;
}
