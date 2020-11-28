#pragma once
#include <iostream>
#include <vector>

#include "Projectile.h"
#include "SFML/Graphics.hpp"

class Player {
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	float movementSpeed, attackSpeed, attackTime, projectileSpeed;
	sf::Vector2f movement;

	std::vector<Projectile*> playerProjectiles;

	sf::Vector2u boundaries;

	void updateAttack(const float& dt);
	void updateMovement(const float& dt);
	void updateProjectiles(const float& dt);



public:
	Player(std::string filePath, sf::Vector2u boundaries);
	~Player() {};

	void update(const float& dt);
	void render(sf::RenderWindow* window);
	
	
	
	friend std::ostream& operator<<(std::ostream& outstream, const sf::Vector2f& vector);
};

