#include "Entity.h"

Entity::Entity(std::string filePath, sf::Vector2f boundaries, float movementSpeed, float attackSpeed, float projectileSpeed, float maxHp) 
	:	boundaries(boundaries), movementSpeed(movementSpeed), 
		attackSpeed(attackSpeed), projectileSpeed(projectileSpeed), 
		hp(maxHp), maxHp(maxHp), attackTime(0.f) {

	
	entityTexture.loadFromFile(filePath);
	entitySprite.setTexture(entityTexture);

	attackTime = 0.f;

}
