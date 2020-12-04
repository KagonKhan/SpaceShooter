#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "Animator.h"
#include "AssetManager.h"

class Projectile {

	sf::Sprite projectileSprite;

	float rotation;
	float projectileSpeed;
	float projectileDamage;


	sf::Sound sound;


	Animator* animator;

	float i = 0;
	bool rotate = false;

	sf::Vector2f position;

	void initVariables();
	void initSprites(sf::Vector2f position);
	void initSounds();
	void initAnimations();



	void updateMovement(const float& dt);









public:


	Projectile(sf::Vector2f position, float speed = 200.f, float rotation = 0.f);

	sf::Vector2f getSize() const ;
	sf::Vector2f getPosition() const ;
	sf::FloatRect getBounds() const ;
	float getDamage() const ;

	void render(sf::RenderWindow* window);
	void update(const float& dt);

	~Projectile() {};
};

