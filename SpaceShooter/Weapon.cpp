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
}

void Weapon::initWeaponType(int type) {
	type % 3 + 1;
	weaponType = type;
}


void Weapon::update(const float& dt) {

}

void Weapon::render(sf::RenderWindow* window) {
	window->draw(weaponSprite);

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

Ammunition* Weapon::shoot() {
	switch (weaponType) {
	case 1:
		return launchProjectile();
		break;
	case 2:
		return launchMissile();
		break;	
	case 3:
		return launchBeam();
		break;
	
	}
}




Missile* Weapon::launchMissile() {
	return nullptr;
}

Bullet* Weapon::launchProjectile() {
	return nullptr;
}

Beam* Weapon::launchBeam() {
	return nullptr;
}
