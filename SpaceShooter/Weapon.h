#pragma once
#include "Entity.h"

#include "Bullet.h"
#include "Missile.h"
#include "Beam.h"

class Weapon {

	sf::Sprite weaponSprite;
	Entity* target;

	sf::Vector2f targetPosition;

	bool isLockedOnTarget;

	int weaponType;
	

	void initSprite(std::string filename, std::string filepath, sf::Vector2f position);
	void initWeaponType(int type);


	void updateMissileTurret(const float& dt);
	void updateProjectileTurret(const float& dt);
	void updateBeamTurret(const float& dt);



	Missile* launchMissile();
	Bullet* launchProjectile();
	Beam* launchBeam();



public:
	//Type - Projectiles = 1, Missile = 2, Laser = 3
	Weapon(std::string filename, std::string filepath, int type, sf::Vector2f position, int shootingDirection);
	~Weapon();

	void update(const float& dt);
	void render(sf::RenderWindow* window);


	void lockOnTarget(Entity* target);

	void lockOnTargetPosition(sf::Vector2f position);

	void lockOff();


	Ammunition* shoot();
};

