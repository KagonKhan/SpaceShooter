#pragma once
#include "State.h"
#include "Player.h"
#include "Enemy.h"
class GameState : public State {


	//USE SPRITESHEETS ZZZ
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite, backgroundSpriteV2;
	sf::Texture nebulaeTextures[3];
	sf::Sprite nebulaeSprites[3];


	std::vector<Enemy*> enemies;
	Player* player;

	void initBackground();
	void initPlayer();
	void initEnemies();

	void spawnNebulis();
	int nebulisIndex;

public:
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	~GameState() {};

	void update(const float& dt);
	void render();
};

