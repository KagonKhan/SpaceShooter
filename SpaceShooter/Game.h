#pragma once
#include "SFML/Graphics.hpp"
#include "GameState.h"
#include "AssetManager.h"



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

