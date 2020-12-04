#include "Enemy.h"
#include <ctime>


Enemy::Enemy(std::string fileName, std::string filePath, float maxhp, sf::Vector2f windowBoundaries, sf::Vector2f position) :
	Entity(fileName, filePath, windowBoundaries, 75.f, 1.f, 400.f, 100.f, position) {

	entitySprite.setOrigin(entitySprite.getGlobalBounds().width / 2.f, entitySprite.getGlobalBounds().height / 2.f);

}

Enemy::~Enemy() {
	for (auto& it : enemyProjectile)
		delete it;
}

void Enemy::update(const float& dt) {
	updateAttack(dt);
	updateMovement(dt);
	updateProjectiles(dt);
}

void Enemy::updateAttack(const float& dt) {
	srand(static_cast<long int>(time(NULL)));


	attackTime += attackSpeed * dt;

	//if(rand()%10 == 5)
		if (attackTime >= 1.f) {
			sf::Vector2f position(entitySprite.getPosition().x,	entitySprite.getPosition().y);

			enemyProjectile.push_back(new Projectile(position, 500.f, -90.f, 1));
			attackTime = 0.f;
		}
}

void Enemy::updateMovement(const float& dt) {

}

void Enemy::updateProjectiles(const float& dt) {
	for (unsigned i = 0; i < enemyProjectile.size(); i++) {
		enemyProjectile[i]->update(dt);


		//CLEANING UP PROJECTILES
		if (enemyProjectile[i]->getPosition().y > boundaries.y + enemyProjectile[i]->getSize().y) {
			delete enemyProjectile[i];

			//CHECK IF NECESSARY i--
			enemyProjectile.erase(enemyProjectile.begin() + i--);
		}
	}
}


void Enemy::render(sf::RenderWindow* window) {
	for (auto x : enemyProjectile)
		x->render(window);

	window->draw(entitySprite);
}

void Enemy::setPosition(sf::Vector2f position) {
	entitySprite.setPosition(position);
}






bool Enemy::checkHit(const Projectile& projectile) {
	if (hitbox.getGlobalBounds().intersects(projectile.getBounds())) {
		hp -= projectile.getDamage();
		return true;
	}
	return false;
}


float Enemy::getHP() const {
	return hp;
}