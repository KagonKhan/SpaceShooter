#include "pch.h"

#include "State.h"

State::State(sf::RenderWindow* window, std::stack<State*>* states) {
	this->window = window;
	this->states = states;
}

void State::updateMousePosition() {
	mousePosition = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
}

void State::updateSFMLEvents() {
	while (window->pollEvent(sfEvent))
		if (sfEvent.type == sf::Event::Closed) {
			window->close();
		}
	
}


State::~State() {
	std::cout << "\nDELETING STATE\n";
	std::cout << "- popping state\n";
	//states->pop();
}
