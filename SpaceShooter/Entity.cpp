#include "pch.h"
#include "Entity.h"


// this is so ugly ...
Entity::Entity(std::string fileName, std::string filePath, sf::Vector2f boundaries,
				float movementSpeed, float attackSpeed, 
				float maxHp, sf::Vector2f position)	:

		boundaries(boundaries), movementSpeed(movementSpeed), 
		hp(maxHp), maxHp(maxHp)

{

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
}


void Entity::setPosition(sf::Vector2f position) {
	entitySprite.setPosition(position);
}


const sf::Sprite& Entity::getSprite() const {
	return entitySprite;
}

const float& Entity::getHp() const {
	return hp;
}

const sf::Vector2f& Entity::getPosition() const {
	return entitySprite.getPosition();
}



void Entity::receiveDamage(float amount) {
	hp -= amount;
}


