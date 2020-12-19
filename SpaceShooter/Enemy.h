#pragma once
#include "Entity.h"

class Enemy : public Entity {



protected:
	void initSprites();


	virtual void updateAttack(const float& dt);
	virtual void updateMovement(const float& dt);
	virtual void updateProjectiles(const float& dt);

	std::vector<Projectile*> projectiles;


public:

	Enemy(std::string fileName, std::string filePath, float maxhp, sf::Vector2f windowBoundaries, sf::Vector2f position);
	virtual ~Enemy();

	void update(const float& dt);
	void render(sf::RenderWindow* window);

	std::vector<Projectile*>* getProjectiles();

	bool areThereProjectilesOnScreen();

};

