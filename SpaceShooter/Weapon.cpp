#include "pch.h"
#include "Weapon.h"


Weapon::Weapon(std::string filename, std::string filepath, std::string type, sf::Vector2f position, int shootingDirection) {
	weaponSprite.setTexture(AssetManager::GetTexture(filename, filepath));
	weaponSprite.setOrigin(weaponSprite.getGlobalBounds().width / 2.f, weaponSprite.getGlobalBounds().height / 2.f);
	weaponSprite.setPosition(position);


	//missile
	weaponType = 1;
}

Weapon::~Weapon() {
}

void Weapon::update(const float& dt) {

}

void Weapon::render(sf::RenderWindow* window) {
	window->draw(weaponSprite);

}

void Weapon::lockOnTarget(Entity* target) {
	this->target = target;
}

void Weapon::lockOff() {
	target = nullptr;
}




















void Weapon::updateMissile(const float& dt) {
}
