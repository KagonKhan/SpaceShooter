#include "Enemy.h"

void Enemy::updateAttack(const float& dt) {
	attackTime += attackSpeed * dt;
	if (attackTime >= 2 + rand() % 8) {
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

Enemy::Enemy(std::string filePath, float maxhp, sf::Vector2f windowBoundaries) :
	Entity(filePath, windowBoundaries, 75.f, 500.f, 50.f, 100.f) {

	entityTexture.loadFromFile(filePath);
	entitySprite.setTexture(entityTexture);

	hp = maxHp = maxhp;

	attackSpeed = 0.5f;
	projectileSpeed = 100;
	attackTime = 0.f;
	movementSpeed = 20.f;
}

void Enemy::update(const float& dt) {
	updateAttack(dt);
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
