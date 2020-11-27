#pragma once
#include "State.h"
#include <iostream>
class GameState : public State {
	sf::Texture backgroundTextures[6];
	sf::Sprite backgroundSprites[6];

	float backgroundTime;
	int bgIndex;


	void initBackground();

	void updateBackground(const float& dt);

public:
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	~GameState() {};

	void update(const float& dt);
	void render();
};

