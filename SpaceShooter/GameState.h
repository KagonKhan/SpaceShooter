#pragma once
#include "State.h"
class GameState : public State {

public:
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	~GameState() {};

	void update(const float& dt);
	void render();
};

