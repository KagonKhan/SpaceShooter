#pragma once

#include "Animator.h"


class Projectile {

	sf::Sprite projectileSprite;

	float projectileRotation, projectileSpeed, projectileDamage;
	int projectileDirection;


	sf::SoundBuffer bufer;
	sf::Sound sound;

	Animator* animator;


	int projectileType;




	void initVariables();
	void initSprites(sf::Vector2f position);
	void initSounds();
	void initAnimations();


	void updateMovement(const float& dt);
	void updateAnimation(const float& dt);

public:

	Projectile(sf::Vector2f position, float speed = 200.f, int directionY = -1, int type = 0);

	const sf::Vector2f getSize() const ;
	const sf::Vector2f getPosition() const ;
	const sf::FloatRect getBounds() const ;
	const float getDamage() const ;
	const sf::Sprite& getSprite() const;


	void setRotation(float rotation);


	void render(sf::RenderWindow* window);
	void update(const float& dt);

	~Projectile() {};
};

