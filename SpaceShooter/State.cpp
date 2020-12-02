#include "State.h"

void State::updateMousePosition() {
	mousePosition = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
}

void State::updateSFMLEvents() {
	while (window->pollEvent(sfEvent))
		switch (sfEvent.type) {

		case sf::Keyboard::Escape:
			delete states->top();

		case sf::Event::KeyPressed: {
			if(sf::Keyboard::Escape)
			window->close();
		}
	}
	
}

State::State(sf::RenderWindow* window, std::stack<State*>* states) {
	this->window = window;
	this->states = states;
}

State::~State() {
	states->pop();
}
