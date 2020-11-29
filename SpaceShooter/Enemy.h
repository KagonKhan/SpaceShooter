#pragma once
#include "Projectile.h"
#include "Entity.h"

class Enemy : public Entity {


	void updateAttack(const float& dt);
	void updateMovement(const float& dt);
	void updateProjectiles(const float& dt);

	std::vector<Projectile*> enemyProjectile;


public:
	Enemy(std::string fileName, std::string filePath, float maxhp, sf::Vector2f windowBoundaries);
	~Enemy() {};

	void update(const float& dt);
	void render(sf::RenderWindow* window);
	void setPosition(sf::Vector2f position);
	void shoot(const float& dt);

};

