#pragma once
#include "Entity.h"
#include "Animator.h"
#include "Weapon.h"

class Player : public Entity {

	//Would be nice  to find an alternative
	sf::Sprite engineSprite, engineSprite2;

	Animator* animator;

	float velocity;


	bool blockAttack, blockMovement, beamStartCooldown;
	float beamCooldownTimer;


	//Figure out a better solution
	std::vector<Ammunition*> bullets, missiles;
	Beam* beam;

	std::vector<Weapon> bulletWeapons, missileWeapons;
	Weapon beamWeapon;


	// I don't like this - find better solutions later
	int projectileType;

	void initVariables();
	void initSprites();
	void initAnimation();
	void initListener();
	void initWeapons();



	void updateAttack(const float& dt);
	void updateWeapons(const float& dt);
	void updateMovement(const float& dt);
	void updateAmmunition(const float& dt);
	void updateAnimations(const float& dt);
	void updateSprites(const float& dt);

	void renderPlayer(sf::RenderWindow* window);
	void renderPlayerAttacks(sf::RenderWindow* window);


public:
	Player(std::string fileName, std::string filePath, sf::Vector2f windowBoundaries, sf::Vector2f position);
	~Player();

	void update(const float& dt);	
	void render(sf::RenderWindow* window);
	

};

