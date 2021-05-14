#include "pch.h"
#include "Weapon.h"
#include "Ammunition.h"

Weapon::Weapon(std::string filename, std::string filepath, int type, sf::Vector2f position, int shootingDirection) {

	initSprite(filename, filepath, position);

	initWeaponType(type);

}

Weapon::~Weapon() {

}


void Weapon::initSprite(std::string filename, std::string filepath, sf::Vector2f position) {
	weaponSprite.setTexture(AssetManager::GetTexture(filename, filepath));
	weaponSprite.setOrigin(weaponSprite.getGlobalBounds().width / 2.f, weaponSprite.getGlobalBounds().height / 2.f);
	weaponSprite.setPosition(position);
//	weaponSprite.move(sf::Vector2f(500, -200));
}

void Weapon::initWeaponType(int type) {

	weaponType = type;



	attackSpeed = 100.f;
	attackTime = 0.f;
}




const sf::Sprite& Weapon::getSprite() const {
	return weaponSprite;
}

const sf::Vector2f& Weapon::getWeaponPosition() const {
	return weaponSprite.getPosition();
}

void Weapon::update(const float& dt) {

	attackTime += attackSpeed * dt;



	switch (weaponType) {
	case 1:
		return updateBulletTurret(dt);
		break;
	case 2:
		return updateMissileTurret(dt);
		break;
	case 3:
		return updateBeamTurret(dt);
		break;
	}
}

void Weapon::updateBulletTurret(const float& dt) {

}

void Weapon::updateMissileTurret(const float& dt) {
}

void Weapon::updateBeamTurret(const float& dt) {
}




void Weapon::render(sf::RenderWindow* window) {
	window->draw(weaponSprite);

}

bool Weapon::isWeaponReadyToShoot() {
	if (attackTime > 1.f) {
		return true;
	}
	else
		return false;
}






void Weapon::lockOnTarget(Entity* target) {
	this->target = target;
}

void Weapon::lockOnTargetPosition(sf::Vector2f position) {
	targetPosition = position;
}

void Weapon::lockOff() {
	target = nullptr;
}

void Weapon::setPosition(sf::Vector2f position) {
	weaponSprite.setPosition(position);
}

Ammunition* Weapon::shoot() {
	std::cout << weaponType;
	attackTime = 0.f;
	switch (weaponType) {
	case 1:
		return launchBullet();
		break;
	case 2:
		return launchMissile();
		break;	
	case 3:

		return launchBeam();
		break;
	}
}



Bullet* Weapon::launchBullet() {
	std::cout << "Weapon Position: " << weaponSprite.getPosition().x << ", "  << weaponSprite.getPosition().y;
	return new Bullet("Laser_Bullets.png", "../Resources/art/Ammunition/Bullets/", "Laser_Bullets.wav",
		"../Resources/art/Ammunition/Bullets/", weaponSprite.getPosition(), 900, 20, 0.f, 1);
}

Missile* Weapon::launchMissile() {

	return new Missile("Laser_Bullets.png", "../Resources/art/Ammunition/Bullets/", "Laser_Bullets.wav",
		"../Resources/art/Ammunition/Bullets/", weaponSprite.getPosition(), 100, 20, 0.f);
}


Beam* Weapon::launchBeam() {
	return new Beam("Red_Laser_Beam.png", "../Resources/art/Ammunition/Beams/", "Red_Laser_Beam.wav",
		"../Resources/art/Ammunition/Beams/", weaponSprite.getPosition(), 100, 20, 0.f);
}
