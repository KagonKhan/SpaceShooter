#pragma once
#include "Enemy.h"
class BossEnemy : public Enemy {

	sf::RectangleShape hpBar, hpBarBG;



public:
	BossEnemy(std::string fileName, std::string filePath, float maxhp, sf::Vector2f windowBoundaries, sf::Vector2f position);
	~BossEnemy();

	void update(const float& dt);
	void render(sf::RenderWindow* window);

};

