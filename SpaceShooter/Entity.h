#pragma once
#include "SFML/Graphics.hpp"
class Entity {
protected:

	sf::Texture entityTexture;
	sf::Sprite entitySprite;

	float movementSpeed, attackSpeed, attackTime, projectileSpeed, hp, maxHp;
	sf::Vector2f movement, boundaries;

public:
	Entity(std::string filePath, sf::Vector2f boundaries, float movementSpeed, float attackSpeed, float projectileSpeed, float maxHp);
	virtual ~Entity() {};
};
