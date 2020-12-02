#pragma once

#include <stack>
#include "SFML/Graphics.hpp"

class State {
protected:
	std::stack<State*>* states;

	sf::RenderWindow* window;

	sf::Event sfEvent;

	sf::Vector2f mousePosition;


	void updateMousePosition();
	virtual void updateSFMLEvents();


public:
	State(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~State();

	virtual void update(const float& dt) = 0;
	virtual void render() = 0;
};

