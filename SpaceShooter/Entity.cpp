#include "Entity.h"



Entity::Entity(std::string fileName, std::string filePath, sf::Vector2f boundaries, float movementSpeed, float attackSpeed, float projectileSpeed, float maxHp, sf::Vector2f position)
	:	boundaries(boundaries), movementSpeed(movementSpeed), 
		attackSpeed(attackSpeed), projectileSpeed(projectileSpeed), 
		hp(maxHp), maxHp(maxHp), attackTime(0.f) {

	
	entitySprite.setTexture(AssetManager::GetTexture(fileName, filePath));

	//center the origin
	//entitySprite.setOrigin((sf::Vector2f)AssetManager::GetTexture(fileName, filePath).getSize() / 2.f);

	//set hitbox to 75% size
	hitbox.setSize((sf::Vector2f)AssetManager::GetTexture(fileName, filePath).getSize() * 0.5f);

	hitbox.setFillColor(sf::Color::Red);

	entitySprite.setPosition(position);
	hitbox.setPosition(entitySprite.getPosition() + hitbox.getSize()/2.f);


	attackTime = 0.f;

}


bool Entity::checkHit(sf::FloatRect boundaries) {
	if (hitbox.getGlobalBounds().intersects(boundaries))
		return true;
	return false;
}


