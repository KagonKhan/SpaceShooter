#pragma once
#include "SFML/Graphics.hpp"
#include "Projectile.h"

#include "AssetManager.h"

class Entity {
protected:

	sf::Sprite entitySprite;
	sf::RectangleShape hitbox;

	float movementSpeed, attackSpeed, attackTime, projectileSpeed, hp, maxHp;
	sf::Vector2f movement, boundaries;

public:
	bool checkHit(sf::FloatRect boundaries);

	Entity(std::string fileName, std::string filePath, sf::Vector2f boundaries, float movementSpeed, float attackSpeed, float projectileSpeed, float maxHp, sf::Vector2f position);
	virtual ~Entity() {};
};

