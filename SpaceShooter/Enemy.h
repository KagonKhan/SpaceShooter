#pragma once
#include "Entity.h"

class Enemy : public Entity {



	void updateAttack(const float& dt);
	void updateMovement(const float& dt);
	void updateProjectiles(const float& dt);

	std::vector<Projectile*> projectiles;


public:
	Enemy(std::string fileName, std::string filePath, float maxhp, sf::Vector2f windowBoundaries, sf::Vector2f position);
	~Enemy();

	void update(const float& dt);
	void render(sf::RenderWindow* window);

	std::vector<Projectile*>* getProjectiles();

	bool areThereProjectilesOnScreen();

	const sf::Sprite& getEnemySprite() const;

	const sf::Sprite& getSprite() const;
	void receiveDamage(int amount);

	float getHP() const;

};

