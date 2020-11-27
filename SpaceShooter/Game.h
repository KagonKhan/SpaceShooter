#pragma once
#include "SFML/Graphics.hpp"

class Game {
	sf::RenderWindow* window;

	void initWindow();

	void update();

	void render();


public:
	Game();
	~Game();

	void run();
};

