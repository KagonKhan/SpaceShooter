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
	initHitbox();
	initVariables();
}


void Entity::initSprite(std::string filename, std::string filepath, sf::Vector2f position) {
	entitySprite.setTexture(AssetManager::GetTexture(filename, filepath));
	//center the origin
	entitySprite.setOrigin(sf::Vector2f(entitySprite.getGlobalBounds().width, entitySprite.getGlobalBounds().height) / 2.f);

	entitySprite.setPosition(position);
}

void Entity::initHitbox() {
	//set hitbox to 50% size
	hitbox.setSize(sf::Vector2f(entitySprite.getGlobalBounds().width, entitySprite.getGlobalBounds().height) * 0.5f);
	hitbox.setOrigin(hitbox.getSize() / 2.f);
	hitbox.setPosition(entitySprite.getPosition() + hitbox.getSize() / 2.f);

	//hitbox.setFillColor(sf::Color::Red);
}

void Entity::initVariables() {
	attackTime = 0.f;
}

bool Entity::checkHit(sf::FloatRect boundaries) {
	if (hitbox.getGlobalBounds().intersects(boundaries))
		return true;
	return false;
}

bool Entity::checkHit(const Projectile& projectile) {
	if (hitbox.getGlobalBounds().intersects(projectile.getBounds())) {
		hp -= projectile.getDamage();
		return true;
	}
	return false;
}


