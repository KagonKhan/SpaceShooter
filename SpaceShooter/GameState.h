#pragma once
#include "State.h"
#include "Player.h"
#include "Enemy.h"
#include "BossEnemy.h"
#include "PowerUp.h"


class GameState : public State {

	// View test
	sf::View view;

	float timer;
	int nebulisIndex;


	//USE SPRITESHEETS ZZZ
	sf::Sprite backgroundSprite, backgroundSpriteV2;
	sf::Sprite nebulaeSprites[3];



	std::vector<Enemy*> enemies, enemiesForDeletion;
	std::vector<PowerUp*> powerUps;
	Player* player;



	void initBackground();
	void initPlayer();
	void initEnemies();
	void initPowerUps();



	void update(const float& dt);
	void updateBackground();
	void updatePlayer(const float& dt);
	void updateEnemies(const float& dt);
	void updateEnemiesForDeletion(const float& dt);
	void updatePowerUps(const float& dt);
	void updateLogic(const float& dt);



	void render();
	void renderBackgrounds();
	void renderPlayer();
	void renderEnemies();
	void renderPowerUps();



	void spawnNebulis();
	void checkCollisions();
	void checkPlayerCollisions();
	void checkEnemyCollisions();
	void checkPowerUpsCollisions();
	void checkProjectileCollisions();
	void spawnNewEnemies();


public:
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	~GameState();

};

