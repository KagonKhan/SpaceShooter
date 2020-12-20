#pragma once
#include "Entity.h"
#include "Ammunition.h"

class Missile : public Ammunition {


	float PerpendicularDotProduct(const sf::Vector2f A, const sf::Vector2f B);
	float DotProduct(const sf::Vector2f A, const sf::Vector2f B);


	void updateMissileMovement(const float& dt);
	void updateMissileRotation(const float& dt);

	Entity* target;
	

	sf::Vector2f missileVelocity, targetPosition;
	float angularVelocity;

public:
	Missile(std::string spriteFilename, std::string spriteFilepath,
		std::string soundFilename, std::string soundFilepath,
		sf::Vector2f position, float speed, float damage, float rotation);

	~Missile();

	void setTargetPosition(sf::Vector2f targetPosition);
	void setTargetEntity(Entity* target);

	void update(const float& dt);
	void render(sf::RenderWindow* window);
};

