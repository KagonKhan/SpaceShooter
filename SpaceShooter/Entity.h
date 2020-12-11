#pragma once

#include "Projectile.h"
#include "Beam.h"

class Entity {
private:
	void initSprite(std::string filename, std::string filepath, sf::Vector2f position);
	void initHitbox();
	void initVariables();


protected:
	sf::Sprite entitySprite;
	sf::RectangleShape hitbox;
	sf::Vector2f movement, boundaries;

	float movementSpeed, attackSpeed, attackTime, projectileSpeed, hp, maxHp;

public:
	//Possibly obsolete
	bool checkHit(sf::FloatRect boundaries);
	bool checkHit(const Projectile& projectile);
	bool checkHit(const Beam& beam);

	void getDamage(float damage);
	void setPosition(sf::Vector2f position);


	Entity(std::string fileName, std::string filePath, sf::Vector2f boundaries, float movementSpeed, float attackSpeed, float projectileSpeed, float maxHp, sf::Vector2f position);
	virtual ~Entity() {};
};

