#pragma once

#include "Ammunition.h"


class Bullet : public Ammunition{


	int projectileDirection;


	Animator* animator;


	int projectileType;


	void initSounds();
	void initAnimations();


	void updateMovement(const float& dt);
	void updateAnimation(const float& dt);

public:

	Bullet(std::string spriteFilename, std::string spriteFilepath,
		std::string soundFilename, std::string soundFilepath,
		sf::Vector2f position, float speed, float damage, float rotation, int type);


	void render(sf::RenderWindow* window);
	void update(const float& dt);

	~Bullet() {};
};

