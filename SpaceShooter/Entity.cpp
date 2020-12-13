#include "pch.h"


#include "Entity.h"


// this is so ugly ...
Entity::Entity(std::string fileName, std::string filePath, sf::Vector2f boundaries,
				float movementSpeed, float attackSpeed, float projectileSpeed, 
				float maxHp, sf::Vector2f position)	:
		boundaries(boundaries), movementSpeed(movementSpeed), 
		attackSpeed(attackSpeed), projectileSpeed(projectileSpeed), 
		hp(maxHp), maxHp(maxHp), attackTime(0.f) {


	initSprite(fileName, filePath, position);
	initVariables();
}


void Entity::initSprite(std::string filename, std::string filepath, sf::Vector2f position) {
	entitySprite.setTexture(AssetManager::GetTexture(filename, filepath));
	//center the origin
	entitySprite.setOrigin(sf::Vector2f(entitySprite.getGlobalBounds().width, entitySprite.getGlobalBounds().height) / 2.f);

	entitySprite.setPosition(position);
}


void Entity::initVariables() {
	attackTime = 0.f;
}

void Entity::getDamage(float damage) { 
	std::cout << damage << std::endl;
	hp -= damage;
}

void Entity::setPosition(sf::Vector2f position) {
	entitySprite.setPosition(position);
}

const sf::Sprite& Entity::getSprite() const {
	return entitySprite;
}

const float Entity::getHp() const {
	return hp;
}

void Entity::receiveDamage(float amount) {
	hp -= amount;
	//std::cout << amount << std::endl;
}


