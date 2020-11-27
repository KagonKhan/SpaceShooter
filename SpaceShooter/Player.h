#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"

class Player {
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	float movementSpeed, attackSpeed, attackTime, projectileSpeed;
	sf::Vector2f movement;





	void updateMovement(const float& dt);


public:
	Player(std::string filePath);
	~Player() {};

	void update(const float& dt);
	void render(sf::RenderWindow* window);
};

