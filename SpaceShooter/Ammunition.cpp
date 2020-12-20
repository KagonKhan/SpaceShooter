#include "pch.h"
#include "Ammunition.h"



Ammunition::Ammunition(std::string spriteFilename, std::string spriteFilepath,
    std::string soundFilename, std::string soundFilepath,
    sf::Vector2f position, float speed, float damage, float rotation) {

    initVariables(speed, damage, rotation);
    initSprites(spriteFilename, spriteFilepath, position);
    initSounds(soundFilename, soundFilepath, position);

}

Ammunition::~Ammunition() {
}




void Ammunition::initVariables(float speed, float damage, float rotation) {
    ammoSpeed = speed;
    ammoDamage = damage;
    ammoRotation = rotation;


    size = sf::Vector2f(ammoSprite.getGlobalBounds().width, ammoSprite.getGlobalBounds().height);
    position = ammoSprite.getPosition();
    direction = sf::Vector2f(sinf((ammoSprite.getRotation() * 3.1415926f / 180.f)), -cosf((ammoSprite.getRotation() * 3.1415926f / 180.f)));

}

void Ammunition::initSprites(std::string filename, std::string filepath, sf::Vector2f position) {
    ammoSprite.setTexture(AssetManager::GetTexture(filename, filepath));
    ammoSprite.setPosition(position);
    ammoSprite.setOrigin(getSize() / 2.f);
}

void Ammunition::initSounds(std::string filename, std::string filepath, sf::Vector2f position) {
    ammoSound.setBuffer(AssetManager::GetSoundBuffer(filename, filepath));
}




const sf::Sprite& Ammunition::getSprite() const {
    return ammoSprite;
}

const float& Ammunition::getDamage() const {
    return ammoDamage;
}

const sf::Vector2f& Ammunition::getPosition() const {
    return position;
}

const sf::Vector2f& Ammunition::getSize() const {
    return size;
}

const sf::Vector2f& Ammunition::getDirection() const {
    return direction;
}

void Ammunition::setRotation(float rotation) {
    ammoRotation = rotation;
}
