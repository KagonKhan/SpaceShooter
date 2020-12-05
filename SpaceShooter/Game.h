#pragma once
#include "GameState.h"


class Game {
	sf::RenderWindow* window;
	std::stack<State*> states;

	sf::Clock deltaTimeClock;

	AssetManager manager;

	float dt;


	void initWindow();
	void initStates();


	void update();
	void updateDeltaTime();


	void render();


public:
	Game();
	~Game();
	 
	void run();
};

