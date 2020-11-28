#pragma once
#include <iostream>
#include <vector>

#include "Projectile.h"
#include "SFML/Graphics.hpp"
#include "Entity.h"


class Player : public Entity {


	std::vector<Projectile*> playerProjectiles;

	sf::Texture engine;
	sf::Sprite engineSPrite;


	void updateAttack(const float& dt);
	void updateMovement(const float& dt);
	void updateProjectiles(const float& dt);



public:
	Player(std::string filePath, sf::Vector2f boundaries);
	~Player() {};

	void update(const float& dt);
	void render(sf::RenderWindow* window);
	
	
	
	friend std::ostream& operator<<(std::ostream& outstream, const sf::Vector2f& vector);
};

