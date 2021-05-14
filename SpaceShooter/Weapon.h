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
	
	float attackSpeed, attackTime;

	void initSprite(std::string filename, std::string filepath, sf::Vector2f position);
	void initWeaponType(int type);


	void updateBulletTurret(const float& dt);
	void updateMissileTurret(const float& dt);
	void updateBeamTurret(const float& dt);



	Bullet* launchBullet();
	Missile* launchMissile();
	Beam* launchBeam();



public:
	//Type - Projectiles = 1, Missile = 2, Laser = 3
	Weapon() {};
	Weapon(std::string filename, std::string filepath, int type, sf::Vector2f position, int shootingDirection);
	~Weapon();


	const sf::Sprite& getSprite() const ;
	const sf::Vector2f& getWeaponPosition() const;




	void update(const float& dt);
	void render(sf::RenderWindow* window);

	bool isWeaponReadyToShoot();

	void lockOnTarget(Entity* target);

	void lockOnTargetPosition(sf::Vector2f position);

	void lockOff();

	void setPosition(sf::Vector2f position);

	void scaleSprite(float scaleX, float scaleY) { this->weaponSprite.setScale(scaleX, scaleY); }

	Ammunition* shoot();
};

