#pragma once
#include <iostream>
#include <vector>

#include "Projectile.h"
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Animator.h"

class Player : public Entity {

	//Fix later
	sf::Sprite engineSprite, engineSprite2;

	Animator* animator;


	sf::RectangleShape hitbox;


	void initSprites();
	void initAnimation();
	void initListener();


	void updateAttack(const float& dt);
	void updateMovement(const float& dt);
	void updateProjectiles(const float& dt);
	void updateAnimations(const float& dt);
	void updateSprites(const float& dt);

	std::vector<Projectile*> projectiles;


public:
	Player(std::string fileName, std::string filePath, sf::Vector2f windowBoundaries, sf::Vector2f position);
	~Player();

	void update(const float& dt);
	void render(sf::RenderWindow* window);

	std::vector<Projectile*>* getProjectiles();


	
	friend std::ostream& operator<<(std::ostream& outstream, const sf::Vector2f& vector);
};

