#pragma once
#include "Entity.h"
#include "Enemy.h"
class BossEnemy : public Enemy {


public:
	BossEnemy(std::string fileName, std::string filePath, float maxhp, sf::Vector2f windowBoundaries, sf::Vector2f position);
	~BossEnemy();



};

