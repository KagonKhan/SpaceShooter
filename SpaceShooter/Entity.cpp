#include "Entity.h"
#include "AssetManager.h"


Entity::Entity(std::string fileName, std::string filePath, sf::Vector2f boundaries, float movementSpeed, float attackSpeed, float projectileSpeed, float maxHp)
	:	boundaries(boundaries), movementSpeed(movementSpeed), 
		attackSpeed(attackSpeed), projectileSpeed(projectileSpeed), 
		hp(maxHp), maxHp(maxHp), attackTime(0.f) {

	
	entitySprite.setTexture(AssetManager::GetTexture(fileName, filePath));

	attackTime = 0.f;

}
