#pragma once
#include "Entity.h"
#include "Missile.h"
class Weapon {

	sf::Sprite weaponSprite;
	Entity* target;
	bool isLockedOnTarget;

	int weaponType;
	

	sf::RectangleShape missile;

	void updateMissile(const float& dt);



public:
	Weapon(std::string filename, std::string filepath, std::string type, sf::Vector2f position, int shootingDirection);
	~Weapon();

	void update(const float& dt);
	void render(sf::RenderWindow* window);
	void lockOnTarget(Entity* target);
	void lockOff();

};

