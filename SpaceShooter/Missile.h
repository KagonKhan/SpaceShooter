#pragma once
#include "Entity.h"
class Missile {

	sf::Sprite missileSprite;

	sf::RectangleShape missile;


	float PerpendicularDotProduct(const sf::Vector2f A, const sf::Vector2f B);
	float DotProduct(const sf::Vector2f A, const sf::Vector2f B);


	void updateMissileMovement(const float& dt);
	void updateMissileRotation(const float& dt);

	Entity* target;
	

	sf::Vector2f missileVelocity, targetPosition;
	float angularVelocity;

public:
	Missile(sf::Vector2f targetPosition, sf::Vector2f position, float initialRotation);
	~Missile();

	void setTargetPosition(sf::Vector2f targetPosition);

	void update(const float& dt);
	void render(sf::RenderWindow* window);
};

