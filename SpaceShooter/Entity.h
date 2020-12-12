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

	void getDamage(float damage);
	void setPosition(sf::Vector2f position);

	const sf::Sprite& getSprite() const;


	const float getHp() const ;
	void receiveDamage(float amount);

	Entity(std::string fileName, std::string filePath, sf::Vector2f boundaries, float movementSpeed, float attackSpeed, float projectileSpeed, float maxHp, sf::Vector2f position);
	virtual ~Entity() {};
};

