#include "Enemy.h"

Enemy::Enemy(std::string fileName, std::string filePath, float maxhp, sf::Vector2f windowBoundaries) :
	Entity(fileName, filePath, windowBoundaries, 75.f, 50.f, 550.f, 100.f) {

}

void Enemy::updateAttack(const float& dt) {
	srand(time(NULL));
	attackTime += attackSpeed * dt;
	if (attackTime >= 1 ) {
		sf::Vector2f size(10.f, 50.f);
		sf::Vector2f position(entitySprite.getPosition().x + entitySprite.getGlobalBounds().width / 2.f - size.x / 2.f,
			entitySprite.getPosition().y);

		enemyProjectile.push_back(new Projectile(size, position, sf::Color::Magenta, 2.f, sf::Color::Yellow, 200.f));
		enemyProjectile.back()->setDirection(180.f);


		attackTime = 0.f;
	}
}

void Enemy::updateMovement(const float& dt) {

}

void Enemy::updateProjectiles(const float& dt) {
	for (unsigned i = 0; i < enemyProjectile.size(); i++) {
		enemyProjectile[i]->update(dt);


		//CLEANING UP PROJECTILES
		if (enemyProjectile[i]->getPosition().y + enemyProjectile[i]->getSize().y > boundaries.y) {
			delete enemyProjectile[i];

			//CHECK IF NECESSARY i--
			enemyProjectile.erase(enemyProjectile.begin() + i--);
		}
	}
}


void Enemy::update(const float& dt) {
//	updateAttack(dt);
	updateMovement(dt);
	updateProjectiles(dt);
}

void Enemy::render(sf::RenderWindow* window) {
	for (auto x : enemyProjectile)
		x->render(window);

	window->draw(entitySprite);
}

void Enemy::setPosition(sf::Vector2f position) {
	entitySprite.setPosition(position);
}

void Enemy::shoot(const float& dt) {

	attackTime += attackSpeed * dt;
	if (attackTime >= 11.f) {

		sf::Vector2f size(10.f, 50.f);
		sf::Vector2f position(entitySprite.getPosition().x + entitySprite.getGlobalBounds().width / 2.f - size.x / 2.f,
			entitySprite.getPosition().y);

		enemyProjectile.push_back(new Projectile(size, position, sf::Color::Magenta, 2.f, sf::Color::Yellow, 200.f));
		enemyProjectile.back()->setDirection(180);


		attackTime = 0.f;
	}
}
