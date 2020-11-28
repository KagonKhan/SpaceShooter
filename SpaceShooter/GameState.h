#pragma once
#include "State.h"
#include "Player.h"
#include "Enemy.h"
class GameState : public State {


	//USE SPRITESHEETS ZZZ
	sf::Texture backgroundTextures[6];
	sf::Sprite backgroundSprites[6];

	float backgroundTime;
	int bgIndex;

	std::vector<Enemy*> enemies;
	Player* player;

	void initBackground();
	void initPlayer();


	void updateBackground(const float& dt);

public:
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	~GameState() {};

	void update(const float& dt);
	void render();
};

