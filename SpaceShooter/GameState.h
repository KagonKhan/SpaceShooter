#pragma once
#include "State.h"
#include "Player.h"
#include "Enemy.h"
class GameState : public State {

	// View test
	sf::View view;

	float timer;
	int nebulisIndex;


	//USE SPRITESHEETS ZZZ
	sf::Sprite backgroundSprite, backgroundSpriteV2;
	sf::Sprite nebulaeSprites[3];

	std::vector<Enemy*> enemies, enemiesForDeletion;

	Player* player;


	void initBackground();
	void initPlayer();
	void initEnemies();


	void update(const float& dt);
	void updateBackground();
	void updatePlayer(const float& dt);
	void updateEnemies(const float& dt);
	void updateLogic(const float& dt);


	void render();
	void renderBackgrounds();
	void renderPlayer();
	void renderEnemies();


	void spawnNebulis();
	void checkCollisions();
	void updateEnemiesForDeletion(const float& dt);


public:
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	~GameState();

};

